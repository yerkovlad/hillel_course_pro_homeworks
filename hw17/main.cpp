#include <iostream>
#include <filesystem>
#include <string>
#include <sstream>
#include <vector>
#include <thread>
#include <mutex>
#include <queue>
#include <condition_variable>

namespace fs = std::filesystem;

int txt_files = 0, imgs_files = 0, exe_files = 0, other_files = 0;
uintmax_t txt_size = 0, imgs_size = 0, exe_size = 0, other_size = 0;

std::mutex result_mutex;

class ThreadPool {
public:
    ThreadPool(size_t threads) : stop(false) {
        for (size_t i = 0; i < threads; ++i)
            workers.emplace_back([this] {
                while (true) {
                    std::function<void()> task;
                    {
                        std::unique_lock<std::mutex> lock(queue_mutex);
                        condition.wait(lock, [this] { return stop || !tasks.empty(); });
                        if (stop && tasks.empty()) return;
                        task = std::move(tasks.front());
                        tasks.pop();
                    }
                    task();
                }
            });
    }

    void enqueue(std::function<void()> task) {
        {
            std::unique_lock<std::mutex> lock(queue_mutex);
            tasks.push(std::move(task));
        }
        condition.notify_one();
    }

    ~ThreadPool() {
        {
            std::unique_lock<std::mutex> lock(queue_mutex);
            stop = true;
        }
        condition.notify_all();
        for (std::thread &worker : workers) worker.join();
    }

private:
    std::vector<std::thread> workers;
    std::queue<std::function<void()>> tasks;
    std::mutex queue_mutex;
    std::condition_variable condition;
    bool stop;
};

void process_directory(const fs::path& dir_path, std::stringstream& local_output) {
    try {
        for (const auto& entry : fs::directory_iterator(dir_path)) {
            if (fs::is_regular_file(entry)) {
                std::string filename = entry.path().filename().string();
                uintmax_t file_size = fs::file_size(entry);
                size_t np = std::string::npos;

                if (filename.find(".txt") != np) {
                    std::lock_guard<std::mutex> lock(result_mutex);
                    txt_files++;
                    txt_size += file_size;
                }
                else if (filename.find(".jpg") != np || filename.find(".png") != np || filename.find(".bmp") != np) {
                    std::lock_guard<std::mutex> lock(result_mutex);
                    imgs_files++;
                    imgs_size += file_size;
                }
                else if (filename.find(".exe") != np) {
                    std::lock_guard<std::mutex> lock(result_mutex);
                    exe_files++;
                    exe_size += file_size;
                }
                else {
                    std::lock_guard<std::mutex> lock(result_mutex);
                    other_files++;
                    other_size += file_size;
                }
            }
        }
        local_output << "Processed directory: " << dir_path << "\n";
    } catch (const fs::filesystem_error& e) {
        local_output << "Error accessing " << dir_path << ": " << e.what() << "\n";
    }
}

int main() {
    std::string dir_path_input;
    std::cout << "Enter directory path: ";
    std::getline(std::cin, dir_path_input);

    fs::path dir_path = dir_path_input;

    if (!fs::exists(dir_path) || !fs::is_directory(dir_path)) {
        std::cerr << dir_path << " is not a valid directory.\n";
        return 1;
    }

    ThreadPool pool(std::thread::hardware_concurrency());
    std::vector<std::stringstream> thread_outputs;
    std::mutex output_mutex;

    for (const auto& entry : fs::directory_iterator(dir_path)) {
        if (fs::is_directory(entry)) {
            thread_outputs.emplace_back();
            pool.enqueue([&entry, &thread_outputs, idx = thread_outputs.size() - 1]() {
                process_directory(entry.path(), thread_outputs[idx]);
            });
        }
    }

    std::stringstream final_output;

    final_output << "TXT files: " << txt_files << ", Total size: " << txt_size << " bytes\n";
    final_output << "Image files: " << imgs_files << ", Total size: " << imgs_size << " bytes\n";
    final_output << "EXE files: " << exe_files << ", Total size: " << exe_size << " bytes\n";
    final_output << "Other files: " << other_files << ", Total size: " << other_size << " bytes\n";

    for (auto& ss : thread_outputs) {
        std::cout << ss.str();
    }

    std::cout << final_output.str();
    return 0;
}

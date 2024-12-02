#include <iostream>
#include <filesystem>
#include <string>

namespace fs = std::filesystem;

int txt_files = 0;
int imgs_files = 0;
int exe_files = 0;
int other_files = 0;

uintmax_t txt_size = 0;
uintmax_t imgs_size = 0;
uintmax_t exe_size = 0;
uintmax_t other_size = 0;

int main() {
    std::string dir_path_input;
    std::cout << "Enter directory path: ";
    std::getline(std::cin, dir_path_input);

    fs::path dir_path = dir_path_input;

    try {
        if (fs::exists(dir_path) && fs::is_directory(dir_path)) {
            for (const auto& entry : fs::recursive_directory_iterator(dir_path)) {
                if (fs::is_regular_file(entry.status())) {
                    std::string filename = entry.path().filename().string();
                    size_t np = std::string::npos;

                    uintmax_t file_size = fs::file_size(entry);

                    if (filename.find(".txt") != np) {
                        txt_files++;
                        txt_size += file_size;
                    }
                    else if (filename.find(".jpg") != np || filename.find(".png") != np || filename.find(".bmp") != np) {
                        imgs_files++;
                        imgs_size += file_size;
                    }
                    else if (filename.find(".exe") != np) {
                        exe_files++;
                        exe_size += file_size;
                    }
                    else {
                        other_files++;
                        other_size += file_size;
                    }
                }
            }
        } else {
            std::cerr << dir_path << " is not a valid directory.\n";
        }
    } catch (const fs::filesystem_error& e) {
        std::cerr << "Error: " << e.what() << '\n';
    }

    std::cout << "TXT files: " << txt_files << ", Total size: " << txt_size << " bytes\n";
    std::cout << "Image files: " << imgs_files << ", Total size: " << imgs_size << " bytes\n";
    std::cout << "EXE files: " << exe_files << ", Total size: " << exe_size << " bytes\n";
    std::cout << "Other files: " << other_files << ", Total size: " << other_size << " bytes\n";

    return 0;
}

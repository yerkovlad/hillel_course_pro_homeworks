#pragma once
#include <string>
#include <fstream>
#include <chrono>
#include <format>
#include <mutex>

class Logger {
public:
    enum class Level { INFO, WARNING, ERROR };

    static Logger& getInstance() {
        static Logger instance;
        return instance;
    }

    void log(const std::string& message, Level level = Level::INFO) {
        std::ofstream logFile("log.txt", std::ios::app);
        if (logFile.is_open()) {
            logFile << getLevelString(level) << " - " << getCurrentTime() << " - " << message << std::endl;
        } else {
            std::cerr << "Error: Unable to open log file" << std::endl;
        }
    }

private:
    Logger() = default;
    ~Logger() = default;
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

    std::string getCurrentTime() const {
        auto now = std::chrono::system_clock::now();
        auto time_t_now = std::chrono::system_clock::to_time_t(now);
        return std::format("{:%Y-%m-%d %H:%M:%S}", *std::localtime(&time_t_now));
    }

    std::string getLevelString(Level level) const {
        switch (level) {
            case Level::INFO: return "[INFO]";
            case Level::WARNING: return "[WARNING]";
            case Level::ERROR: return "[ERROR]";
        }
        return "[UNKNOWN]";
    }
};

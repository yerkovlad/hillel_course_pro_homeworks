#include "Logger.h"

Logger::Logger(const std::string &filename) : logFile(filename, std::ios::app) {}

void Logger::log(const std::string &message) {
    logFile << message << std::endl;
}

Logger::~Logger() {
    if (logFile.is_open()) {
        logFile.close();
    }
}
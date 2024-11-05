#ifndef LOGGER_H
#define LOGGER_H

#include <fstream>
#include <string>

class Logger {
public:
    explicit Logger(const std::string &filename);
    void log(const std::string &message);
    ~Logger();

private:
    std::ofstream logFile;
};

#endif
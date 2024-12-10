#include <iostream>
#include "Logger.h"
#include "ConfigManager.h"

int main() {
    Logger::getInstance()->log("This is an info message");
    Logger::getInstance()->log("This is a warning", Logger::Level::WARNING);
    Logger::getInstance()->log("This is an error", Logger::Level::ERROR);

    ConfigManager::getInstance()->setConfig("username", "admin");
    std::cout << "Username: " << ConfigManager::getInstance()->getConfig("username") << std::endl;

    return 0;
}

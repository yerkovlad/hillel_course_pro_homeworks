#pragma once
#include <string>
#include <unordered_map>
#include <mutex>

class ConfigManager {
public:
    static ConfigManager* getInstance() {
        std::lock_guard<std::mutex> lock(mtx);
        if (instance == nullptr) {
            instance = new ConfigManager();
        }
        return instance;
    }

    void setConfig(const std::string& key, const std::string& value) {
        std::lock_guard<std::mutex> lock(configMutex);
        config_[key] = value;
    }

    std::string getConfig(const std::string& key) {
        std::lock_guard<std::mutex> lock(configMutex);
        if (config_.find(key) != config_.end()) {
            return config_[key];
        } else {
            return "Key not found";
        }
    }

private:
    ConfigManager() = default;
    ~ConfigManager() = default;
    ConfigManager(const ConfigManager&) = delete;
    ConfigManager& operator=(const ConfigManager&) = delete;

    std::unordered_map<std::string, std::string> config_;
    std::mutex configMutex;
    static ConfigManager* instance;
    static std::mutex mtx;
};

ConfigManager* ConfigManager::instance = nullptr;
std::mutex ConfigManager::mtx;

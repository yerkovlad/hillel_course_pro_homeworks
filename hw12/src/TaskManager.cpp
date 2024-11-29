#include "TaskManager.hpp"

void TaskManager::addTask(const Task& task) {
    tasks.push_back(task);
}

std::vector<Task> TaskManager::getTasks() const {
    return tasks;
}

std::vector<Task> TaskManager::filterTasks(std::function<bool(const Task&)> filter) const {
    std::vector<Task> result;
    for (const auto& task : tasks) {
        if (filter(task)) {
            result.push_back(task);
        }
    }
    return result;
}

void TaskManager::sortTasks(std::function<bool(const Task&, const Task&)> comparator) {
    std::sort(tasks.begin(), tasks.end(), comparator);
}

void TaskManager::removeTask(std::function<bool(const Task&)> filter) {
    tasks.erase(std::remove_if(tasks.begin(), tasks.end(), filter), tasks.end());
}

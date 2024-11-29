#ifndef TASKMANAGER_HPP
#define TASKMANAGER_HPP

#include "Task.hpp"
#include <vector>
#include <functional>

class TaskManager {
private:
    std::vector<Task> tasks;

public:
    void addTask(const Task& task);
    std::vector<Task> getTasks() const;
    std::vector<Task> filterTasks(std::function<bool(const Task&)> filter) const;
    void sortTasks(std::function<bool(const Task&, const Task&)> comparator);
    void editTask(size_t index, std::function<void(Task&)> editor);
    void deleteTask(size_t index);
};

#endif

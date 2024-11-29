#ifndef TASKVIEW_HPP
#define TASKVIEW_HPP

#include "Task.hpp"
#include <vector>
#include <string>

class TaskView {
public:
    void displayTasks(const std::vector<Task>& tasks);
    std::string getInput(const std::string& prompt);
    int getIntegerInput(const std::string& prompt);
};

#endif

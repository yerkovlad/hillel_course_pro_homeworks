#include "TaskView.hpp"
#include <iostream>

void TaskView::displayTasks(const std::vector<Task>& tasks) {
    for (const auto& task : tasks) {
        std::cout << "Title: " << task.getTitle() 
                  << ", Description: " << task.getDescription()
                  << ", Priority: " << task.getPriority() 
                  << ", Deadline: " << std::chrono::system_clock::to_time_t(task.getDeadline())
                  << ", Is Done: " << (task.isDone() ? "Yes" : "No") 
                  << ", Created At: " << std::chrono::system_clock::to_time_t(task.getCreatedAt())
                  << "\n";
    }
}

std::string TaskView::getInput(const std::string& prompt) {
    std::cout << prompt;
    std::string input;
    std::getline(std::cin, input);
    return input;
}

int TaskView::getIntegerInput(const std::string& prompt) {
    std::cout << prompt;
    int value;
    std::cin >> value;
    std::cin.ignore(); // Очистка буфера после считывания числа
    return value;
}

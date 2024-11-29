#include "TaskController.hpp"
#include <iostream>

TaskController::TaskController(TaskManager& model, TaskView& view)
    : model(model), view(view) {}

void TaskController::addTask() {
    std::string title = view.getInput("Enter task title: ");
    std::string description = view.getInput("Enter task description: ");
    int priority = view.getIntegerInput("Enter task priority (1-5): ");
    auto deadline = std::chrono::system_clock::now() + std::chrono::hours(24);

    model.addTask(Task(title, description, priority, deadline));
    std::cout << "Task added successfully!\n";
}

void TaskController::showTasks() {
    auto tasks = model.getTasks();
    view.displayTasks(tasks);
}

void TaskController::sortTasks() {
    int option = view.getIntegerInput("Sort by: 1. Priority 2. Deadline 3. Title\n");
    if (option == 1) {
        model.sortTasks([](const Task& a, const Task& b) { return a.getPriority() > b.getPriority(); });
    } else if (option == 2) {
        model.sortTasks([](const Task& a, const Task& b) { return a.getDeadline() < b.getDeadline(); });
    } else if (option == 3) {
        model.sortTasks([](const Task& a, const Task& b) { return a.getTitle() < b.getTitle(); });
    }
    std::cout << "Tasks sorted!\n";
}

void TaskController::markTaskAsDone() {
    int index = view.getIntegerInput("Enter task index to mark as done: ");
    auto tasks = model.getTasks();
    if (index >= 0 && index < tasks.size()) {
        tasks[index].markAsDone();
        std::cout << "Task marked as done!\n";
    } else {
        std::cout << "Invalid index!\n";
    }
}

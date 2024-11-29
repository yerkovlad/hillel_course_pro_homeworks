#ifndef TASKCONTROLLER_HPP
#define TASKCONTROLLER_HPP

#include "TaskManager.hpp"
#include "TaskView.hpp"

class TaskController {
private:
    TaskManager& model;
    TaskView& view;

public:
    TaskController(TaskManager& model, TaskView& view);

    void addTask();
    void showTasks();
    void sortTasks();
    void filterTasks();
    void markTaskAsDone();
    void editTask();
    void deleteTask();
};

#endif

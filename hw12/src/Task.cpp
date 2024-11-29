#include "Task.hpp"

Task::Task(const std::string& title, const std::string& description, int priority, 
           const std::chrono::system_clock::time_point& deadline)
    : title(title), description(description), priority(priority), 
      deadline(deadline), is_done(false), created_at(std::chrono::system_clock::now()) {}

const std::string& Task::getTitle() const {
    return title;
}

const std::string& Task::getDescription() const {
    return description;
}

int Task::getPriority() const {
    return priority;
}

std::chrono::system_clock::time_point Task::getDeadline() const {
    return deadline;
}

bool Task::isDone() const {
    return is_done;
}

std::chrono::system_clock::time_point Task::getCreatedAt() const {
    return created_at;
}

void Task::markAsDone() {
    is_done = true;
}

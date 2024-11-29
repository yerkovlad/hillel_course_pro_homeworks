#ifndef TASK_HPP
#define TASK_HPP

#include <string>
#include <chrono>

class Task {
private:
    std::string title;
    std::string description;
    int priority;
    std::chrono::system_clock::time_point deadline;
    bool is_done;
    std::chrono::system_clock::time_point created_at;

public:
    Task(const std::string& title, const std::string& description, int priority, 
         const std::chrono::system_clock::time_point& deadline);

    const std::string& getTitle() const;
    const std::string& getDescription() const;
    int getPriority() const;
    std::chrono::system_clock::time_point getDeadline() const;
    bool isDone() const;
    std::chrono::system_clock::time_point getCreatedAt() const;

    void setTitle(const std::string& newTitle);
    void setDescription(const std::string& newDescription);
    void setPriority(int newPriority);
    void markAsDone();
};

#endif

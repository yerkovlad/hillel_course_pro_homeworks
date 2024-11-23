#pragma once

#include <string>
#include <memory>
#include <vector>
#include <iostream>

class Course;

class Student {
private:
    std::string name;
    std::string group;
    std::vector<std::shared_ptr<Course>> courses;

public:
    Student(const std::string& name, const std::string& group)
        : name(name), group(group) {}

    void setName(const std::string& newName) { name = newName; }
    void setGroup(const std::string& newGroup) { group = newGroup; }

    std::string getName() const { return name; }
    std::string getGroup() const { return group; }

    void addCourse(const std::shared_ptr<Course>& course) {
        courses.push_back(course);
    }

    void print() const {
        std::cout << "Student: " << name << ", Group: " << group << "\n";
    }
};
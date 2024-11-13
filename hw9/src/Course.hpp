#pragma once

#include "Student.hpp"
#include <vector>
#include <memory>
#include <ranges>
#include <algorithm>
#include <iostream>

class Course {
private:
    std::string courseName;
    std::vector<std::shared_ptr<Student*>> students;

public:
    explicit Course(const std::string& name) : courseName(name) {}

    void addStudent(const std::shared_ptr<Student*>& student) {
        students.push_back(student);
    }

    std::vector<std::string> getGroups() const {
        std::vector<std::string> groups;
        for (const auto& studentPtr : students) {
            if (studentPtr && *studentPtr) {
                groups.push_back((*studentPtr)->getGroup());
            }
        }
        return groups;
    }

    void printCourseInfo() const {
        std::cout << "Course: " << courseName << "\n";
        for (const auto& studentPtr : students) {
            if (studentPtr && *studentPtr) {
                (*studentPtr)->print();
            }
        }
    }
};
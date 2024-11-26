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
    auto groupList = students 
        | std::views::filter([](const auto& studentPtr) { return studentPtr && *studentPtr; })
        | std::views::transform([](const auto& studentPtr) { return (*studentPtr)->getGroup(); });

    std::set<std::string> uniqueGroups(groupList.begin(), groupList.end());
    return std::vector<std::string>(uniqueGroups.begin(), uniqueGroups.end());
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

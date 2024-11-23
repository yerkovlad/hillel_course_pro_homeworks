#pragma once

#include "Student.hpp"
#include <string>
#include <vector>
#include <memory>
#include <set>
#include <iostream>
#include <ranges>
#include <algorithm>

class Course {
private:
    std::string courseName;
    std::vector<std::weak_ptr<Student>> students;

public:
    explicit Course(const std::string& name) : courseName(name) {}

    void addStudent(const std::shared_ptr<Student>& student) {
        students.push_back(student);
        student->addCourse(std::shared_ptr<Course>(this));
    }

    auto getUniqueGroups() const {
        auto groups = students
                      | std::views::transform([](const auto& weakStudent) {
                            if (auto student = weakStudent.lock()) {
                                return student->getGroup();
                            }
                            return std::string{};
                        });

        std::set<std::string> uniqueGroups(groups.begin(), groups.end());
        return std::vector<std::string>(uniqueGroups.begin(), uniqueGroups.end());
    }

    void printCourseInfo() const {
        std::cout << "Course: " << courseName << "\n";
        for (const auto& weakStudent : students) {
            if (auto student = weakStudent.lock()) {
                student->print();
            }
        }
    }
};
#include "Student.hpp"
#include "Course.hpp"
#include <iostream>
#include <vector>
#include <memory>
#include <ranges>
#include <set>

int main() {
    auto student1 = std::make_shared<Student>("Petrenko", "A1");
    auto student2 = std::make_shared<Student>("Ivanenko", "B2");
    auto student3 = std::make_shared<Student>("Shevchenko", "A1");
    auto student4 = std::make_shared<Student>("Bondarenko", "C3");

    auto math = std::make_shared<Course>("Mathematics");
    auto physics = std::make_shared<Course>("Physics");

    math->addStudent(student1);
    math->addStudent(student3);
    physics->addStudent(student2);
    physics->addStudent(student4);

    std::vector<std::shared_ptr<Course>> courses{math, physics};

    for (const auto& coursePtr : courses) {
        if (coursePtr) {
            coursePtr->printCourseInfo();
            auto uniqueGroups = coursePtr->getUniqueGroups();

            std::cout << "Groups attending the course: ";
            for (const auto& group : uniqueGroups) {
                std::cout << group << " ";
            }
            std::cout << "\n\n";
        }
    }

    return 0;
}
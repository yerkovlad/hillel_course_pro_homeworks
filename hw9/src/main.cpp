#include "Student.hpp"
#include "Course.hpp"
#include <iostream>
#include <vector>
#include <memory>

int main() {
    std::shared_ptr<Student*> student1(new Student("Petrenko", "A1"));
    std::shared_ptr<Student*> student2(new Student("Ivanenko", "B2"));
    std::shared_ptr<Student*> student3(new Student("Shevchenko", "A1"));
    std::shared_ptr<Student*> student4(new Student("Bondarenko", "C3"));

    std::vector<std::shared_ptr<Student*>> students;
    students.push_back(student1);
    students.push_back(student2);
    students.push_back(student3);
    students.push_back(student4);

    std::shared_ptr<Course*> math(new Course("Mathematics"));
    std::shared_ptr<Course*> physics(new Course("Physics"));

    math->addStudent(student1);
    math->addStudent(student3);
    physics->addStudent(student2);
    physics->addStudent(student4);

    std::vector<std::shared_ptr<Course*>> courses;
    courses.push_back(math);
    courses.push_back(physics);

    for (const auto& coursePtr : courses) {
        if (coursePtr && *coursePtr) {
            (*coursePtr)->printCourseInfo();
            std::vector<std::string> groups = (*coursePtr)->getGroups();
            std::cout << "Groups attending the course: ";
            for (const auto& group : groups) {
                std::cout << group << " ";
            }
            std::cout << "\n\n";
        }
    }

    return 0;
}
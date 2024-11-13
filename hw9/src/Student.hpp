#pragma once

#include <string>
#include <memory>
#include <iostream>

class Student {
private:
    std::string name;
    std::string group;

public:
    Student(const std::string& name, const std::string& group)
        : name(name), group(group) {}

    void setName(const std::string& newName) { name = newName; }
    void setGroup(const std::string& newGroup) { group = newGroup; }

    std::string getName() const { return name; }
    std::string getGroup() const { return group; }

    void print() const {
        std::cout << "Student: " << name << ", Group: " << group << "\n";
    }
};
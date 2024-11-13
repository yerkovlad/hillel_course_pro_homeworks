#pragma once

#include <iostream>

template<typename T>
class MySharedPtr {
private:
    T* myData;
    size_t* myCounter;

public:
    explicit MySharedPtr(T* value = nullptr)
        : myData(value), myCounter(new size_t(1)) {
        std::cout << "Created MySharedPtr, count = " << *myCounter << "\n";
    }

    MySharedPtr(const MySharedPtr<T>& other)
        : myData(other.myData), myCounter(other.myCounter) {
        ++(*myCounter);
        std::cout << "Copied MySharedPtr, count = " << *myCounter << "\n";
    }

    MySharedPtr<T>& operator=(const MySharedPtr<T>& other) {
        if (this != &other) {
            release();
            myData = other.myData;
            myCounter = other.myCounter;
            ++(*myCounter);
            std::cout << "Assigned MySharedPtr, count = " << *myCounter << "\n";
        }
        return *this;
    }

    T& operator*() const {
        return *myData;
    }

    T* operator->() const {
        return myData;
    }

    size_t use_count() const {
        return *myCounter;
    }

    ~MySharedPtr() {
        release();
    }

private:
    void release() {
        if (myCounter) {
            --(*myCounter);
            std::cout << "Released MySharedPtr, count = " << *myCounter << "\n";
            if (*myCounter == 0) {
                delete myData;
                delete myCounter;
                std::cout << "Deleted MySharedPtr data\n";
            }
        }
    }
};
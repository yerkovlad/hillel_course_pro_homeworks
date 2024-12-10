#pragma once

#include <iostream>
#include <atomic>
#include <functional>
#include <mutex>

template<typename T>
class MySharedPtr {
private:
    T* myData;
    std::atomic<size_t>* myCounter;

public:
    explicit MySharedPtr(T* value = nullptr)
        : myData(value), myCounter(new std::atomic<size_t>(1)) {
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

    MySharedPtr(MySharedPtr<T>&& other) noexcept
        : myData(other.myData), myCounter(other.myCounter) {
        other.myData = nullptr;
        other.myCounter = nullptr;
        std::cout << "Moved MySharedPtr\n";
    }

    MySharedPtr<T>& operator=(MySharedPtr<T>&& other) noexcept {
        if (this != &other) {
            release();
            myData = other.myData;
            myCounter = other.myCounter;
            other.myData = nullptr;
            other.myCounter = nullptr;
            std::cout << "Move-assigned MySharedPtr\n";
        }
        return *this;
    }

    bool operator==(const MySharedPtr<T>& other) const {
        return myData == other.myData;
    }

    struct Hasher {
        size_t operator()(const MySharedPtr<T>& ptr) const {
            return std::hash<T*>()(ptr.myData);
        }
    };

    T& operator*() const {
        return *myData;
    }

    T* operator->() const {
        return myData;
    }

    size_t use_count() const {
        return myCounter ? myCounter->load() : 0;
    }

    ~MySharedPtr() {
        release();
    }

private:
    void release() {
        if (myCounter) {
            if (--(*myCounter) == 0) {
                delete myData;
                delete myCounter;
                std::cout << "Deleted MySharedPtr data\n";
            } else {
                std::cout << "Released MySharedPtr, count = " << *myCounter << "\n";
            }
        }
    }
};

#include "SharedPtr.hpp"
#include <iostream>
#include <thread>
#include <mutex>

std::mutex resourceMutex;

void threadFunction(MySharedPtr<int> sharedPtr) {
    std::lock_guard<std::mutex> lock(resourceMutex);
    std::cout << "Thread: Initial value = " << *sharedPtr << ", use_count = " << sharedPtr.use_count() << "\n";
    *sharedPtr = 500;
    std::cout << "Thread: Modified value = " << *sharedPtr << ", use_count = " << sharedPtr.use_count() << "\n";
}

int main() {
    MySharedPtr<int> ptr1(new int(42));
    std::cout << "Main: ptr1 value = " << *ptr1 << ", use_count = " << ptr1.use_count() << "\n";

    {
        std::lock_guard<std::mutex> lock(resourceMutex);
        *ptr1 = 100;
    }

    std::thread t1(threadFunction, ptr1);

    {
        std::lock_guard<std::mutex> lock(resourceMutex);
        std::cout << "Main: After thread, ptr1 value = " << *ptr1 << ", use_count = " << ptr1.use_count() << "\n";
    }

    t1.join();

    return 0;
}

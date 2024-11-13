#include "SharedPtr.hpp"
#include <iostream>

int main() {
    MySharedPtr<int> ptr1(new int(42));
    std::cout << "ptr1 value: " << *ptr1 << ", use_count: " << ptr1.use_count() << "\n";

    {
        MySharedPtr<int> ptr2 = ptr1;
        std::cout << "ptr2 value: " << *ptr2 << ", use_count: " << ptr2.use_count() << "\n";

        *ptr2 = 100;
        std::cout << "Modified ptr2 value: " << *ptr1 << "\n";
    }

    std::cout << "After ptr2 is out of scope, use_count: " << ptr1.use_count() << "\n";
    return 0;
}
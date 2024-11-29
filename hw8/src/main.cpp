#include "SharedPtr.hpp"
#include <iostream>
#include <unordered_set>

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

    MySharedPtr<int> ptr3 = std::move(ptr1);
    std::cout << "After move, ptr3 use_count: " << ptr3.use_count() << "\n";
    std::cout << "After move, ptr1 use_count: " << ptr1.use_count() << "\n";

    std::unordered_set<MySharedPtr<int>, MySharedPtr<int>::Hasher> mySet;
    mySet.insert(ptr3);
    mySet.insert(MySharedPtr<int>(new int(200)));

    for (const auto& elem : mySet) {
        std::cout << "Set element value: " << *elem << ", use_count: " << elem.use_count() << "\n";
    }

    MySharedPtr<int> ptr4 = ptr3;
    std::cout << "ptr3 == ptr4: " << (ptr3 == ptr4 ? "true" : "false") << "\n";

    return 0;
}

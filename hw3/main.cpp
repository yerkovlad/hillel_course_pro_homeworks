#include <iostream>

struct Rectangle {
    int width;
    int height;

    constexpr int area() const {
        return width * height;
    }
};

int main() {
    constexpr Rectangle rect_const{5, 10};
    constexpr int area_const = rect_const.area();
    std::cout << "Compile-time area: " << area_const << std::endl;

    int width, height;
    std::cout << "Enter width and height: ";
    std::cin >> width >> height;
    Rectangle rect_dynamic{width, height};
    std::cout << "Runtime area: " << rect_dynamic.area() << std::endl;

    return 0;
}

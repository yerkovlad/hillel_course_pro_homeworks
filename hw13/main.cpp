#include <iostream>
#include <string>
#include <stdexcept>
#include <iomanip>

enum class ConversionType { Length, Mass, Temperature };

template<ConversionType Type>
double convert(double value, const std::string& from, const std::string& to) {
    if constexpr (Type == ConversionType::Length) {
        if (from == "m" && to == "km") return value / 1000.0;
        if (from == "km" && to == "m") return value * 1000.0;
        if (from == "cm" && to == "m") return value / 100.0;
        if (from == "m" && to == "cm") return value * 100.0;
        throw std::invalid_argument("Unsupported length conversion.");
    } else if constexpr (Type == ConversionType::Mass) {
        if (from == "kg" && to == "g") return value * 1000.0;
        if (from == "g" && to == "kg") return value / 1000.0;
        if (from == "lb" && to == "kg") return value * 0.453592;
        if (from == "kg" && to == "lb") return value / 0.453592;
        throw std::invalid_argument("Unsupported mass conversion.");
    } else if constexpr (Type == ConversionType::Temperature) {
        if (from == "C" && to == "F") return value * 9.0 / 5.0 + 32.0;
        if (from == "F" && to == "C") return (value - 32.0) * 5.0 / 9.0;
        if (from == "C" && to == "K") return value + 273.15;
        if (from == "K" && to == "C") return value - 273.15;
        throw std::invalid_argument("Unsupported temperature conversion.");
    }
    throw std::invalid_argument("Unsupported conversion type.");
}

void showMenu() {
    std::cout << "Choose conversion type:\n";
    std::cout << "1. Length (m, km, cm)\n";
    std::cout << "2. Mass (kg, g, lb)\n";
    std::cout << "3. Temperature (C, F, K)\n";
    std::cout << "Enter your choice: ";
}

int main() {
    try {
        int choice;
        showMenu();
        std::cin >> choice;

        if (choice < 1 || choice > 3) {
            std::cerr << "Invalid choice. Exiting.\n";
            return 1;
        }

        double value;
        std::string from, to;
        std::cout << "Enter value to convert: ";
        std::cin >> value;
        std::cout << "Enter the unit to convert from: ";
        std::cin >> from;
        std::cout << "Enter the unit to convert to: ";
        std::cin >> to;

        double result = 0.0;

        switch (choice) {
        case 1:
            result = convert<ConversionType::Length>(value, from, to);
            break;
        case 2:
            result = convert<ConversionType::Mass>(value, from, to);
            break;
        case 3:
            result = convert<ConversionType::Temperature>(value, from, to);
            break;
        default:
            throw std::invalid_argument("Invalid conversion type.");
        }

        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Converted value: " << result << " " << to << "\n";

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    return 0;
}

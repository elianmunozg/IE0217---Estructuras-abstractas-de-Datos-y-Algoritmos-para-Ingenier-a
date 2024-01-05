#include <iostream>

int main() {
    int num;

    std::cout << "Enter an integer: ";
    std::cin >> num;

    // outer if condition
    if (num != 0) {
        // inner if condition
        if (num > 0) {
            std::cout << "The number is positive." << std::endl;
        }
        // inner else condition
        else {
            std::cout << "The number is negative." << std::endl;
        }
    }
    // outer else condition
    else {
        std::cout << "The number is 0 and it is neither positive nor negative." << std::endl;
    }

    std::cout << "This line is always printed." << std::endl;

    return 0;
}

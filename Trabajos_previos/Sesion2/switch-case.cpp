#include <iostream>

int main() {
    char oper;
    float num1, num2;

    std::cout << "Enter an operator (+, -, *, /): ";
    std::cin >> oper;

    std::cout << "Enter two numbers: " << std::endl;
    std::cin >> num1 >> num2;

    switch (oper) {
        case '+':
            std::cout << num1 + num2;
            break;
        case '-':
            std::cout << num1 - num2;
            break;
        case '*':
            std::cout << num1 * num2;
            break;
        case '/':
            if (num2 != 0) {
                std::cout << num1 / num2;
            } else {
                std::cout << "Error! Division by zero is not allowed.";
            }
            break;
        default:
            // Si el operador no coincide con ningún caso constante (+, -, *, /)
            std::cout << "Error! The operator is not correct";
            break;
    }

    return 0;
}

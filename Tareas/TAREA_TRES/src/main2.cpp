#include <iostream>
#include "EmailValidator.hpp"

int main() {
    EmailValidator validator;
    std::string email;

    std::cout << "Ingrese una dirección de correo electrónico para validar: ";
    std::getline(std::cin, email);

    try {
        if (validator.IsValidEmail(email)) {
            std::cout << "La dirección de correo electrónico es válida." << std::endl;
        } else {
            std::cout << "La dirección de correo electrónico NO es válida." << std::endl;
        }
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}

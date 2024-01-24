#include <iostream>
#include "EmailValidator.hpp"

int main() {
    EmailValidator emailValidator; // Crea una instancia de la clase EmailValidator

    std::string email;

    try {
        std::cout << "Ingrese una dirección de correo electrónico: ";
        std::cin >> email;

        if (emailValidator.IsValidEmail(email)) {
            std::cout << "La dirección de correo electrónico es válida." << std::endl;
        } else {
            std::cout << "La dirección de correo electrónico no es válida." << std::endl;
        }
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}

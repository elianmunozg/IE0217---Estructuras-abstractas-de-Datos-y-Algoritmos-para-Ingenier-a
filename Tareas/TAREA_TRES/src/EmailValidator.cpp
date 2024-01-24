#include "EmailValidator.hpp"
#include <iostream>
#include <regex>

bool EmailValidator::IsValidEmail(const std::string& email) {
    // Expresión regular para validar el formato de correo electrónico
    std::regex regexPattern("^[a-zA-Z0-9]+([.-]?[a-zA-Z0-9]+)*@[a-zA-Z]+\\.[a-zA-Z]{2,4}$");

    // Comprueba si el correo electrónico coincide con la expresión regular
    if (std::regex_match(email, regexPattern)) {
        // Divide la dirección de correo electrónico en partes
        size_t atIndex = email.find('@');
        std::string name = email.substr(0, atIndex);
        std::string domain = email.substr(atIndex + 1);

        // Verifica la longitud del nombre y que no comience ni termine con un punto o guión
        if (name.length() <= 15 && name.front() != '.' && name.back() != '.' && name.front() != '-' && name.back() != '-') {
            // Verifica el dominio
            size_t dotIndex = domain.find('.');
            if (dotIndex != std::string::npos && domain.length() > (dotIndex + 1) &&
                std::regex_match(domain, std::regex("^[a-zA-Z]+$"))) {
                // Verifica la extensión
                std::string extension = domain.substr(dotIndex + 1);
                if (extension.length() >= 2 && extension.length() <= 4 &&
                    std::regex_match(extension, std::regex("^[a-zA-Z]+$"))) {
                    return true; // Correo electrónico válido
                }
            }
        }
    }
    
    throw std::invalid_argument("La dirección de correo electrónico no es válida.");
}

#include "EmailValidator.hpp"
#include <iostream>
#include <regex>
bool EmailValidator::IsValidEmail(const std::string& email) {
    // Verifica si '@' está presente
    if (email.find('@') == std::string::npos) {
        throw std::invalid_argument("El correo debe contener '@'");
    }

    // Expresión regular para validar el formato de correo electrónico
    std::regex regexPattern("^[a-zA-Z0-9][-a-zA-Z0-9\\.]{0,13}[a-zA-Z0-9]@[a-zA-Z]+(\\.[a-zA-Z]{2,4})+$");

    // Comprueba si el correo electrónico coincide con la expresión regular
    if (std::regex_match(email, regexPattern)) {
        return true; // Correo electrónico válido
    }
    
    throw std::invalid_argument("La dirección de correo electrónico no es válida.");
}
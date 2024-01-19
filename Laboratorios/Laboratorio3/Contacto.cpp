// Incluye la definición de la plantilla si es necesario.
// Por ejemplo:
#include "Contacto.hpp"

template <typename T>
Contacto<T>::Contacto(const T& nombre, const T& telefono, const T& email)
    : nombre(nombre), telefono(telefono), email(email) {}

// Getters
template <typename T>
T Contacto<T>::getNombre() const {
    return nombre;
}

template <typename T>
T Contacto<T>::getTelefono() const {
    return telefono;
}

template <typename T>
T Contacto<T>::getEmail() const {
    return email;
}


template class Contacto<std::string>;
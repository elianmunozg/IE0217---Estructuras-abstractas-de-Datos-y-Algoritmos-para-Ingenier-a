#include "Agenda.hpp"

template <typename T>
void Agenda<T>::agregarContacto(const Contacto<T>& nuevoContacto) {
    for (const auto& item : contactos) {
        if (item.getTelefono() == nuevoContacto.getTelefono()) {
            throw std::invalid_argument("Ya existe un contacto con este número");
        }
    }
    contactos.push_back(nuevoContacto);
}

template <typename T>
void Agenda<T>::eliminarContacto(const T& telefono) {
    auto it = std::find_if(contactos.begin(), contactos.end(), [&telefono](const Contacto<T>& contacto) {
        return contacto.getTelefono() == telefono;
    });
    if (it != contactos.end()) {
        contactos.erase(it);
    } else {
        throw std::out_of_range("No se encuentra un contacto con ese número");
    }
}

template <typename T>
void Agenda<T>::mostrarContactos() const {
    for (const auto& contacto : contactos) {
        std::cout << "Nombre: " << contacto.getNombre() << " "
                  << "Telefono: " << contacto.getTelefono() << " "
                  << "Email: " << contacto.getEmail() << std::endl;
    }
}

template <typename T>
std::list<Contacto<T>> Agenda<T>::buscarContactos(const std::string& patron) const {
    std::list<Contacto<T>> resultados;
    for (const auto& contacto : contactos) {
        if (contacto.getNombre().find(patron) != std::string::npos ||
            contacto.getTelefono().find(patron) != std::string::npos ||
            contacto.getEmail().find(patron) != std::string::npos) {
            resultados.push_back(contacto);
        }
    }
    return resultados;
}


template class Agenda<std::string>;

// Si vas a usar la plantilla con otros tipos, deberás agregar más líneas como esta:
// template class Agenda<int>;
// template class Agenda<otro_tipo>;

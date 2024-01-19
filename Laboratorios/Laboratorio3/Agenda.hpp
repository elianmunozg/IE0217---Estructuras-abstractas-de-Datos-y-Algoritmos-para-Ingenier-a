#ifndef AGENDA_HPP
#define AGENDA_HPP
#include <algorithm>
#include <iostream>
#include <list>
#include "Contacto.hpp"

template <typename T>
class Agenda {
public:
    void agregarContacto(const Contacto<T>& nuevoContacto);
    void eliminarContacto(const T& telefono);
    void mostrarContactos() const;
    std::list<Contacto<T>> buscarContactos(const std::string& patron) const;

private:
    std::list<Contacto<T>> contactos;
};

#endif // AGENDA_HPP

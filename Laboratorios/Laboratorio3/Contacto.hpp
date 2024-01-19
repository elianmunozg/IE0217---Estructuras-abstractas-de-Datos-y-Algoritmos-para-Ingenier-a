// Contacto.hpp

#ifndef CONTACTO_HPP
#define CONTACTO_HPP

#include <string>

template <typename T>
class Contacto {
public:
    Contacto(const T& nombre, const T& telefono, const T& email);
    T getNombre() const;
    T getTelefono() const;
    T getEmail() const;

private:
    T nombre;
    T telefono;
    T email;
};



#endif // CONTACTO_HPP

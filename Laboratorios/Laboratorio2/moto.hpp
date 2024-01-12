#ifndef MOTO_HPP 
#define MOTO_HPP

#include "vehiculo.hpp" 

class Moto : public Vehiculo {
public:
    Moto(int velocidad, bool tieneCasco);
    void usarCasco();

private:
    bool tieneCasco;
}; 

#endif // MOTO_HPP

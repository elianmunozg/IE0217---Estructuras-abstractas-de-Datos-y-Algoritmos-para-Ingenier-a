#include "moto.hpp"
#include <iostream> 


Moto::Moto(int velocidad, bool tieneCasco)
    : Vehiculo(velocidad), tieneCasco(tieneCasco) {}


void Moto::usarCasco() {
    if (tieneCasco) {
        std::cout << "Usando casco mientras conduzco la moto." << std::endl;
    } else {
        std::cout << "Alerta!!! No tengo casco." << std::endl;
    }
}

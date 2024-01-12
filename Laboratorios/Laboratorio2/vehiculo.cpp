#include "vehiculo.hpp"
#include "iostream"


Vehiculo::Vehiculo(int param_velocidad) {
    this->velocidad = param_velocidad;
}

void Vehiculo::acelerar() {
    std::cout << "Acelerando el vehiculo hasta " << velocidad << " km/h" << std::endl;
}

void Vehiculo::frenar() {
    std::cout << "Frenando el vehiculo" << std::endl;
}

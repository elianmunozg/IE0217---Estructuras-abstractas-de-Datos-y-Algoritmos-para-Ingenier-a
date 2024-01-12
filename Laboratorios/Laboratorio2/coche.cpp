#include "coche.hpp"
#include <iostream> 

Coche::Coche(int velocidad, int numPuertas) : Vehiculo(velocidad), numPuertas(numPuertas) {
    
}


void Coche::abrirPuertas() {
   
    std::cout << "Abriendo las puertas\n"; 
}
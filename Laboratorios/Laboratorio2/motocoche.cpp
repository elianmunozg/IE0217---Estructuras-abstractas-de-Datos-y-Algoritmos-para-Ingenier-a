#include "motoCoche.hpp"
#include <iostream> 


MotoCoche::MotoCoche(int velocidad, int numPuertas, bool tieneCasco)
    : Coche(velocidad, numPuertas), Moto(velocidad, tieneCasco) {
    std::cout << "Instanciando un MotoCoche" << std::endl; 
}

#ifndef MOTOCOCHE_HPP
#define MOTOCOCHE_HPP

#include "coche.hpp" 
#include "moto.hpp"  

// Clase MotoCoche que hereda de Coche y Moto.
class MotoCoche : public Coche, public Moto {
public:
    // Constructor de MotoCoche que recibe la velocidad, número de puertas y si tiene casco.
    MotoCoche(int velocidad, int numPuertas, bool tieneCasco);
};

#endif // MOTOCOCHE_HPP

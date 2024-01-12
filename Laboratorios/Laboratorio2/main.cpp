#include "motocoche.hpp"

int main() {
    MotoCoche miMotoCoche(60, 2, false);

    miMotoCoche.Coche::acelerar();
    miMotoCoche.abrirPuertas();
    miMotoCoche.usarCasco();

    return 0;
}

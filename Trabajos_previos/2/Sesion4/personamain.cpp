#include <iostream>
#include "persona.hpp"

using namespace std;

int main() {
    // Crear una persona con nombre "Juan" y edad 25
    Persona p("Juan", 25);

    // Mostrar el nombre y la edad de la persona
    cout << "Nombre: " << p.getNombre() << endl;
    cout << "Edad: " << p.getEdad() << endl;

    // Cambiar la edad de la persona y mostrar la nueva edad
    p.setEdad(26);
    cout << "Nueva edad: " << p.getEdad() << endl;

    return 0;
}

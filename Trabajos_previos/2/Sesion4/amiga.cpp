#include <iostream>
using namespace std;

// Declaración de la clase Distance
class Distance {
private:
    int meter;

    // Declaración de la función friend
    friend int addFive(Distance);

public:
    // Constructor por defecto
    Distance() : meter(0) {}

    // Función para acceder a miembros privados desde la función friend
    int addFive(Distance d) {
        d.meter += 5;
        return d.meter;
    }
};

// Definición de la función friend
int addFive(Distance d) {
    // Accediendo al miembro privado meter de la clase Distance
    d.meter += 5;
    return d.meter;
}

int main() {
    // Crear un objeto de la clase Distance
    Distance D;

    // Llamar a la función friend desde el main
    cout << "Distance: " << addFive(D) << endl;

    return 0;
}

#include <iostream>
using namespace std;

class Molde {
public: // Mueve esta sección al interior de la clase
    double largo;
    double ancho;
    double altura;

    Molde() {
        cout << "Esto se ejecuta en cada instanciacion" << endl;
        cout << "Iniciando un objeto de la clase Molde" << endl;
    }

    double calcularArea() {
        return largo * ancho;
    }

    double calcularVolumen() {
        return largo * ancho * altura;
    }
};

int main() {
    // Instanciar un objeto llamado pared basado en la clase Molde.
    Molde pared;

    // Asignar valores al objeto pared.
    pared.largo = 400.5;
    pared.ancho = 20.8;
    pared.altura = 315.2;

    // Calcular y desplegar el área y volumen.
    cout << "Area = " << pared.calcularArea() << endl;
    cout << "Volumen = " << pared.calcularVolumen() << endl;

    return 0;
}

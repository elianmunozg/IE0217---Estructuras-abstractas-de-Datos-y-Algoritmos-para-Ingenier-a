#include <iostream>
using namespace std;

class Molde {
public:
    double largo;
    double ancho;
    double alto;

    // Constructor
    Molde(double largo_p, double ancho_p, double alto_p) : largo(largo_p), ancho(ancho_p), alto(alto_p) {
        cout << "Probando si se puede imprimir" << endl;
    }

    // Destructor
    ~Molde() {
        cout << "Saludos desde el destructor de la clase Molde" << endl;
    }

    // Función para calcular el área
    double calcularArea() {
        return largo * ancho;
    }

    // Función para calcular el volumen
    double calcularVolumen() {
        return largo * ancho * alto;
    }
};

int main() {
    // Declaración de una variable entera
    int variable_entera;

    // Instanciar un objeto llamado "pared" basado en la clase Molde
    Molde pared(10.0, 20.0, 35.0);

    // Imprimir el área y el volumen
    cout << "El área es: " << pared.calcularArea() << endl;
    cout << "El volumen es: " << pared.calcularVolumen() << endl;

    return 0;
}

#include <iostream>
using namespace std;

class Molde {
public:
    double largo;
    double ancho;
    double alto;

    // Constructor que inicializa los atributos con los valores proporcionados
    Molde(double largo_p, double ancho_p, double alto_p) : largo(largo_p), ancho(ancho_p), alto(alto_p) {}

    // Función para imprimir los valores de largo, ancho y alto
    void imprimirMedidas() {
        cout << "Largo: " << largo << ", Ancho: " << ancho << ", Alto: " << alto << endl;
    }
};

int main() {
    // Declaración de una variable entera
    int variable_entera;

    // Instanciar un objeto llamado "pared" basado en la clase Molde
    Molde pared(10.0, 20.0, 35.0);

    // Imprimir el valor inicial del atributo "largo"
    cout << "Valor inicial de largo: " << pared.largo << endl;

    // Modificar el valor del atributo "largo"
    pared.largo = 20.0;

    // Imprimir el nuevo valor del atributo "largo"
    cout << "Nuevo valor de largo: " << pared.largo << endl;

    // Modificar el valor de los atributos "ancho" y "alto"
    pared.ancho = 13.2;
    pared.alto = 23.4;

    // Imprimir todas las medidas
    pared.imprimirMedidas();

    return 0;
}

#include <iostream>
using namespace std;

// Clase base 'Animal' que se utilizará para estudiar tipos de acceso
class Animal {
public:
    // Función para establecer la edad (pública)
    void setEdad(int age) {
        edad = age;
    }

    // Función para obtener la edad (pública)
    int getEdad() {
        return edad;
    }

protected:
    // Miembro protegido 'nombre', accesible por clases derivadas
    string nombre;

private:
    // Miembro privado 'edad', accesible solo dentro de la clase 'Animal'
    int edad;
};

// Clase derivada 'Perro' que hereda de la clase 'Animal'
class Perro : public Animal {
public:
    // Función para establecer el nombre del perro (pública)
    void setNombre(string n) {
        nombre = n;
    }

    // Función para obtener el nombre del perro (pública)
    string getNombre() {
        return nombre;
    }
};

int main() {
    // Crear un objeto de la clase derivada 'Perro'
    Perro miPerro;

    // Establecer el nombre y la edad del perro
    miPerro.setNombre("Toby");
    miPerro.setEdad(3);

    // Imprimir información sobre el perro utilizando funciones públicas
    cout << "Mi perro se llama " << miPerro.getNombre() << endl;
    cout << "y tiene " << miPerro.getEdad() << " años." << endl;

    return 0;
}

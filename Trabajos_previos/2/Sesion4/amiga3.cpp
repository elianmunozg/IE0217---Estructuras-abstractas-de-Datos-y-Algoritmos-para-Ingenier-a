#include <iostream>
using namespace std;

// Declaración anticipada de ClassB para que ClassA pueda hacer referencia a ella
class ClassB;

// Definición de ClassA
class ClassA {
private:
    int numA;

public:
    // Constructor para inicializar numA en 12
    ClassA() : numA(12) {}

    // Declaración de la clase ClassB como amiga para que pueda acceder a numA
    friend class ClassB;
};

// Definición de ClassB
class ClassB {
private:
    int numB;

public:
    // Constructor para inicializar numB en 1
    ClassB() : numB(1) {}

    // Función miembro para sumar numA de ClassA y numB de ClassB
    int add(ClassA objectA) {
        // Acceso a numA de ClassA y numB de ClassB
        return objectA.numA + numB;
    }
};

int main() {
    // Crear objetos de ambas clases
    ClassA objectA;
    ClassB objectB;

    // Llamar a la función add de ClassB y mostrar el resultado
    cout << "Sum: " << objectB.add(objectA) << endl;

    return 0;
}

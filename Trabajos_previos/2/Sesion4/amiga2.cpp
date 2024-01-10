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

    // Declaración de la función amiga
    friend int add(ClassA, ClassB);
};

// Definición de ClassB
class ClassB {
private:
    int numB;

public:
    // Constructor para inicializar numB en 1
    ClassB() : numB(1) {}

    // Declaración de la función amiga
    friend int add(ClassA, ClassB);
};

// Definición de la función amiga add
int add(ClassA objectA, ClassB objectB) {
    // Acceso a los miembros privados de ambas clases
    return (objectA.numA + objectB.numB);
}

int main() {
    // Crear objetos de ambas clases
    ClassA objectA;
    ClassB objectB;

    // Llamar a la función amiga add y mostrar el resultado
    cout << "Sum: " << add(objectA, objectB) << endl;

    return 0;
}

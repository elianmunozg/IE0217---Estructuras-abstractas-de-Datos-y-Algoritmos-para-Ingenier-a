#include <iostream>
using namespace std;

// Clase Base
class Base {
public:
    virtual void print() {
        cout << "Base Function" << endl;
    }
};

// Clase Derivada que hereda de Base
class Derived : public Base {
public:
    void print() override {
        cout << "Derived Function" << endl;
    }
};

int main() {
    // Crear un objeto de la clase Derived
    Derived derived1;

    // Puntero de tipo Base que apunta a derived1
    Base* base1 = &derived1;

    // Llamada a la función miembro de la clase Derived
    base1->print();

    return 0;
}

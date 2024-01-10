#include <iostream>
using namespace std;

// Definición de la clase Animal
class Animal {
public:
    // Función para que el animal coma
    void eat() {
        cout << "I can eat!" << endl;
    }

    // Función para que el animal duerma
    void sleep() {
        cout << "I can sleep!" << endl;
    }
};

// Definición de la clase Dog que hereda de Animal
class Dog : public Animal {
public:
    // Función para que el perro ladre
    void bark() {
        cout << "I can bark! Woof woof!!" << endl;
    }
};

int main() {
    // Crear un objeto de la clase Dog
    Dog dog1;

    // Llamar a funciones de la clase base (Animal)
    dog1.eat();
    dog1.sleep();

    // Llamar a función de la clase derivada (Dog)
    dog1.bark();

    return 0;
}

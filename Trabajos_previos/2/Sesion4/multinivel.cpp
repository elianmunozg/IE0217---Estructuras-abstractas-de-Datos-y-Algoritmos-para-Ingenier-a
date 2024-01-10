#include <iostream>
using namespace std;

class Animal {
public:
    void info() {
        cout << "I am an animal." << endl;
    }
};

class Mammal : public Animal {
public:
    Mammal() {
        cout << "Mammals can give direct birth." << endl;
    }
};

class Dog : public Mammal {
public:
    void bark() {
        cout << "I am a Dog. Woof woof." << endl;
    }
};

int main() {
    Dog dog1;
    cout << "Dog Class:" << endl;
    dog1.info();  // Función de la clase base
    dog1.bark();  // Función de la clase derivada
    return 0;
}

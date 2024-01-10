#include <iostream>
using namespace std;

class Animal {
public:
    void info() {
        cout << "I am an animal." << endl;
    }
};

class WingedAnimal {
public:
    WingedAnimal() {
        cout << "Winged animal can flap." << endl;
    }
};

class Cat : public Animal {
public:
    void meow() {
        cout << "I am a Cat. Meow." << endl;
    }
};

class Bat : public Animal, public WingedAnimal {};

int main() {
    Cat cat1;
    cout << "Cat Class:" << endl;
    cat1.info();  // Función de la clase base
    cat1.meow();  // Función de la clase derivada
    return 0;
}

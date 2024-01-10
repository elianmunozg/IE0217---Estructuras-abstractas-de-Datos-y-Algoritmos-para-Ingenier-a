#include <iostream>
#include <string>
using namespace std;

class Animal {
private:
    string color;

protected:
    string type;

public:
    void run() {
        cout << "I can run ---BASE!" << endl;
    }

    void eat() {
        cout << "I can eat!" << endl;
    }

    void sleep() {
        cout << "I can sleep!" << endl;
    }

    void setColor(string clr) {
        color = clr;
    }

    string getColor() {
        return color;
    }
};

class Dog : public Animal {
public:
    void run() {
        cout << "I can run -- DERIVED!" << endl;
    }

    void setType(string tp) {
        type = tp;
    }

    void displayInfo(string c) {
        cout << "I am a " << type << endl;
        cout << "My color is " << c << endl;
    }

    void bark() {
        cout << "I can bark! Woof woof!!" << endl;
    }
};

int main() {
    Dog dog1;

    // Llamar a funciones de la clase base (Animal)
    dog1.run();
    dog1.eat();
    dog1.sleep();
    dog1.setColor("black");

    // Llamar a funciones de la clase derivada (Dog)
    dog1.bark();
    dog1.setType("Doberman");
    
    // Mostrar información del perro
    dog1.displayInfo(dog1.getColor());

    return 0;
}

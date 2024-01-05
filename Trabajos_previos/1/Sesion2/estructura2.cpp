#include <iostream>
using namespace std;

// Definición de la estructura Person
struct Person {
    char name[50];
    int age;
    float salary;
};

int main() {
    // Creación de una instancia de la estructura Person
    Person p1;

    // Solicitar información al usuario
    cout << "Enter Full name: ";
    cin.get(p1.name, 50);

    cout << "Enter age: ";
    cin >> p1.age;

    cout << "Enter salary: ";
    cin >> p1.salary;

    // Mostrar la información ingresada
    cout << "\nDisplaying Information." << endl;
    cout << "Name: " << p1.name << endl;
    cout << "Age: " << p1.age << endl;
    cout << "Salary: " << p1.salary << endl;

    return 0;
}

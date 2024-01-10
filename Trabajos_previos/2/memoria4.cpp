#include <iostream>
using namespace std;

class Student {
private:
    int age;

public:
    // Constructor que inicializa age en 12
    Student() : age(12) {}

    // Función para obtener la edad
    void getAge() {
        cout << "Age = " << age << endl;
    }
};

int main() {
    // Declarar dinámicamente un objeto de la clase Student
    Student* ptr = new Student();

    // Llamar a la función getAge()
    ptr->getAge();

    // Liberar la memoria asignada dinámicamente
    delete ptr;

    return 0;
}

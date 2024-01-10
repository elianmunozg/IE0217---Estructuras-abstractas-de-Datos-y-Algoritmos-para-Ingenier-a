#include <iostream>
using namespace std;

class Student {
public:
    double marks1;
    double marks2;
};

// Función para crear y configurar un objeto de la clase Student
Student createStudent() {
    // Crear un objeto de la clase Student
    Student student;

    // Asignar valores a las calificaciones del estudiante
    student.marks1 = 96.5;
    student.marks2 = 75.0;

    // Imprimir las calificaciones del estudiante
    cout << "Marks 1: " << student.marks1 << endl;
    cout << "Marks 2: " << student.marks2 << endl;

    // Retornar el objeto creado
    return student;
}

int main() {
    // Crear un objeto de la clase Student utilizando la función createStudent
    Student student1 = createStudent();

    // El objeto student1 ahora tiene calificaciones asignadas
    return 0;
}

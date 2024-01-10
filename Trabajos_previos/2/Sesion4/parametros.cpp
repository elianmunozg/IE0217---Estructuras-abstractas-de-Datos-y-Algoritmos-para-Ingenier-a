#include <iostream>
using namespace std;

class Student {
public:
    double marks;

    // Constructor para inicializar las calificaciones del estudiante
    Student(double m) {
        marks = m;
    }
};

// Función para calcular el promedio de las calificaciones de dos estudiantes
void calculateAverage(Student s1, Student s2) {
    double average = (s1.marks + s2.marks) / 2.0;
    // Imprimir el promedio de las calificaciones
    cout << "Average Marks = " << average << endl;
}

int main() {
    // Crear dos objetos de la clase Student, inicializando las calificaciones
    Student student1(88.0), student2(56.0);

    // Llamar a la función para calcular el promedio y mostrar el resultado
    calculateAverage(student1, student2);

    return 0;
}

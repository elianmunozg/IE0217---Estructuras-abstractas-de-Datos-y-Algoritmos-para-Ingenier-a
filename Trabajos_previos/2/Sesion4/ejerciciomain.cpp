#include <iostream>
#include "ejercicio.hpp"

int main() {
    // Crear dos estudiantes con calificaciones
    Student student1(88.0), student2(56.0);

    // Calcular y mostrar el promedio de las calificaciones
    double average = AverageCalculator::calculateAverage(student1, student2);
    std::cout << "Average Marks: " << average << std::endl;

    return 0;
}

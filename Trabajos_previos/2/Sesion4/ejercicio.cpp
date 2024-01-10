#include "ejercicio.hpp"

// Implementación del constructor de Student
Student::Student(double m) {
    marks = m;
}

// Implementación de la función para calcular el promedio
double AverageCalculator::calculateAverage(Student s1, Student s2) {
    return (s1.marks + s2.marks) / 2;
}

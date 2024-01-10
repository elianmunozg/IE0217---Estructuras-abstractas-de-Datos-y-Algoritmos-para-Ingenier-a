#ifndef EJERCICIO_H
#define EJERCICIO_H

class Student {
public:
    double marks;

    // Constructor
    Student(double m);
};

class AverageCalculator {
public:
    // Función para calcular el promedio
    static double calculateAverage(Student s1, Student s2);
};

#endif // EJERCICIO_H

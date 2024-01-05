#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

#include <iostream>
#include <string>

const int MAX_EMPLEADOS = 10;

struct Empleado {
    int id;
    std::string nombre;
    double salario;
};  // Agrega un punto y coma aquí

void mostrarMenu();
void procesarOpcion(Empleado empleados[], int& numEmpleados);
void agregarEmpleado(Empleado empleados[], int& numEmpleados);  
void listarEmpleado(const Empleado empleados[], int& numEmpleados);
void eliminarEmpleado(Empleado empleados[], int& numEmpleados);

#endif

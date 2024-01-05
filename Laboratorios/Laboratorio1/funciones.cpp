#include "funciones.hpp"
#include <iostream>
#include <string>


void mostrarMenu() {
    std::cout << "\n-- Menu --\n";
    std::cout << "1. Agregar empleados \n";
    std::cout << "2. Listar empleados \n";
    std::cout << "3. Eliminar empleados\n";
    std::cout << "4. Salir\n";
    
}

void procesarOpcion(Empleado empleados[], int& numEmpleados) {
    int opcion;
    std::cout << "Ingrese una opcion:";
    std::cin >> opcion;

    switch (opcion) {
    case 1: // Agregar empleado
        agregarEmpleado(empleados, numEmpleados);
        break;
    case 2: // Lista de empleados
        listarEmpleado(empleados, numEmpleados);
        break;
    case 3: // Eliminar empleado
        eliminarEmpleado(empleados, numEmpleados);
        break;
    case 4: // Salir
        std::cout << "Saliendo del programa...\n";
        exit(0);
    default:
        std::cout << "Opcion no valida. Intente de nuevo...\n";
    }
}


void agregarEmpleado(Empleado empleados[], int& numEmpleados) {
    const int MAX_EMPLEADOS = 100; // Asegúrate de definir MAX_EMPLEADOS adecuadamente

    if (numEmpleados < MAX_EMPLEADOS) {
        Empleado nuevoEmpleado;
        nuevoEmpleado.id = numEmpleados + 1;

        std::cout << "Ingrese el nombre del empleado: ";
        std::cin >> nuevoEmpleado.nombre;

        std::cout << "Ingrese el salario del empleado: ";
        std::cin >> nuevoEmpleado.salario;

        empleados[numEmpleados++] = nuevoEmpleado;

        std::cout << "Empleado agregado con éxito\n";
    } else {
        std::cout << "No se puede agregar más, límite alcanzado.\n";
    }
}

void listarEmpleado(const Empleado empleados[], int& numEmpleados) {
    std::cout << "--- Lista de empleados ---\n";

    for (int i = 0; i < numEmpleados; ++i) {
        std::cout << "ID: " << empleados[i].id << ", Nombre: "
                  << empleados[i].nombre << ", Salario: " << empleados[i].salario << "\n";
    }
}


void eliminarEmpleado(Empleado empleados[], int& numEmpleados) {
    int idEliminar;
    std::cout << "Ingrese el ID a eliminar: ";
    std::cin >> idEliminar;

    for (int i = 0; i < numEmpleados; ++i) {
        if (empleados[i].id == idEliminar) {
            for (int j = i; j < numEmpleados - 1; ++j) {
                empleados[j] = empleados[j + 1];
            }
            --numEmpleados;
            std::cout << "Empleado eliminado con éxito.\n";
            return;
        }
    }

    
}

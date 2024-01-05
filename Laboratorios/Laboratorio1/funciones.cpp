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

void procesarOpcion(){
    int opcion;
    std::cout << "Ingrese una opcion:";
    std::cin >> opcion;

    switch (opcion)
    {
    case 1: //Agregar empleado
        agregarEmpleado();
        break;
    case 2: //Lista de empleados
        listarEmpleado();
        break;
    case 3: //Eliminar empleado
        eliminarEmpleado();
        break;
        
    case 4: //Salir
        std::cout << "Saliendo del programa...\n";
        exit(0);
    default:
        std::cout << "Opcion no valida. Intente de nuevo...\n";



       
    
    
    }
}
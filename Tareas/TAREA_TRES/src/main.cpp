#include "Matriz.hpp"
#include "OperacionCompleja.hpp"
#include "OperacionesBasicas.hpp"
#include <iostream>
#include <complex>

int main() {
    // Crear una instancia de OperacionCompleja para números complejos
    OperacionCompleja<double> operaciones;

    // Crear y configurar la primera matriz de números complejos
    Matriz<std::complex<double>> matriz1;
    std::cout << "Creando la primera matriz de números complejos:" << std::endl;
    matriz1.pedirTamano();
    matriz1.ingresarDatos();

    // Crear y configurar la segunda matriz de números complejos
    Matriz<std::complex<double>> matriz2;
    std::cout << "\nCreando la segunda matriz de números complejos:" << std::endl;
    matriz2.pedirTamano();
    matriz2.ingresarDatos();

    // Realizar y mostrar la multiplicación de las matrices
    try {
        std::cout << "Multiplicando las matrices..." << std::endl;
        operaciones.multiplicarYMostrar(matriz1, matriz2);
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error al multiplicar matrices: " << e.what() << std::endl;
        return 1;
    }
    try {
        // Realizar la resta y mostrar el resultado
        operaciones.restarYMostrar(matriz1, matriz2);
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error en la resta: " << e.what() << std::endl;
    }

    try {
        // Realizar la suma y mostrar el resultado
        operaciones.sumarYMostrar(matriz1, matriz2);
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error en la suma: " << e.what() << std::endl;
    }

    return 0;
}

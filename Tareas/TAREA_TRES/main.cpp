#include "Matriz.hpp"
#include "OperacionCompleja.hpp"
#include <iostream>
#include <complex>

int main() {
    // Crear una instancia de OperacionCompleja
    OperacionCompleja<double> operaciones;

    // Crear la primera matriz
    Matriz<std::complex<double>> matriz1;
    std::cout << "Creando la primera matriz de números complejos:" << std::endl;
    matriz1.pedirTamano();
    matriz1.ingresarDatos();

    // Crear la segunda matriz
    Matriz<std::complex<double>> matriz2;
    std::cout << "\nCreando la segunda matriz de números complejos:" << std::endl;
    matriz2.pedirTamano();
    matriz2.ingresarDatos();

    // Sumar las matrices y mostrar el resultado
    try {
        operaciones.sumarYMostrar(matriz1, matriz2);
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error al sumar matrices: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}

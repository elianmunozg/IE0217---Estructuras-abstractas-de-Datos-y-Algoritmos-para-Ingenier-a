#include "Matriz.hpp"
#include <complex>

int main() {
    try {
        // Crear la primera instancia de Matriz
        Matriz<float> matriz1; 
        matriz1.pedirTamano();
        matriz1.ingresarDatos();

        // Crear la segunda instancia de Matriz
        Matriz<float> matriz2;
        matriz2.pedirTamano();
        matriz2.ingresarDatos();

        // Imprimir ambas matrices
        std::cout << "Matriz 1:" << std::endl;
        matriz1.imprimir();

        std::cout << "Matriz 2:" << std::endl;
        matriz2.imprimir();

        // Aquí puedes realizar operaciones con ambas matrices

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}

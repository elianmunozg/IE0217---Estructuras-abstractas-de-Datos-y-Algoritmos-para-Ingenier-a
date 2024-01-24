#include "Matriz.hpp"
#include "OperacionesBasicas.hpp"

int main() {
    try {
        // Crear y llenar las matrices
        Matriz<float> matriz1;
        matriz1.pedirTamano();
        matriz1.ingresarDatos();

        Matriz<float> matriz2;
        matriz2.pedirTamano();
        matriz2.ingresarDatos();

        // Realizar operaciones
        Matriz<float> suma = OperacionesBasicas<float>::sumar(matriz1, matriz2);
        Matriz<float> resta = OperacionesBasicas<float>::restar(matriz1, matriz2);
        Matriz<float> multiplicacion = OperacionesBasicas<float>::multiplicar(matriz1, matriz2);

        // Imprimir resultados
        std::cout << "Suma:\n";
        suma.imprimir();
        std::cout << "Resta:\n";
        resta.imprimir();
        std::cout << "Multiplicación:\n";
        multiplicacion.imprimir();

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}

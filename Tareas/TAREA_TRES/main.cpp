#include "Matriz.hpp"
#include <iostream>

int main() {
    try {
        // Crear la primera matriz y pedir su tamaño y datos
        Matriz<int> m1;
        std::cout << "Matriz 1:" << std::endl;
        m1.pedirTamano();
        m1.ingresarDatos();

        // Crear la segunda matriz y pedir su tamaño y datos
        Matriz<int> m2;
        std::cout << "\nMatriz 2:" << std::endl;
        m2.pedirTamano();
        m2.ingresarDatos();

        // Crear una matriz para almacenar el resultado
        // Asumimos que las matrices tienen el mismo tamaño
        Matriz<int> resultado(m1.getFilas(), m1.getColumnas());

        // Sumar las matrices
        for (int i = 0; i < m1.getFilas(); ++i) {
            for (int j = 0; j < m1.getColumnas(); ++j) {
                resultado(i, j) = m1(i, j) + m2(i, j);
            }
        }

        // Imprimir el resultado
        std::cout << "\nResultado de la suma:" << std::endl;
        resultado.imprimir();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}

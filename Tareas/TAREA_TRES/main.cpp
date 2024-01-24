#include "Matriz.hpp"
#include "OperacionesBasicas.hpp"
#include <iostream>

int main() {
    try {
        Matriz<int> m1;
        std::cout << "Matriz 1:" << std::endl;
        m1.pedirTamano();
        m1.ingresarDatos();

        Matriz<int> m2;
        std::cout << "\nMatriz 2:" << std::endl;
        m2.pedirTamano();
        m2.ingresarDatos();

        OperacionesBasicas<int>::sumarYMostrar(m1, m2);
        OperacionesBasicas<int>::restarYMostrar(m1, m2);
        OperacionesBasicas<int>::multiplicarYMostrar(m1, m2);

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}

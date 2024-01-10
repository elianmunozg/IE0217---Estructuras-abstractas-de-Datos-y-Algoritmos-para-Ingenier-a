#include <iostream>

// Se almacena en el segmento de datos.
int globalVariable = 42;

int main() {
    // Se almacena en el stack.
    int stackVariable = 10;

    // Se almacena en el heap.
    int* heapVariable = new int(20);

    // Mostrar valores de las variables.
    std::cout << "Valor de globalVariable: " << globalVariable << std::endl;
    std::cout << "Valor de stackVariable: " << stackVariable << std::endl;
    std::cout << "Valor de heapVariable: " << *heapVariable << std::endl;

    // Liberar la memoria asignada en el heap.
    delete heapVariable;

    return 0;
}

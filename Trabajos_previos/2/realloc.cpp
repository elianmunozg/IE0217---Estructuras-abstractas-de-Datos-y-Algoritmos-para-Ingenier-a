#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    // Declarar punteros
    float *ptr, *new_ptr;

    // Asignar memoria para 5 elementos float
    ptr = (float *)malloc(5 * sizeof(float));

    // Verificar si la asignación de memoria fue exitosa
    if (ptr == NULL) {
        cout << "Memory Allocation Failed";
        exit(1);
    }

    // Inicializar el bloque de memoria original
    for (int i = 0; i < 5; i++) {
        ptr[i] = 11.5;
    }

    // Realocar memoria para 10 elementos float
    new_ptr = (float *)realloc(ptr, 10 * sizeof(float));

    // Verificar si la realocación fue exitosa
    if (new_ptr == NULL) {
        cout << "Memory Re-allocation Failed";
        exit(1);
    }

    // Inicializar el bloque de memoria realocado
    for (int i = 5; i < 10; i++) {
        new_ptr[i] = i * 2.5;
    }

    // Imprimir los valores
    cout << "Printing Values" << endl;
    for (int i = 0; i < 10; i++) {
        cout << new_ptr[i] << endl;
    }

    // Liberar la memoria después de su uso
    free(new_ptr);

    return 0;
}

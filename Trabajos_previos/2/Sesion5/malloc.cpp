#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    // allocate memory of int size to an int pointer
    int* ptr = (int*) malloc(sizeof(int));

    // Verificar si la asignación de memoria fue exitosa
    if (ptr == nullptr) {
        cout << "Error: No se pudo asignar memoria." << endl;
        return 1;  // Terminar el programa con código de error
    }

    // asignar el valor 5 a la memoria asignada
    *ptr = 5;

    // imprimir el valor asignado
    cout << *ptr;

    // liberar la memoria asignada
    free(ptr);

    return 0;
}

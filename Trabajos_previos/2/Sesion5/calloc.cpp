#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
    int *ptr;

    // Utiliza el operador de moldeo para asignar el resultado de calloc a ptr
    ptr = (int *)calloc(5, sizeof(int));

    // Verifica si la asignación de memoria fue exitosa
    if (!ptr) {
        cout << "Memory Allocation Failed" << endl;
        exit(1);
    }

    cout << "Initializing values..." << endl << endl;

    for (int i = 0; i < 5; i++) {
        ptr[i] = i * 2 + 1;
    }

    cout << "Initialized values" << endl;

    for (int i = 0; i < 5; i++) {
        // Utiliza ptr[i] o *(ptr+i) de manera intercambiable
        cout << ptr[i] << endl;
    }

    // Liberar la memoria asignada con calloc
    free(ptr);

    return 0;
}

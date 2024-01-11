#include <iostream>
using namespace std;

// Función para intercambiar la posición de dos elementos
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Función para imprimir un array
void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

// Función para realizar el ordenamiento por selección
void selectionSort(int array[], int size) {
    for (int step = 0; step < size - 1; step++) {
        // Encuentra el índice del elemento mínimo en cada iteración
        int min_idx = step;

        for (int i = step + 1; i < size; i++) {
            // Para ordenar en orden descendente, cambia > a < en esta línea
            // Selecciona el elemento mínimo en cada bucle
            if (array[i] < array[min_idx])
                min_idx = i;
        }

        // Coloca el elemento mínimo en la posición correcta
        swap(&array[min_idx], &array[step]);
    }
}

// Código principal
int main() {
    int data[] = {20, 12, 10, 15, 2};
    int size = sizeof(data) / sizeof(data[0]);

    // Llama a la función de ordenamiento por selección
    selectionSort(data, size);

    cout << "Sorted array in Ascending Order: \n";
    // Imprime el array ordenado
    printArray(data, size);

    return 0;
}

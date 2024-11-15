#include <iostream>
using namespace std;

// Función para imprimir un array
void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

// Función para realizar el ordenamiento por inserción
void insertionSort(int array[], int size) {
    for (int step = 1; step < size; step++) {
        int key = array[step];
        int j = step - 1;

        // Compara key con cada elemento a su izquierda hasta encontrar un elemento menor
        // Para ordenar en orden descendente, cambia key < array[j] a key > array[j]
        while (key < array[j] && j >= 0) {
            array[j + 1] = array[j];
            --j;
        }

        array[j + 1] = key;
    }
}

// Código principal
int main() {
    int data[] = {9, 5, 1, 4, 3};
    int size = sizeof(data) / sizeof(data[0]);

    // Llama a la función de ordenamiento por inserción
    insertionSort(data, size);

    cout << "Sorted array in ascending order: \n";
    // Imprime el array ordenado
    printArray(data, size);

    return 0;
}

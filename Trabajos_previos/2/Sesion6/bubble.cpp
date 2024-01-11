#include <iostream>
using namespace std;

// Realizar el ordenamiento de burbuja (Bubble Sort)
void bubbleSort(int array[], int size) {
    // Bucle externo para acceder a cada elemento del array
    for (int step = 0; step < (size - 1); ++step) {
        // Verificar si se produce un intercambio
        int swapped = 0;

        // Bucle interno para comparar dos elementos
        for (int i = 0; i < (size - step - 1); ++i) {
            // Comparar dos elementos del array
            // Cambiar > a < para ordenar en orden descendente
            if (array[i] > array[i + 1]) {
                // Intercambiar elementos si no están en el orden deseado
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                swapped = 1;
            }
        }

        // Si no hay intercambios, significa que el array ya está ordenado
        // No es necesario realizar más comparaciones
        if (swapped == 0)
            break;
    }
}

// Imprimir un array
void printArray(int array[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << array[i] << " ";
    }
    cout << "\n";
}

int main() {
    int data[] = {-2, 45, 0, 11, -9};
    // Encontrar la longitud del array
    int size = sizeof(data) / sizeof(data[0]);

    // Llamar a la función de ordenamiento
    bubbleSort(data, size);

    cout << "Sorted Array in Ascending Order:\n";
    // Imprimir el array ordenado
    printArray(data, size);

    return 0;
}

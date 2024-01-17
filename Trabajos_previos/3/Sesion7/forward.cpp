#include <iostream>     // Biblioteca para operaciones de entrada/salida.
#include <forward_list> // Biblioteca para utilizar el contenedor forward_list.
using namespace std;

int main() {
    // Crea una lista simplemente enlazada con enteros.
    forward_list<int> nums{1, 2, 3, 4};

    // Inicializa un iterador al principio de la lista enlazada.
    forward_list<int>::iterator itr = nums.begin();

    // Recorre la lista enlazada utilizando el iterador.
    while (itr != nums.end()) {
        // Accede al valor actual apuntado por el iterador.
        int original_value = *itr;

        // Asigna un nuevo valor al elemento actual.
        *itr = original_value * 2;

        // Avanza el iterador a la siguiente posición.
        itr++;
    }

    // Muestra el contenido de la lista enlazada.
    for (int num: nums) {
        cout << num << ", ";
    }

    return 0; // Indica que el programa terminó exitosamente.
}

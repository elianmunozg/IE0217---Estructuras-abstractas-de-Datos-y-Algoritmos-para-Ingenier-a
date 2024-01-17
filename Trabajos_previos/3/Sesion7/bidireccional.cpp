#include <iostream> // Incluye la biblioteca estándar de entrada/salida.
#include <list>     // Incluye la biblioteca para usar el contenedor list.
using namespace std;

int main() {
    list<int> nums {1, 2, 3, 4, 5}; // Crea una lista doblemente enlazada con enteros.

    // Inicializa un iterador al principio de la lista.
    list<int>::iterator itr = nums.begin();

    cout << "Moving forward: " << endl;
    // Muestra los elementos de la lista moviéndose hacia adelante.
    while (itr != nums.end()) {
        cout << *itr << ", ";
        itr++; // Mueve el iterador una posición hacia adelante.
    }

    cout << endl << "Moving backward: " << endl;
    // Muestra los elementos de la lista en orden inverso.
    itr = nums.end(); // Coloca el iterador al final de la lista.
    while (itr != nums.begin()) {
        itr--; // Mueve el iterador una posición hacia atrás.
        cout << *itr << ", "; // Debe decrementarse antes de la impresión para evitar el acceso al 'end' no válido.
    }

    cout << *itr << endl; // Imprime el primer elemento de la lista.

    return 0; // Termina el programa con éxito.
}

#include <iostream> // Biblioteca para operaciones de entrada/salida.
#include <vector>   // Biblioteca para utilizar el contenedor vector.
using namespace std;

int main() {
    // Crea un vector que contiene los enteros 1, 2, 3, y 4.
    vector<int> vec{1, 2, 3, 4};

    // Crea un iterador que apunta al primer elemento del vector.
    vector<int>::iterator itr_first = vec.begin();

    // Crea un iterador que apunta al último elemento del vector.
    vector<int>::iterator itr_last = vec.end() - 1;

    // Muestra el primer elemento del vector.
    cout << "First Element: " << *itr_first << endl;

    // Muestra el segundo elemento del vector usando la notación de desplazamiento.
    cout << "Second Element: " << itr_first[1] << endl;

    // Muestra el penúltimo elemento del vector.
    cout << "Second Last Element: " << *(itr_last - 1) << endl;

    // Muestra el último elemento del vector.
    cout << "Last Element: " << *itr_last << endl;

    return 0; // Termina el programa con éxito.
}

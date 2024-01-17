#include <iostream>  // Biblioteca para operaciones de entrada/salida.
#include <vector>    // Biblioteca para utilizar el contenedor vector.
using namespace std;

int main() {
    // Crea un vector que almacena cadenas, inicializado con lenguajes de programación.
    vector<string> languages = {"Python", "C++", "Java"};

    // Crea un iterador para recorrer el vector de cadenas.
    vector<string>::iterator itr;

    // Itera sobre todos los elementos del vector.
    for (itr = languages.begin(); itr != languages.end(); itr++) {
        cout << *itr << ", "; // Accede y muestra el valor actual apuntado por el iterador.
    }

    return 0; // Indica que el programa terminó exitosamente.
}

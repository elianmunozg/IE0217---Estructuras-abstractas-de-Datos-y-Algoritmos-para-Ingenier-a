// Incluye las bibliotecas necesarias para la entrada/salida y para utilizar unordered_set
#include <iostream>
#include <unordered_set>

// Utiliza el espacio de nombres estándar para evitar tener que escribir std:: delante de cada elemento estándar de C++
using namespace std;

// La función principal que se ejecuta al iniciar el programa
int main() {
    // Inicializa un unordered_set de enteros
    // Los unordered_sets almacenan elementos únicos y no garantizan un orden específico
    unordered_set<int> numbers = {1, 100, 10, 70, 100}; // El 100 duplicado se ignorará

    // Imprime el contenido del unordered_set
    // No se garantiza ningún orden particular de los elementos
    cout << "Numbers are: ";
    for(auto &num: numbers) { // Utiliza un bucle for basado en rango para recorrer el unordered_set
        cout << num << ", "; // Imprime cada número seguido de una coma y un espacio
    }

    // La ejecución del programa fue exitosa
    return 0;
}

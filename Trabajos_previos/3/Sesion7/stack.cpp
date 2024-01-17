#include <iostream> // Incluye la biblioteca estándar de entrada/salida
#include <stack>    // Incluye la biblioteca para usar el contenedor de pila (stack)
using namespace std;

int main() {
    // Crea una pila para almacenar enteros
    stack<int> numbers;

    // Agrega elementos a la pila
    numbers.push(1);  // Agrega el número 1 a la pila
    numbers.push(100); // Agrega el número 100 a la pila
    numbers.push(10); // Agrega el número 10 a la pila

    cout << "Numbers are: ";

    // Muestra los elementos de la pila
    // Este bucle continúa hasta que la pila esté vacía
    while(!numbers.empty()) {
        cout << numbers.top() << ", "; // Muestra el elemento superior de la pila
        numbers.pop(); // Elimina el elemento superior de la pila
    }

    return 0; // Termina el programa con éxito
}

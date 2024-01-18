#include <iostream> // Incluye la biblioteca estándar de entrada/salida.

using namespace std;

// Plantilla de función para sumar dos números
// Puede sumar números de cualquier tipo que admita el operador '+'
template <typename T>
T add(T num1, T num2) {
    return (num1 + num2);
}

int main() {
    int result1;    // Almacena el resultado de la suma de enteros
    double result2; // Almacena el resultado de la suma de doubles

    // Llama a la función de plantilla con parámetros enteros
    result1 = add<int>(2, 3);
    cout << "2 + 3 = " << result1 << endl;

    // Llama a la función de plantilla con parámetros double
    result2 = add<double>(2.2, 3.3);
    cout << "2.2 + 3.3 = " << result2 << endl;

    return 0; // Termina el programa con éxito
}

#include <iostream>
#include <stdexcept> // Incluye la definición de std::runtime_error

using namespace std;

int main() {
    int numerador, denominador, resultado;

    cout << "Ingrese el numerador: ";
    cin >> numerador;

    cout << "Ingrese el denominador: ";
    cin >> denominador;

    try {
        // Si el denominador es cero, lanza un error en tiempo de ejecución
        if (denominador == 0) {
            throw runtime_error("Error: el denominador no puede ser cero.");
        }

        // Calcula el resultado si no se lanzó la excepción
        resultado = numerador / denominador;
        cout << "El resultado es: " << resultado << endl;
    } 
    // Captura cualquier excepción que herede de std::exception
    catch (const exception& e) {
        // Imprime el mensaje de error asociado con la excepción
        cerr << e.what() << endl;
    }

    return 0;
}

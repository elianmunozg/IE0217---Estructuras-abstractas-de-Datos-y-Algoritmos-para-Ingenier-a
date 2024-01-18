#include <iostream> // Necesario para la entrada y salida estándar

using namespace std;

int main() {
    double numerator, denominator, divide;

    // Solicita al usuario el numerador
    cout << "Enter numerator: ";
    cin >> numerator;

    // Solicita al usuario el denominador
    cout << "Enter denominator: ";
    cin >> denominator;

    // Bloque try para intentar realizar la división
    try {
        // Lanza una excepción si el denominador es cero
        if (denominator == 0)
            throw 0;

        // Realiza la división si el denominador no es cero
        divide = numerator / denominator;
        
        // Imprime el resultado de la división
        cout << numerator << " / " << denominator << " = " << divide << endl;
    }
    // Bloque catch que maneja la excepción
    catch (int num_exception) {
        // Informa al usuario de que no se puede dividir por cero
        cout << "Error: Cannot divide by " << num_exception << endl;
    }

    return 0; // Termina el programa
}

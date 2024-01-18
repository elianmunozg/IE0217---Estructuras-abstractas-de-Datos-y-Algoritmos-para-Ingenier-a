#include <iostream>
#include <string>

using namespace std;

int main() {
    double numerator, denominator, arr[4] = {0.0, 0.0, 0.0, 0.0};
    int index;

    cout << "Enter array index: ";
    cin >> index;

    try {
        // Lanza una excepción si el índice del arreglo está fuera de los límites
        if (index >= 4)
            throw "Error: Array out of bounds";

        cout << "Enter numerator: ";
        cin >> numerator;

        cout << "Enter denominator: ";
        cin >> denominator;

        // Lanza una excepción si el denominador es cero
        if (denominator == 0)
            throw 0;

        // La división solo se ejecuta si no se ha lanzado ninguna excepción
        arr[index] = numerator / denominator;
        cout << "Result: " << arr[index] << endl;
    }
    // Captura la excepción de índice fuera de los límites
    catch (const char* msg) {
        cout << msg << endl;
    }
    // Captura la excepción de división por cero
    catch (int num) {
        cout << "Error: Cannot divide by " << num << endl;
    }
    // Captura cualquier otra excepción no especificada
    catch (...) {
        cout << "Unexpected exception!" << endl;
    }

    return 0;
}

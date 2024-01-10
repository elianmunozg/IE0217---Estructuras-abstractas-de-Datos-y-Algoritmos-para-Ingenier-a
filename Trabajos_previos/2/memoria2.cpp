#include <iostream>
using namespace std;

int main() {
    // Declarar un puntero a int
    int* pointInt;

    // Declarar un puntero a float
    float* pointFloat;

    // Asignar dinámicamente memoria para un int y un float
    pointInt = new int;
    pointFloat = new float;

    // Asignar valores a la memoria
    *pointInt = 45;
    *pointFloat = 45.45f;

    // Mostrar los valores asignados
    cout << "Valor de pointInt: " << *pointInt << endl;
    cout << "Valor de pointFloat: " << *pointFloat << endl;

    // Liberar la memoria asignada
    delete pointInt;
    delete pointFloat;

    return 0;
}

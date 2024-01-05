#include <iostream>
using namespace std;

// Función con parámetro de tipo float
float absolute(float var) {
    if (var < 0.0)
        var = -var;
    return var;
}

// Función con parámetro de tipo int
int absolute(int var) {
    if (var < 0)
        var = -var;
    return var;
}

int main() {
    // Llamada a la función con parámetro de tipo int
    cout << "Absolute value of -5 = " << absolute(-5) << endl;

    // Llamada a la función con parámetro de tipo float
    cout << "Absolute value of 5.5 = " << absolute(5.5f) << endl;

    return 0;
}

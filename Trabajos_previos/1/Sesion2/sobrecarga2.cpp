#include <iostream>
using namespace std;

// Función con 2 parámetros
void display(int var1, double var2) {
    cout << "Integer number: " << var1;
    cout << " and double number: " << var2 << endl;
}

// Función con parámetro de tipo double
void display(double var) {
    cout << "Double number: " << var << endl;
}

// Función con parámetro de tipo int
void display(int var) {
    cout << "Integer number: " << var << endl;
}

int main() {
    int a = 5;
    double b = 5.5;

    // Llamada a la función con parámetro de tipo int
    display(a);

    // Llamada a la función con parámetro de tipo double
    display(b);

    // Llamada a la función con 2 parámetros
    display(a, b);

    return 0;
}

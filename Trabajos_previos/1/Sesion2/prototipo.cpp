#include <iostream>
using namespace std;

// Declaración de la función (prototipo)
int add(int, int);

int main() {
    int sum;

    // Llamando a la función y almacenando
    // el valor devuelto en 'sum'
    sum = add(100, 78);

    cout << "100 + 78 = " << sum << endl;

    return 0;
}

// Definición de la función
int add(int a, int b) {
    return (a + b);
}

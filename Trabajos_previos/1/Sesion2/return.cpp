#include <iostream>
using namespace std;

// Declarando una función
int add(int a, int b) {
    return (a + b);
}

int main() {
    int sum;

    // Llamando a la función y almacenando
    // el valor devuelto en 'sum'
    sum = add(100, 78);

    cout << "100 + 78 = " << sum << endl;

    return 0;
}

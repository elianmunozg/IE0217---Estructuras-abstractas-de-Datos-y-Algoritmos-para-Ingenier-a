#include <iostream>
using namespace std;

int main() {
    // inicializando una variable double
    double num_double = 3.56;

    cout << "num_double = " << num_double << endl;

    // conversión de estilo C de double a int
    int num_int1 = (int)num_double;
    cout << "num_int1 = " << num_int1 << endl;

    // conversión de estilo de función de double a int
    int num_int2 = int(num_double);
    cout << "num_int2 = " << num_int2 << endl;

    return 0;
}

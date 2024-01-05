#include <iostream>
using namespace std;

int main() {
    // asignando un valor entero a num_int
    int num_int = 9;

    // declarando una variable de tipo double
    double num_double;

    // conversión implícita
    // asignando el valor entero a una variable double
    num_double = num_int;

    cout << "num_int = " << num_int << endl;
    cout << "num_double = " << num_double << endl;

    return 0;
}

#include <iostream> // Incluye la biblioteca para operaciones de entrada/salida.

using namespace std;

// Plantilla de clase con múltiples y valores por defecto para parámetros de plantilla
template <class T, class U, class V = char>
class ClassTemplate {
private:
    T var1; // Variable del primer tipo T
    U var2; // Variable del segundo tipo U
    V var3; // Variable del tercer tipo V con valor por defecto char

public:
    // Constructor que inicializa las variables
    ClassTemplate(T v1, U v2, V v3 = V()) : var1(v1), var2(v2), var3(v3) {}

    // Función para imprimir los valores de las variables
    void printVar() {
        cout << "var1 = " << var1 << endl;
        cout << "var2 = " << var2 << endl;
        cout << "var3 = " << var3 << endl;
    }
};

int main() {
    // Crea un objeto con tipos int, double y char
    ClassTemplate<int, double> obj1(7, 7.7, 'c');
    cout << "obj1 values: " << endl;
    obj1.printVar();

    // Crea un objeto con tipos double, char y bool
    ClassTemplate<double, char, bool> obj2(8.8, 'a', false);
    cout << "obj2 values: " << endl;
    obj2.printVar();

    return 0;
}

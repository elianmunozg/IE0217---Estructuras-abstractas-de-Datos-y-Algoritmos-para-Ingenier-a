#include <iostream>
using namespace std;

class Fraccion {
    int numerador, denominador;

public:
    // Constructor que inicializa la fracción con el numerador y denominador dados
    Fraccion(int n, int d) : numerador(n), denominador(d) {}

    // Sobrecarga del operador + para sumar dos fracciones
    Fraccion operator+ (const Fraccion &f) {
        // Calcula el numerador y denominador del resultado
        Fraccion resultado(
            numerador * f.denominador + f.numerador * denominador,
            denominador * f.denominador
        );
        return resultado;
    }

    // Función para imprimir la fracción
    void imprimir() {
        // Imprime la fracción en formato "numerador/denominador"
        cout << numerador << "/" << denominador << endl;
    }
};

int main() {
    // Crea dos fracciones
    Fraccion f1(1, 2);
    Fraccion f2(3, 4);

    // Suma las dos fracciones
    Fraccion f3 = f1 + f2;

    // Imprime el resultado
    f3.imprimir();

    return 0;
}

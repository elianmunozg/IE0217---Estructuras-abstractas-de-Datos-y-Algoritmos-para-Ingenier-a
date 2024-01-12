#include <iostream>

using namespace std;

// Sección para variables globales
int variableGlobal = 10;

// Sección para la función
void funcionGlobal() {
    // Sección para una variable estática
    static int variableLocalEstatica = 5;

    // Sección para una variable local
    int variableLocal = 20;

    // Mostrar el valor de las variables
    cout << "Variable global: " << variableGlobal << endl;
    cout << "Variable local estática: " << variableLocalEstatica << endl;
    cout << "Variable local: " << variableLocal << endl;
}

int main() {
    // Sección para una variable local en main
    int variableLocalMain = 15;

    // Llamada a una función global
    funcionGlobal();

    // Mostrar el valor de la variable local
    cout << "Variable local en main: " << variableLocalMain << endl;

    // Sección para memoria dinámica
    int* variableDinamica = new int;
    *variableDinamica = 25;

    // Mostrar el valor de la variable dinámica
    cout << "Variable dinamica: " << *variableDinamica << endl;

    // Liberar la memoria dinámica asignada
    delete variableDinamica;

    return 0;
}
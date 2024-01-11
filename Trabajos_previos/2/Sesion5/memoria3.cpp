#include <iostream>
using namespace std;

int main() {
    int num;

    // Solicitar al usuario que ingrese el número total de estudiantes
    cout << "Enter total number of students: ";
    cin >> num;

    // Asignar dinámicamente memoria para num floats
    float* ptr = new float[num];

    // Solicitar al usuario que ingrese las calificaciones de los estudiantes
    cout << "Enter GPA of students." << endl;
    for (int i = 0; i < num; ++i) {
        cout << "Student " << i + 1 << ": ";
        cin >> *(ptr + i);
    }

    // Mostrar las calificaciones de los estudiantes
    cout << "\nDisplaying GPA of students." << endl;
    for (int i = 0; i < num; ++i) {
        cout << "Student " << i + 1 << ": " << *(ptr + i) << endl;
    }

    // Liberar la memoria asignada dinámicamente
    delete[] ptr;

    return 0;
}

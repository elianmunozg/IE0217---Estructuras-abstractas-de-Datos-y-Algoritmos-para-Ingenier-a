#include <iostream> // Biblioteca para operaciones de entrada/salida
#include <map>      // Biblioteca para el contenedor map
using namespace std;

int main() {
    map<int, string> student; // Declara un map de enteros a strings

    // Agrega elementos al map utilizando el operador de indexación
    student[1] = "Jacqueline";
    student[2] = "Blake";

    // Agrega elementos usando el método insert() y make_pair()
    student.insert(make_pair(3, "Denise"));
    student.insert(make_pair(4, "Blake")); // Aquí, Blake tiene una nueva clave (4)

    // Intenta agregar elementos con claves duplicadas
    // Solo se conservará el último valor para la clave duplicada (5)
    student[5] = "Timothy"; // Esta asignación será reemplazada
    student[5] = "Aaron";   // Esta asignación es la que permanecerá

    // Itera y muestra el contenido del map
    // El map solo tendrá elementos únicos para cada clave
    for (int i = 1; i <= student.size(); ++i) {
        cout << "Student[" << i << "]: " << student[i] << endl;
    }

    return 0; // Fin del programa
}

#include "Agenda.hpp"
#include <iostream>

int main() {
    // Objetos de la clase Contacto
    Contacto<std::string> contacto1("Juanito Mora", "27681234", "dj_juanito@gmail.com");
    Contacto<std::string> contacto2("William Walker", "65464654", "Willywalk@gmail.com");
    Contacto<std::string> contacto3("Juan Santamaria", "26666688", "adiosmeson@gmail.com");

    // Crear un objeto de la clase Agenda
    Agenda<std::string> agenda;

    // Agregar contactos a la agenda
    try {
        agenda.agregarContacto(contacto1);
        agenda.agregarContacto(contacto2);
        agenda.agregarContacto(contacto3);
    }
    catch (const std::exception& e) {
        std::cerr << "Error al agregar contacto: " << e.what() << std::endl;
    }

    // Mostrar contactos en la agenda
    std::cout << "Contactos en la agenda: " << std::endl;
    agenda.mostrarContactos();

    // Eliminar un contacto
    try {
        agenda.eliminarContacto("65464654");
    }
    catch (const std::exception& e) {
        std::cerr << "Error al eliminar contacto: " << e.what() << std::endl;
    }

    // Mostrar contactos en la agenda después de eliminar
    std::cout << "Contactos en la agenda después de eliminar: " << std::endl;
    agenda.mostrarContactos();

    // Buscar contactos por un patrón
    std::string patron = "Juan"; // Puedes cambiar este patrón para probar diferentes búsquedas
    std::cout << "Buscando contactos que contienen '" << patron << "': " << std::endl;
    auto resultados = agenda.buscarContactos(patron);
    for (const auto& contacto : resultados) {
        std::cout << "Nombre: " << contacto.getNombre() << " "
                  << "Telefono: " << contacto.getTelefono() << " "
                  << "Email: " << contacto.getEmail() << std::endl;
    }

    return 0;
}

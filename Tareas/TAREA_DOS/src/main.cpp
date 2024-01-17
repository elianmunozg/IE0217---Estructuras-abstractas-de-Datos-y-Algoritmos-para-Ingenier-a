

#include "Libro.hpp"
#include "Noticia.hpp"
#include "Pelicula.hpp"
#include "Podcast.hpp"


#include <iostream>
#include <memory>
#include <vector>
#include <iostream>


int main() {
    // Create instances of Libro
    Libro libro1("Libro 1", "Autor 1", "Editorial 1", "Genero 1", "Estado 1", 300, 19.99, "Resumen 1", {"Material 1", "Material 2"});
    Libro libro2("Libro 2", "Autor 2", "Editorial 2", "Genero 2", "Estado 2", 250, 15.99, "Resumen 2", {"Material 3", "Material 4"});

    // Output information about the books using the imprimirInformacion() method
    std::cout << "Book 1 Information:" << std::endl;
    libro1.imprimirInformacion();

    std::cout << "\nBook 2 Information:" << std::endl;
    libro2.imprimirInformacion();

    return 0;
}

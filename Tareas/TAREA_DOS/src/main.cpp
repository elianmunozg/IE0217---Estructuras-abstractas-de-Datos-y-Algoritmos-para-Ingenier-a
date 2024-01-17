

#include "Libro.hpp"
#include "Noticia.hpp"
#include "Pelicula.hpp"
#include "Podcast.hpp"

#include "MaterialPrecio.hpp"
#include <iostream>
#include <memory>
#include <vector>

int main() {
      // Create instances of Libro
    Libro libro1("Libro 1", "Autor 1", "Editorial 1", "Genero 1", "Estado 1", 300, 19.99, "Resumen 1", {"Material 1", "Material 2"});
    Libro libro2("Libro 2", "Autor 2", "Editorial 2", "Genero 2", "Estado 2", 250, 15.99, "Resumen 2", {"Material 3", "Material 4"});

    // Output information about the books
    std::cout << "Book 1: " << libro1.getTitulo() << ", Author: " << libro1.getAutor() << std::endl;
    std::cout << "Book 2: " << libro2.getTitulo() << ", Author: " << libro2.getAutor() << std::endl;

    return 0;
}

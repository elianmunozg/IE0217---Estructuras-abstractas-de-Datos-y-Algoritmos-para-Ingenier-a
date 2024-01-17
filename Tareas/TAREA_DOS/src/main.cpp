#include <iostream>
#include <memory>
#include "Libro.hpp"
#include "Noticia.hpp"
#include "Pelicula.hpp"
#include "Podcast.hpp"
#include "MaterialOrdenado.hpp"

int main() {
    // Crear objetos de prueba
    std::shared_ptr<Libro> libro1 = std::make_shared<Libro>("Libro 1", "Autor 1", "Editorial 1", "Genero 1", "Disponible", 150, 19.99, "Resumen Libro 1");
    std::shared_ptr<Libro> libro2 = std::make_shared<Libro>("Libro 2", "Autor 2", "Editorial 2", "Genero 2", "Prestado", 220, 29.99, "Resumen Libro 2");

    std::shared_ptr<Noticia> noticia1 = std::make_shared<Noticia>("Noticia 1", "Autor 1", "Genero 1", "Disponible", 3, 0.99, "Resumen Noticia 1");
    std::shared_ptr<Noticia> noticia2 = std::make_shared<Noticia>("Noticia 2", "Autor 2", "Genero 2", "Reservado", 12, 1.99, "Resumen Noticia 2");

    std::shared_ptr<Pelicula> pelicula1 = std::make_shared<Pelicula>("Pelicula 1", "Director 1", "Genero 1", 120, "Disponible", 9.99, "Resumen Pelicula 1", {});
    std::shared_ptr<Pelicula> pelicula2 = std::make_shared<Pelicula>("Pelicula 2", "Director 2", "Genero 2", 180, "Prestado", 14.99, "Resumen Pelicula 2", {});

    std::shared_ptr<Podcast> podcast1 = std::make_shared<Podcast>("Podcast 1", "Presentador 1", "Genero 1", 45, "Disponible", 0.99, "Resumen Podcast 1", {});
    std::shared_ptr<Podcast> podcast2 = std::make_shared<Podcast>("Podcast 2", "Presentador 2", "Genero 2", 120, "Reservado", 1.99, "Resumen Podcast 2", {});

    // Crear un MaterialOrdenado y agregar los objetos de prueba
    MaterialOrdenado biblioteca;

    biblioteca.anadirMaterial(libro1);
    biblioteca.anadirMaterial(libro2);
    biblioteca.anadirMaterial(noticia1);
    biblioteca.anadirMaterial(noticia2);
    biblioteca.anadirMaterial(pelicula1);
    biblioteca.anadirMaterial(pelicula2);
    biblioteca.anadirMaterial(podcast1);
    biblioteca.anadirMaterial(podcast2);

    // Probar las funciones de MaterialOrdenado
    std::cout << "Materiales por título:" << std::endl;
    biblioteca.buscarMaterialPorTitulo("Libro 1");
    biblioteca.buscarMaterialPorTitulo("Pelicula 2");

    std::cout << "\nMateriales por tipo:" << std::endl;
    biblioteca.buscarMaterialPorTipo("libro");
    biblioteca.buscarMaterialPorTipo("pelicula");

    return 0;
}

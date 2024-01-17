#include "MaterialPrecio.hpp"
#include <iostream>
#include <vector>

/**
 * @brief Constructor de la clase MaterialPrecio.
 */
MaterialPrecio::MaterialPrecio(const std::string& titulo, const std::string& grupo, double precio)
    : Libro(titulo, grupo, precio), Noticia(titulo, grupo, precio), Pelicula(titulo, grupo, precio), Podcast(titulo, grupo, precio) {
    // Constructor de MaterialPrecio
}

void MaterialPrecio::ordenarAscendente() {
    bool swapped;
    do {
        swapped = false;
        for (size_t i = 0; i < materiales.size() - 1; i++) {
            if (materiales[i].getPrecio() > materiales[i + 1].getPrecio()) {
                std::swap(materiales[i], materiales[i + 1]);
                swapped = true;
            }
        }
    } while (swapped);
}

void MaterialPrecio::ordenarDescendente() {
    bool swapped;
    do {
        swapped = false;
        for (size_t i = 0; i < materiales.size() - 1; i++) {
            if (materiales[i].getPrecio() < materiales[i + 1].getPrecio()) {
                std::swap(materiales[i], materiales[i + 1]);
                swapped = true;
            }
        }
    } while (swapped);
}


void MaterialPrecio::imprimirMateriales() const {
    std::cout << "Materiales ordenados por precio:" << std::endl;
    for (const auto& material : materiales) {
        std::cout << "Título: " << material.getTitulo() << ", Tipo: " << material.getGrupo() << ", Precio: " << material.getPrecio() << std::endl;
    }
}

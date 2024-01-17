#include "MaterialPrecio.hpp"

/**
 * @brief Constructor de la clase MaterialPrecio.
 */
MaterialPrecio::MaterialPrecio() {}

/**
 * @brief Destructor de la clase MaterialPrecio.
 */
MaterialPrecio::~MaterialPrecio() {}


/**
 * @brief Ordenar materiales por precio utilizando el algoritmo Bubble Sort.
 */
void MaterialPrecio::ordenarPorPrecio() {
    bool swapped;
    do {
        swapped = false;
        for (size_t i = 0; i < materiales.size() - 1; i++) {
            if (materiales[i].precio > materiales[i + 1].precio) {
                std::swap(materiales[i], materiales[i + 1]);
                swapped = true;
            }
        }
    } while (swapped);
}

/**
 * @brief Imprimir los detalles de los materiales ordenados.
 */
void MaterialPrecio::imprimirMateriales() const {
     std::cout << "Materiales de Lectura:" << std::endl;
    for (const auto& material : materialesLectura) {
        std::cout << "Título: " << material->getTitulo() << ", Precio: " << material->getPrecio() << std::endl;
    }

    std::cout << "Materiales Audiovisuales:" << std::endl;
    for (const auto& material : materialesAudiovisuales) {
        std::cout << "Título: " << material->getTitulo() << ", Precio: " << material->getPrecio() << std::endl;
    }
}
void MaterialPrecio::anadirMaterial(const std::string& titulo, const std::string& tipo, double precio) {
    materiales.emplace_back(titulo, tipo, precio);
}

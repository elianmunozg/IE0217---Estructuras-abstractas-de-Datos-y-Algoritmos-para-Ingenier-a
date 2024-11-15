#include "Noticia.hpp"
#include <iostream>
#include <vector>
/**
 * @brief Constructor de la clase Noticia.
 * @param titulo Título de la noticia.
 * @param autor Autor de la noticia.
 * @param editorial Editorial de la noticia.
 * @param genero Género de la noticia.
 * @param estado Estado de disponibilidad de la noticia.
 * @param cantidadHojas Número de hojas de la noticia.
 * @param precio Precio de la noticia.
 * @param resumenContenido Resumen del contenido de la noticia.
 * @param materialRelacionado Lista de materiales relacionados.
 */
Noticia::Noticia(const std::string& titulo, const std::string& autor, const std::string& editorial,
             const std::string& genero, const std::string& estado, int cantidadHojas,
             double precio, const std::string& resumenContenido,
             const std::vector<std::string>& materialRelacionado)
    : MaterialLectura(titulo, autor, editorial, genero, estado, cantidadHojas, precio, resumenContenido, materialRelacionado) {
    
}

/**
 * @brief Determina la longitud de la noticia.
 * @return String que indica si la noticia es corta, mediana o larga.
 */
std::string Noticia::determinarLongitud() const {
    if (cantidadHojas <= 5) return "corta";
    else if (cantidadHojas <= 10) return "mediana";
    return "larga";
}

/**
 * @brief Imprime la información completa de la noticia.
 */
void Noticia::imprimirInformacion() const {
     std::cout << "Titulo: " << getTitulo() << "\nAutor: " << getAutor()
              << "\nEditorial: " << getEditorial() << "\nGenero: " << getGenero()
              << "\nEstado: " << getEstado() << "\nCantidad de Hojas: " << getCantidadHojas()
              << "\nPrecio: " << getPrecio() << "\nResumen: " << resumenContenido << "\nMateriales Relacionados: ";
    for (const auto& material : materialRelacionado) {
        std::cout << material << "; ";
    }
    std::cout << std::endl;
}


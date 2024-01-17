#include "Libro.hpp"
#include <iostream>

/**
 * @brief Constructor de la clase Libro.
 * @param titulo Título del libro.
 * @param autor Autor del libro.
 * @param editorial Editorial del libro.
 * @param genero Género del libro.
 * @param estado Estado de disponibilidad del libro.
 * @param cantidadHojas Número de hojas del libro.
 * @param precio Precio del libro.
 * @param resumenContenido Resumen del contenido del libro.
 * @param materialRelacionado Lista de materiales relacionados.
 */
Libro::Libro(const std::string& titulo, const std::string& autor, 
             const std::string& editorial, const std::string& genero, 
             const std::string& estado, int cantidadHojas, double precio, 
             const std::string& resumenContenido, const std::vector<std::string>& materialRelacionado)
: MaterialLectura(titulo, autor, editorial, genero, estado, cantidadHojas, precio), 
  resumenContenido(resumenContenido), materialRelacionado(materialRelacionado) {}

/**
 * @brief Determina la longitud del libro.
 * @return String que indica si el libro es corto, mediano o largo.
 */
std::string Libro::determinarLongitud() const {
    if (cantidadHojas <= 100) return "corto";
    else if (cantidadHojas <= 200) return "mediano";
    return "largo";
}

/**
 * @brief Imprime la información completa del libro.
 */
void Libro::imprimirInformacion() const {
    std::cout << "Titulo: " << getTitulo() << "\nAutor: " << getAutor()
              << "\nEditorial: " << getEditorial() << "\nGenero: " << getGenero()
              << "\nEstado: " << getEstado() << "\nCantidad de Hojas: " << getCantidadHojas()
              << "\nPrecio: " << getPrecio() << "\nResumen: " << getResumenContenido() << std::endl;

    
}


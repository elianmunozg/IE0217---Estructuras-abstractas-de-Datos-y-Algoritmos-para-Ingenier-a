#include "MaterialLectura.hpp"

/**
 * @brief Constructor de la clase MaterialLectura.
 * @param titulo Título del material de lectura.
 * @param autor Autor del material.
 * @param editorial Editorial del material.
 * @param genero Género del material.
 * @param estado Estado de disponibilidad del material.
 * @param cantidadHojas Número de hojas del material.
 * @param precio Precio del material.
 */
MaterialLectura::MaterialLectura(const std::string& titulo, const std::string& autor, 
                                 const std::string& editorial, const std::string& genero, 
                                 const std::string& estado, int cantidadHojas, double precio) 
: titulo(titulo), autor(autor), editorial(editorial), genero(genero), 
  estado(estado), cantidadHojas(cantidadHojas), precio(precio) {
    this->grupo = "lectura";
}

// Otros métodos comunes a todos los materiales de lectura

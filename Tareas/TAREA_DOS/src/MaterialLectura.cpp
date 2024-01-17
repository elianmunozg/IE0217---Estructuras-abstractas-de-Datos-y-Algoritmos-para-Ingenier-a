#include "MaterialLectura.hpp"

#include <memory>
#include <vector>

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
                                 const std::string& estado, int cantidadHojas, double precio, 
                                 const std::string& resumenContenido, const std::vector<std::string>& materialRelacionado)
: titulo(titulo), autor(autor), editorial(editorial), genero(genero), 
  estado(estado), cantidadHojas(cantidadHojas), precio(precio), 
  resumenContenido(resumenContenido), materialRelacionado(materialRelacionado) {
    grupo = "lectura";
}

// Getters para los atributos protegidos
const std::string& MaterialLectura::getTitulo() const {
    return titulo;
}

const std::string& MaterialLectura::getGrupo() const {
    return grupo;
}



const std::string& MaterialLectura::getAutor() const {
    return autor;
}

const std::string& MaterialLectura::getEditorial() const {
    return editorial;
}

const std::string& MaterialLectura::getGenero() const {
    return genero;
}

const std::string& MaterialLectura::getEstado() const {
    return estado;
}

int MaterialLectura::getCantidadHojas() const {
    return cantidadHojas;
}

double MaterialLectura::getPrecio() const {
    return precio;
}

 const std::string& MaterialLectura::getResumenContenido() const {
    return resumenContenido;
}

const std::vector<std::string>& MaterialLectura::getMaterialRelacionado() const {
    return materialRelacionado;
}

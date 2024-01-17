#include "MaterialAudiovisual.hpp"

#include <vector>
/**
 * @brief Constructor de la clase MaterialAudiovisual.
 * @param titulo Título del material audiovisual.
 * @param autor Autor o creador del material.
 * @param genero Género del material.
 * @param duracion Duración del material en minutos.
 * @param estado Estado de disponibilidad del material.
 * @param precio Precio del material.
 */
MaterialAudiovisual::MaterialAudiovisual(const std::string& titulo, const std::string& autor, 
                                         const std::string& genero, int duracion, 
                                         const std::string& estado, double precio,
                                         const std::string& resumenContenido, 
                                         const std::vector<std::string>& materialRelacionado)
: titulo(titulo), autor(autor), genero(genero), duracion(duracion), estado(estado), precio(precio) {grupo="audiovisual";}


// Getters para los atributos protegidos

const std::string& MaterialAudiovisual::getGrupo() const {
    return grupo;
}


const std::string& MaterialAudiovisual::getTitulo() const {
    return titulo;
}

const std::string& MaterialAudiovisual::getAutor() const {
    return autor;
}

const std::string& MaterialAudiovisual::getGenero() const {
    return genero;
}

int MaterialAudiovisual::getDuracion() const {
    return duracion;
}

const std::string& MaterialAudiovisual::getEstado() const {
    return estado;
}

double MaterialAudiovisual::getPrecio() const {
    return precio;
}
const std::string& MaterialAudiovisual::getResumenContenido() const {
    return resumenContenido;
}

const std::vector<std::string>& MaterialAudiovisual::getMaterialRelacionado() const {
    return materialRelacionado;
}
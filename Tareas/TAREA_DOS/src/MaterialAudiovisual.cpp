#include "MaterialAudiovisual.hpp"

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
                                         const std::string& estado, double precio)
: titulo(titulo), autor(autor), genero(genero), duracion(duracion), estado(estado), precio(precio) {}

// Destructor
MaterialAudiovisual::~MaterialAudiovisual() {
    // Código de limpieza si es necesario
}

// Getters para los atributos protegidos
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

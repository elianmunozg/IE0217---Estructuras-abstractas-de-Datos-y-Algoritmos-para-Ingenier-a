#include "Pelicula.hpp"
#include <iostream>

/**
 * @brief Constructor de la clase Pelicula.
 * @param titulo Título de la película.
 * @param autor Director de la película.
 * @param genero Género de la película.
 * @param duracion Duración de la película en minutos.
 * @param estado Estado de disponibilidad de la película.
 * @param precio Precio de la película.
 * @param resumenContenido Resumen del contenido de la película.
 * @param materialRelacionado Lista de materiales relacionados.
 */
Pelicula::Pelicula(const std::string& titulo, const std::string& autor, 
                   const std::string& genero, int duracion, 
                   const std::string& estado, double precio, 
                   const std::string& resumenContenido, 
                   const std::vector<std::string>& materialRelacionado) 
: MaterialAudiovisual(titulo, autor, genero, duracion, estado, precio), 
  resumenContenido(resumenContenido), materialRelacionado(materialRelacionado) {}

/**
 * @brief Método para determinar la duración de la película.
 * @return Retorna un string que indica si la película es corta, mediana o larga.
 */
  std::string determinarDuracion() const {
        if (getDuracion() >= 0 && getDuracion() <= 90) {
            return "Corta";
        } else if (getDuracion() > 90 && getDuracion() <= 150) {
            return "Mediana";
        } else {
            return "Larga";
        }
    }

/**
 * @brief Método para imprimir la información de la película.
 */
void Pelicula::imprimirInformacion() const {
    std::cout << "Titulo: " << getTitulo() << "\nAutor: " << getAutor()
              << "\nGenero: " << getGenero() << "\nDuracion: " << getDuracion() << " minutos"
              << "\nEstado: " << getEstado() << "\nPrecio: " << getPrecio()
              << "\nResumen: " << getResumenContenido() << "\nMaterial Relacionado:";

   
}

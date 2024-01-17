#ifndef PELICULA_HPP
#define PELICULA_HPP

#include "MaterialAudiovisual.hpp"
#include <string>
#include <vector>

class Pelicula : public MaterialAudiovisual {
private:
    std::string resumenContenido;
    std::string materialRelacionado;

public:
    // Constructor de la clase Pelicula
    Pelicula(const std::string& titulo, const std::string& autor,
             const std::string& genero, int duracion,
             const std::string& estado, double precio,
             const std::string& resumen, const std::string& relacionado)
        : MaterialAudiovisual(titulo, autor, genero, duracion, estado, precio),
          resumenContenido(resumen), materialRelacionado(relacionado) {}


#endif // PELICULA_HPP

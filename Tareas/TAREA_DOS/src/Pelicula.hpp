#ifndef PELICULA_HPP
#define PELICULA_HPP

#include "MaterialAudiovisual.hpp"
#include <string>
#include <vector>

class Pelicula : public MaterialAudiovisual {
private:
    std::string resumenContenido;
    std::vector<std::string> materialRelacionado;

public:
    Pelicula(const std::string& titulo, const std::string& autor, const std::string& genero, int duracion, const std::string& estado, double precio, const std::string& resumenContenido, const std::vector<std::string>& materialRelacionado);
    virtual ~Pelicula() = default;

    std::string determinarDuracion() const; // Método para determinar si la película es corta, mediana o larga
    virtual void imprimirInformacion() const override; // Implementación del método de la clase base

    // Otros métodos específicos para la clase Película
};

#endif // PELICULA_HPP

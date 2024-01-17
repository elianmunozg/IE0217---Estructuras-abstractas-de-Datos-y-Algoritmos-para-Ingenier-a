#ifndef PODCAST_HPP
#define PODCAST_HPP

#include "MaterialAudiovisual.hpp"
#include <string>
#include <vector>

class Podcast : public MaterialAudiovisual {
private:
    std::string resumenContenido;
    std::vector<std::string> materialRelacionado;

public:
    Podcast(const std::string& titulo, const std::string& autor, const std::string& genero, int duracion, const std::string& estado, double precio, const std::string& resumenContenido, const std::vector<std::string>& materialRelacionado);
    virtual ~Podcast() = default;

    std::string determinarDuracion() const; // Método para determinar si el podcast es corto, mediano o largo
    virtual void imprimirInformacion() const override; // Implementación del método de la clase base

    // Otros métodos específicos para la clase Podcast
};

#endif // PODCAST_HPP

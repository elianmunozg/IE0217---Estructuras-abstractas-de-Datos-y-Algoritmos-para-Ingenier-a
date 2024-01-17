#ifndef NOTICIA_HPP
#define NOTICIA_HPP

#include "MaterialLectura.hpp"
#include <string>
#include <vector>

class Noticia : public MaterialLectura {
private:
    std::string resumenContenido;
    std::vector<std::string> materialRelacionado;

public:
    Noticia(const std::string& titulo, const std::string& autor, const std::string& editorial, const std::string& genero, const std::string& estado, int cantidadHojas, double precio, const std::string& resumenContenido, const std::vector<std::string>& materialRelacionado);
    virtual ~Noticia() = default;

    std::string determinarLongitud() const; // Método para determinar si la noticia es corta, mediana o larga
    virtual void imprimirInformacion() const override; // Implementación del método de la clase base

    // Otros métodos específicos para la clase Noticia
};

#endif // NOTICIA_HPP

#ifndef LIBRO_HPP
#define LIBRO_HPP

#include "MaterialLectura.hpp"
#include <string>
#include <vector>

class Libro : public MaterialLectura {
private:
    std::string resumenContenido;
    std::vector<std::string> materialRelacionado;

public:
    Libro(const std::string& titulo, const std::string& autor, const std::string& editorial, const std::string& genero, const std::string& estado, int cantidadHojas, double precio, const std::string& resumenContenido, const std::vector<std::string>& materialRelacionado);
    virtual ~Libro() = default;

    std::string determinarLongitud() const; // Método para determinar si el libro es corto, mediano o largo
    virtual void imprimirInformacion() const override; // Implementación del método de la clase base

    // Otros métodos específicos para la clase Libro
};

#endif // LIBRO_HPP

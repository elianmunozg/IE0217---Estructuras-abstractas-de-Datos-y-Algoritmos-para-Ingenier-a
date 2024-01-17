#ifndef LIBRO_HPP
#define LIBRO_HPP

#include "MaterialLectura.hpp"
#include <string>
#include <vector>
#include <iostream>

class Libro : public MaterialLectura {
protected:
    std::string resumenContenido; // Almacena el resumen del contenido del libro
    std::vector<std::string> materialRelacionado; // Lista de materiales relacionados

public:
    // Constructor
    Libro(const std::string& titulo, const std::string& autor, const std::string& editorial,
          const std::string& genero, const std::string& estado, int cantidadHojas,
          double precio, const std::string& resumenContenido,
          const std::vector<std::string>& materialRelacionado);

    // Destructor virtual por defecto
    virtual ~Libro() = default;

    // Método para determinar la longitud del libro
    std::string determinarLongitud() const;

    // Implementación del método imprimirInformacion de la clase base
    virtual void imprimirInformacion() const override;

    // Posibles métodos adicionales específicos de la clase Libro
};

#endif // LIBRO_HPP

#ifndef MATERIALLECTURA_HPP
#define MATERIALLECTURA_HPP

#include <string>

class MaterialLectura {
protected:
    std::string titulo;
    std::string grupo; // Siempre será "lectura"
    std::string tipoMaterial; // "libro" o "noticia"
    std::string autor;
    std::string editorial;
    std::string genero;
    std::string estado; // "disponible", "prestado", "reservado"
    int cantidadHojas;
    double precio;

public:
    MaterialLectura(const std::string& titulo, const std::string& autor, const std::string& editorial, const std::string& genero, const std::string& estado, int cantidadHojas, double precio);
    virtual ~MaterialLectura() = default;

    virtual void imprimirInformacion() const = 0;
    // Otros métodos y atributos comunes
};

#endif // MATERIALLECTURA_HPP

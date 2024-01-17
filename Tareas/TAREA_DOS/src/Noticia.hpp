#ifndef NOTICIA_HPP
#define NOTICIA_HPP

#include "MaterialLectura.hpp"
#include <string>
#include <vector>


class Noticia : public MaterialLectura {
protected:
    std::string resumenContenido;
    std::vector<std::string> materialRelacionado;

public:
    Noticia(const std::string& titulo, const std::string& autor, 
            const std::string& editorial, const std::string& genero, 
            const std::string& estado, int cantidadHojas, double precio, 
            const std::string& resumenContenido, const std::vector<std::string>& materialRelacionado);

    virtual ~Noticia() = default;

    std::string determinarLongitud() const;
    virtual void imprimirInformacion() const override;
};
#endif // NOTICIA_HPP
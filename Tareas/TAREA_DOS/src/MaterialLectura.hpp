#ifndef MATERIALLECTURA_HPP
#define MATERIALLECTURA_HPP
#include <iostream>
#include <string>
#include <memory>
#include <vector>
class MaterialLectura {
protected:
    std::string titulo;
    std::string grupo; // Siempre será "lectura"
    
    std::string autor;
    std::string editorial;
    std::string genero;
    std::string estado; // "disponible", "prestado", "reservado"
    int cantidadHojas;
    double precio;
    std::string resumenContenido;
    std::vector<std::string> materialRelacionado;

public:
     MaterialLectura(const std::string& titulo, const std::string& autor, const std::string& editorial, 
                    const std::string& genero, const std::string& estado, int cantidadHojas, 
                    double precio, const std::string& resumenContenido, const std::vector<std::string>& materialRelacionado);
 virtual ~MaterialLectura() = default;

    // Getters para los atributos
    const std::string& getTitulo() const;
    const std::string& getGrupo() const;
    
    const std::string& getAutor() const;
    const std::string& getEditorial() const;
    const std::string& getGenero() const;
    const std::string& getEstado() const;
    int getCantidadHojas() const;
    double getPrecio() const;
    const std::string& getResumenContenido() const;
    const std::vector<std::string>& getMaterialRelacionado() const;
   

    virtual void imprimirInformacion() const = 0;
    
};

#endif // MATERIALLECTURA_HPP

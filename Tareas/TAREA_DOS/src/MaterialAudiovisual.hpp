#ifndef MATERIALAUDIOVISUAL_HPP
#define MATERIALAUDIOVISUAL_HPP

#include <string>
#include <iostream>
#include <vector>
class MaterialAudiovisual {
protected:
    std::string titulo;
    std::string grupo; // Siempre será "audiovisual"
    std::string autor;
     
    std::string genero;
    int duracion; // En minutos
    std::string estado; // "disponible", "prestado", "reservado"
    double precio;
    std::string resumenContenido;
    std::vector<std::string> materialRelacionado;

public:
    MaterialAudiovisual(const std::string& titulo, const std::string& autor, const std::string& genero, int duracion, const std::string& estado, double precio);
    virtual ~MaterialAudiovisual() = default;

    virtual void imprimirInformacion() const = 0;
     
     // Getters para los atributos
    const std::string& getTitulo() const;
    const std::string& getGrupo() const;
    
    const std::string& getAutor() const;
    const std::string& getEditorial() const;
    const std::string& getGenero() const;
    const std::string& getEstado() const;
    int getDuracion() const;
    double getPrecio() const;
    const std::string& getResumenContenido() const;
    const std::vector<std::string>& getMaterialRelacionado() const;
   
};

#endif // MATERIALAUDIOVISUAL_HPP

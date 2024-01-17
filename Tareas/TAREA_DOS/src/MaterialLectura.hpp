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

    // Getters para los atributos
    const std::string& getTitulo() const;
    const std::string& getGrupo() const;
    const std::string& getTipoMaterial() const;
    const std::string& getAutor() const;
    const std::string& getEditorial() const;
    const std::string& getGenero() const;
    const std::string& getEstado() const;
    int getCantidadHojas() const;
    double getPrecio() const;

    virtual void imprimirInformacion() const = 0;
    // Otros métodos y atributos comunes
};

#endif // MATERIALLECTURA_HPP

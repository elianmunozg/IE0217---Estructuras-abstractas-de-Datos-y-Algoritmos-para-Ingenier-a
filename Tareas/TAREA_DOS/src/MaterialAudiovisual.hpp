#ifndef MATERIALAUDIOVISUAL_HPP
#define MATERIALAUDIOVISUAL_HPP

#include <string>

class MaterialAudiovisual {
protected:
    std::string titulo;
    std::string grupo; // Siempre será "audiovisual"
    std::string autor;
    std::string tipoMaterial; // "película" o "podcast"
    std::string genero;
    int duracion; // En minutos
    std::string estado; // "disponible", "prestado", "reservado"
    double precio;

public:
    MaterialAudiovisual(const std::string& titulo, const std::string& autor, const std::string& genero, int duracion, const std::string& estado, double precio);
    virtual ~MaterialAudiovisual() = default;

    virtual void imprimirInformacion() const = 0;
    // Otros métodos y atributos comunes
};

#endif // MATERIALAUDIOVISUAL_HPP

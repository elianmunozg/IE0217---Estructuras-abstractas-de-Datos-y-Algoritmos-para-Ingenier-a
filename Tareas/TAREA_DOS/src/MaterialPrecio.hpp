#ifndef MATERIALPRECIO_HPP
#define MATERIALPRECIO_HPP

#include <vector>
#include <memory>
#include "MaterialLectura.hpp"
#include "MaterialAudiovisual.hpp"

/**
 * @brief Clase para ordenar y mostrar materiales por precio.
 */
class MaterialPrecio {
private:
    std::vector<std::shared_ptr<MaterialLectura>> materialesLectura;
    std::vector<std::shared_ptr<MaterialAudiovisual>> materialesAudiovisuales;

public:
    MaterialPrecio();
    ~MaterialPrecio();

    void ordenarPorPrecio(); // Método que emplea Bubble Sort
    void imprimirMateriales() const;
    // Otros métodos relevantes
};

#endif // MATERIALPRECIO_HPP

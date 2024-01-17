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

    void anadirMaterial(const std::shared_ptr<MaterialLectura>& material);
    void anadirMaterial(const std::shared_ptr<MaterialAudiovisual>& material);
    void eliminarMaterial(const std::string& titulo);
    void ordenarPorPrecio(bool ascendente = true);
    void imprimirMateriales() const;
    // Otros métodos relevantes
};

#endif // MATERIALPRECIO_HPP

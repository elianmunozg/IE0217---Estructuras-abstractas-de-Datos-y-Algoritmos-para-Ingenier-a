#ifndef MATERIALORDENADO_HPP
#define MATERIALORDENADO_HPP

#include <vector>
#include <memory>
#include "MaterialLectura.hpp"
#include "MaterialAudiovisual.hpp"

/**
 * @brief Clase para gestionar materiales en la biblioteca virtual.
 */
class MaterialOrdenado {
private:
    std::vector<std::shared_ptr<MaterialLectura>> materialesLectura;
    std::vector<std::shared_ptr<MaterialAudiovisual>> materialesAudiovisuales;

public:
    MaterialOrdenado();
    ~MaterialOrdenado();

    void anadirMaterial(const std::shared_ptr<MaterialLectura>& material);
    void anadirMaterial(const std::shared_ptr<MaterialAudiovisual>& material);
    void eliminarMaterial(const std::string& titulo);
    // Método para buscar material por título o por tipo
    // Otros métodos relevantes
};

#endif // MATERIALORDENADO_HPP

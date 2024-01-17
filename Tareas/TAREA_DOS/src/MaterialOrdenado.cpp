#include "MaterialOrdenado.hpp"
#include <iostream>
/**
 * @brief Constructor de la clase MaterialOrdenado.
 */
MaterialOrdenado::MaterialOrdenado() {}

/**
 * @brief Destructor de la clase MaterialOrdenado.
 */
MaterialOrdenado::~MaterialOrdenado() {}

/**
 * @brief Añadir un material de lectura a la colección.
 * @param material Puntero compartido al material de lectura a añadir.
 */
void MaterialOrdenado::anadirMaterial(MaterialLectura* material) {
    materialesLectura.push_back(material);
}
/**
 * @brief Añadir un material audiovisual a la colección.
 * @param material Puntero compartido al material audiovisual a añadir.
 */
void MaterialOrdenado::anadirMaterial(MaterialAudiovisual* material) {
    materialesAudiovisuales.push_back(material);
}

/**
 * @brief Elimina un material de la colección basado en el título.
 * 
 * Este método elimina materiales tanto de la lista de materiales de lectura como de la lista de materiales audiovisuales.
 * 
 * @param titulo El título del material a eliminar.
 */
void MaterialOrdenado::eliminarMaterial(const std::string& titulo) {
    // Buscar y eliminar el material de lectura si existe
    auto itLectura = std::remove_if(materialesLectura.begin(), materialesLectura.end(),
        [&titulo](MaterialLectura* material) {
            return material->getTitulo() == titulo;
        });
    materialesLectura.erase(itLectura, materialesLectura.end());

    // Buscar y eliminar el material audiovisual si existe
    auto itAudiovisual = std::remove_if(materialesAudiovisuales.begin(), materialesAudiovisuales.end(),
        [&titulo](MaterialAudiovisual* material) {
            return material->getTitulo() == titulo;
        });
    materialesAudiovisuales.erase(itAudiovisual, materialesAudiovisuales.end());
}

/**
 * @brief Busca y muestra la información de materiales por título.
 * 
 * Este método busca en ambas listas de materiales (lectura y audiovisuales) y muestra la información de aquellos que coincidan con el título proporcionado.
 * 
 * @param titulo El título del material a buscar.
 */
void MaterialOrdenado::buscarMaterialPorTitulo(const std::string& titulo) const {
    bool encontrado = false;

    for (const auto& material : materialesLectura) {
        if (material->getTitulo() == titulo) {
            material->imprimirInformacion();
            encontrado = true;
            break; // Terminamos la búsqueda al encontrar el material
        }
    }

    if (!encontrado) {
        for (const auto& material : materialesAudiovisuales) {
            if (material->getTitulo() == titulo) {
                material->imprimirInformacion();
                encontrado = true;
                break; // Terminamos la búsqueda al encontrar el material
            }
        }
    }

    if (!encontrado) {
        std::cout << "Material con título '" << titulo << "' no encontrado." << std::endl;
    }
}
/**
 * @brief Busca y muestra la información de materiales por tipo.
 * 
 * Este método busca en las listas apropiadas de materiales (lectura o audiovisuales) según el tipo especificado y muestra la información de los materiales correspondientes.
 * 
 * @param tipo El tipo de material a buscar (por ejemplo, "libro", "noticia", "pelicula", "podcast").
 */
void MaterialOrdenado::buscarMaterialPorTipo(const std::string& tipo) const {
    bool encontrado = false;

    if (tipo == "libro" || tipo == "noticia") {
        for (const auto& material : materialesLectura) {
            if (material->getTipoMaterial() == tipo) {
                material->imprimirInformacion();
                encontrado = true;
            }
        }
    } else if (tipo == "pelicula" || tipo == "podcast") {
        for (const auto& material : materialesAudiovisuales) {
            if (material->getTipoMaterial() == tipo) {
                material->imprimirInformacion();
                encontrado = true;
            }
        }
    }

    if (!encontrado) {
        std::cout << "No se encontraron materiales del tipo '" << tipo << "'." << std::endl;
    }
}
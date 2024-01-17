#ifndef MATERIALPRECIO_HPP
#define MATERIALPRECIO_HPP

#include <string>
#include <vector>
#include <memory>
#include "Libro.hpp"  // Incluye los encabezados de las clases base
#include "Noticia.hpp"
#include "Pelicula.hpp"
#include "Podcast.hpp"

#include <iostream>

/**
 * @brief Clase para ordenar y mostrar materiales por precio.
 */
class MaterialPrecio : public Libro, public Noticia, public Pelicula, public Podcast {
public:
    MaterialPrecio(const std::string& titulo, const std::string& grupo, double precio);
    
    void ordenarAscendente();
    void ordenarDescendente();
    void imprimirMateriales() const;

private:
    std::vector<MaterialPrecio> materiales;

    // Otros miembros relevantes

};


#endif // MATERIALPRECIO_HPP


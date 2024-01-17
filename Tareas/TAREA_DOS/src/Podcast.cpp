#include "Podcast.hpp"

/**
 * @brief Constructor de la clase Podcast.
 * @param titulo Título del podcast.
 * @param autor Creador del podcast.
 * @param genero Género del podcast.
 * @param duracion Duración del podcast en minutos.
 * @param estado Estado de disponibilidad del podcast.
 * @param precio Precio del podcast.
 * @param resumenContenido Resumen del contenido del podcast.
 * @param materialRelacionado Lista de materiales relacionados.
 */
Podcast::Podcast(const std::string& titulo, const std::string& autor, 
                 const std::string& genero, int duracion, 
                 const std::string& estado, double precio, 
                 const std::string& resumenContenido, 
                 const std::vector<std::string>& materialRelacionado) 
: MaterialAudiovisual(titulo, autor, genero, duracion, estado, precio), 
  resumenContenido(resumenContenido), materialRelacionado(materialRelacionado) {}

/**
 * @brief Método para determinar la duración del podcast.
 * @return Retorna un string que indica si el podcast es corto, mediano o largo.
 */
std::string Podcast::determinarDuracion() const {
    if (duracion <= 30) return "corto";
    else if (duracion <= 90) return "mediano";
    return "largo";
}

void Podcast::imprimirInformacion() const {
    std::cout << "Titulo: " << titulo << "\nCreador: " << autor
              << "\nGénero: " << genero << "\nDuración: " << duracion << " minutos"
              << "\nEstado: " << estado << "\nPrecio: " << precio
              << "\nResumen del Contenido: " << resumenContenido << std::endl;

    // Imprimir los materiales relacionados si los hay
    if (!materialRelacionado.empty()) {
        std::cout << "Materiales Relacionados:" << std::endl;
        for (const auto& material : materialRelacionado) {
            std::cout << " - " << material << std::endl;
        }
    }
}
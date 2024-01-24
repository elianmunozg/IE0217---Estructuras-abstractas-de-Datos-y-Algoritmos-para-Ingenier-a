#include "OperacionesBasicas.hpp"

template <typename T>
void OperacionesBasicas<T>::sumarYMostrar(const Matriz<T>& m1, const Matriz<T>& m2) {
    if (m1.getFilas() != m2.getFilas() || m1.getColumnas() != m2.getColumnas()) {
        throw std::invalid_argument("Las matrices deben tener el mismo tamaño para ser sumadas");
    }

    std::cout << "\nResultado de la suma:" << std::endl;
    for (int i = 0; i < m1.getFilas(); ++i) {
        for (int j = 0; j < m1.getColumnas(); ++j) {
            std::cout << m1(i, j) + m2(i, j) << " ";
        }
        std::cout << std::endl; // Nueva línea al final de cada fila
    }
}

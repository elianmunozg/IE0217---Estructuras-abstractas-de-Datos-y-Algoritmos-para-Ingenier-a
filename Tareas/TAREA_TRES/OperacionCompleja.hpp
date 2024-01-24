#ifndef OPERACIONCOMPLEJA_HPP
#define OPERACIONCOMPLEJA_HPP

#include "Matriz.hpp"
#include <complex>
#include <iostream>
#include <algorithm>  // Para std::transform, std::inner_product

template <typename T>
class OperacionCompleja {
public:
    static void sumarYMostrar(const Matriz<std::complex<T>>& m1, const Matriz<std::complex<T>>& m2);
    static void restarYMostrar(const Matriz<std::complex<T>>& m1, const Matriz<std::complex<T>>& m2);
    static void multiplicar(const Matriz<std::complex<T>>& m1, const Matriz<std::complex<T>>& m2);
};
template <typename T>
void OperacionCompleja<T>::sumarYMostrar(const Matriz<std::complex<T>>& m1, const Matriz<std::complex<T>>& m2) {
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
#endif // OPERACIONCOMPLEJA_HPP

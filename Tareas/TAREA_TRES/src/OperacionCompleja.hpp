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
    static void multiplicarYMostrar(const Matriz<std::complex<T>>& m1, const Matriz<std::complex<T>>& m2);
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

template <typename T>
void OperacionCompleja<T>::restarYMostrar(const Matriz<std::complex<T>>& m1, const Matriz<std::complex<T>>& m2) {
    if (m1.getFilas() != m2.getFilas() || m1.getColumnas() != m2.getColumnas()) {
        throw std::invalid_argument("Las matrices deben tener el mismo tamaño para ser restadas");
    }

    std::cout << "\nResultado de la resta:" << std::endl;
    for (int i = 0; i < m1.getFilas(); ++i) {
        for (int j = 0; j < m1.getColumnas(); ++j) {
            std::cout << m1(i, j) - m2(i, j) << " ";
        }
        std::cout << std::endl; // Nueva línea al final de cada fila
    }
}

template <typename T>
void OperacionCompleja<T>::multiplicarYMostrar(const Matriz<std::complex<T>>& m1, const Matriz<std::complex<T>>& m2) {
    if (m1.getColumnas() != m2.getFilas()) {
        throw std::invalid_argument("El número de columnas de la primera matriz debe ser igual al número de filas de la segunda matriz para multiplicarlas");
    }

    std::cout << "\nResultado de la multiplicación (" << m1.getFilas() << "x" << m2.getColumnas() << "):" << std::endl;
    for (int i = 0; i < m1.getFilas(); ++i) {
        for (int j = 0; j < m2.getColumnas(); ++j) {
            std::complex<T> sum = 0;
            for (int k = 0; k < m1.getColumnas(); ++k) {
                sum += m1(i, k) * m2(k, j);
            }
            std::cout << sum;
            if (j < m2.getColumnas() - 1) {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
}






#endif // OPERACIONCOMPLEJA_HPP

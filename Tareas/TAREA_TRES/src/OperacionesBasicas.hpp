#ifndef OPERACIONESBASICAS_HPP
#define OPERACIONESBASICAS_HPP

#include "Matriz.hpp"
#include <iostream>

template <typename T>
class OperacionesBasicas {
public:
    static void sumarYMostrar(const Matriz<T>& m1, const Matriz<T>& m2);
    static void restarYMostrar(const Matriz<T>& m1, const Matriz<T>& m2);
    static void multiplicarYMostrar(const Matriz<T>& m1, const Matriz<T>& m2);
};

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

template <typename T>
void OperacionesBasicas<T>::restarYMostrar(const Matriz<T>& m1, const Matriz<T>& m2) {
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
void OperacionesBasicas<T>::multiplicarYMostrar(const Matriz<T>& m1, const Matriz<T>& m2) {
    if (m1.getColumnas() != m2.getFilas()) {
        throw std::invalid_argument("El número de columnas de la primera matriz debe ser igual al número de filas de la segunda matriz para multiplicar");
    }

    std::cout << "\nResultado de la multiplicación:" << std::endl;
    for (int i = 0; i < m1.getFilas(); ++i) {
        for (int j = 0; j < m2.getColumnas(); ++j) {
            T sum = T(); // Inicializa sum con el valor por defecto de T
            for (int k = 0; k < m1.getColumnas(); ++k) {
                sum += m1(i, k) * m2(k, j);
            }
            std::cout << sum << " ";
        }
        std::cout << std::endl;
    }
}
#endif // OPERACIONESBASICAS_HPP

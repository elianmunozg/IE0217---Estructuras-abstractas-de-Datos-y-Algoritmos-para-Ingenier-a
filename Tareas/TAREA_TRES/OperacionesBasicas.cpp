// OperacionesBasicas.cpp

#include "OperacionesBasicas.hpp"

template <typename T>
void OperacionesBasicas<T>::validarSumaResta(const Matriz<T>& m1, const Matriz<T>& m2) {
    if (m1.getFilas() != m2.getFilas() || m1.getColumnas() != m2.getColumnas()) {
        throw std::invalid_argument("Las matrices deben tener las mismas dimensiones para la suma o resta.");
    }
}

template <typename T>
void OperacionesBasicas<T>::validarMultiplicacion(const Matriz<T>& m1, const Matriz<T>& m2) {
    if (m1.getColumnas() != m2.getFilas()) {
        throw std::invalid_argument("El número de columnas de la primera matriz debe ser igual al número de filas de la segunda matriz para la multiplicación.");
    }
}


template <typename T>
Matriz<T> OperacionesBasicas<T>::sumar(const Matriz<T>& m1, const Matriz<T>& m2) {
    validarSumaResta(m1, m2);
    Matriz<T> resultado(m1.getFilas(), m1.getColumnas());

    for (int i = 0; i < m1.getFilas(); ++i) {
        for (int j = 0; j < m1.getColumnas(); ++j) {
            resultado(i, j) = m1(i, j) + m2(i, j);
        }
    }
    return resultado;
}


template <typename T>
Matriz<T> OperacionesBasicas<T>::restar(const Matriz<T>& m1, const Matriz<T>& m2) {
    validarSumaResta(m1, m2);
    Matriz<T> resultado(m1.getFilas(), m1.getColumnas());

    for (int i = 0; i < m1.getFilas(); ++i) {
        for (int j = 0; j < m1.getColumnas(); ++j) {
            resultado(i, j) = m1(i, j) - m2(i, j);
        }
    }
    return resultado;
}


template <typename T>
Matriz<T> OperacionesBasicas<T>::multiplicar(const Matriz<T>& m1, const Matriz<T>& m2) {
    validarMultiplicacion(m1, m2);
    Matriz<T> resultado(m1.getFilas(), m2.getColumnas());

    for (int i = 0; i < resultado.getFilas(); ++i) {
        for (int j = 0; j < resultado.getColumnas(); ++j) {
            T sum = 0;
            for (int k = 0; k < m1.getColumnas(); ++k) {
                sum += m1(i, k) * m2(k, j);
            }
            resultado(i, j) = sum;
        }
    }
    return resultado;
}


// Declaraciones explícitas de las plantillas
template class OperacionesBasicas<int>;
template class OperacionesBasicas<float>;
template class OperacionesBasicas<std::complex<float>>;
template class OperacionesBasicas<std::complex<double>>;
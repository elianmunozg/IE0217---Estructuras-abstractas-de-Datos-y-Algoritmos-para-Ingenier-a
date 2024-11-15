// Matriz.hpp

#ifndef MATRIZ_HPP
#define MATRIZ_HPP

#include <vector>
#include <iostream>
#include <complex>
#include <string>
#include <typeinfo>
#include <type_traits>
#include <limits>
#include <stdexcept>

template <typename T>
class Matriz {
public:
    Matriz();
    Matriz(int filas, int columnas);
    void ingresarDatos();
    void imprimir() const;
    void pedirTamano();
    int getFilas() const;
    int getColumnas() const;
    T& operator()(int fila, int columna);
    const T& operator()(int fila, int columna) const;
    Matriz<T> operator+(const Matriz<T>& otra) const;
    


private:
    std::vector<std::vector<T>> data;
    int filas, columnas;

    bool esTipoPermitido();
};
template <typename T>
Matriz<T>::Matriz(int filas, int columnas) : filas(filas), columnas(columnas) {
    
}

template <>
void Matriz<std::complex<float>>::ingresarDatos();

template <>
void Matriz<std::complex<double>>::ingresarDatos();


#endif // MATRIZ_HPP

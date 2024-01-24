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
    


private:
    std::vector<std::vector<T>> data;
    int filas, columnas;

    bool esTipoPermitido();
};



#endif // MATRIZ_HPP

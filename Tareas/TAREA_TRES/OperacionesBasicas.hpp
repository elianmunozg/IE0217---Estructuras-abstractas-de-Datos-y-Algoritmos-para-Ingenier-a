#ifndef OPERACIONESBASICAS_HPP
#define OPERACIONESBASICAS_HPP

#include "Matriz.hpp"
#include <stdexcept>

template <typename T>
class OperacionesBasicas {
public:
    static Matriz<T> sumar(const Matriz<T>& m1, const Matriz<T>& m2);
    static Matriz<T> restar(const Matriz<T>& m1, const Matriz<T>& m2);
    static Matriz<T> multiplicar(const Matriz<T>& m1, const Matriz<T>& m2);

private:
    static void validarSumaResta(const Matriz<T>& m1, const Matriz<T>& m2);
    static void validarMultiplicacion(const Matriz<T>& m1, const Matriz<T>& m2);
};
#include "OperacionesBasicas.cpp"
#endif // OPERACIONESBASICAS_HPP

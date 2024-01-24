// Matriz.cpp

#include "Matriz.hpp"

template <typename T>
Matriz<T>::Matriz() : filas(0), columnas(0) {
    // Constructor por defecto - no hace nada especial
}

template <typename T>
void Matriz<T>::pedirTamano() {
    int tempSize;
    std::cout << "Definir tamaño de la matriz." << std::endl;

    // Pedir número de filas
    while (true) {
        std::cout << "Ingrese el número de filas: ";
        std::cin >> tempSize;
        if (std::cin.fail() || tempSize <= 0) {
            std::cin.clear(); // Limpia el estado de error de cin
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignora la entrada incorrecta
            std::cout << "Número de filas inválido. Por favor intente de nuevo." << std::endl;
        } else {
            filas = tempSize;
            break;
        }
    }

    // Pedir número de columnas
    while (true) {
        std::cout << "Ingrese el número de columnas: ";
        std::cin >> tempSize;
        if (std::cin.fail() || tempSize <= 0) {
            std::cin.clear(); // Limpia el estado de error de cin
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignora la entrada incorrecta
            std::cout << "Número de columnas inválido. Por favor intente de nuevo." << std::endl;
        } else {
            columnas = tempSize;
            break;
        }
    }

    // Redimensionar la matriz para el nuevo tamaño
    data.resize(filas, std::vector<T>(columnas));
}


template <typename T>
void Matriz<T>::ingresarDatos() {
    if (!esTipoPermitido()) {
        throw std::invalid_argument("Tipo de dato no permitido para la matriz");
    }

    std::cout << "Ingrese los elementos de la matriz:" << std::endl;
    T valor;
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            while (true) {
                std::cin >> valor;
                if (std::cin.fail()) {
                    std::cin.clear(); // Limpia el estado de error de cin
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignora la entrada incorrecta
                    std::cout << "Entrada inválida. Por favor ingrese un valor válido para [" << i << "][" << j << "]: ";
                } else {
                    data[i][j] = valor;
                    break;
                }
            }
        }
    }
}

// Especialización para std::complex<float>
template <>
void Matriz<std::complex<float>>::ingresarDatos() {
    std::cout << "Ingrese los elementos de la matriz (parte real e imaginaria):" << std::endl;
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            float valorReal, valorImaginario;
            std::cin >> valorReal >> valorImaginario;
            data[i][j] = std::complex<float>(valorReal, valorImaginario);
        }
    }
}


// Especialización para std::complex<double>
template <>
void Matriz<std::complex<double>>::ingresarDatos() {
    std::cout << "Ingrese los elementos de la matriz (parte real e imaginaria):" << std::endl;
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            double valorReal, valorImaginario;
            std::cin >> valorReal >> valorImaginario;
            data[i][j] = std::complex<double>(valorReal, valorImaginario);
        }
    }
}

template <typename T>
void Matriz<T>::imprimir() const {
    for (const auto& fila : data) {
        for (const auto& elemento : fila) {
            std::cout << elemento << " ";
        }
        std::cout << std::endl;
    }
}

template <typename T>
bool Matriz<T>::esTipoPermitido() {
    return std::is_same<T, int>::value || 
           std::is_same<T, float>::value ||
           std::is_same<T, std::complex<float>>::value ||
           std::is_same<T, std::complex<double>>::value;
}

template <typename T>
int Matriz<T>::getFilas() const {
    return filas;
}

template <typename T>
int Matriz<T>::getColumnas() const {
    return columnas;
}

template <typename T>
T& Matriz<T>::operator()(int fila, int columna) {
    if (fila > filas || columna > columnas || fila < 0 || columna < 0) {
        throw std::out_of_range("Índice fuera de rango");
    }
    return data[fila][columna];
}

template <typename T>
const T& Matriz<T>::operator()(int fila, int columna) const {
    if (fila > filas || columna > columnas || fila < 0 || columna < 0) {
        throw std::out_of_range("Índice fuera de rango");
    }
    return data[fila][columna];
}

template <typename T>
Matriz<T> Matriz<T>::operator+(const Matriz<T>& otra) const {
    if (filas != otra.filas || columnas != otra.columnas) {
        throw std::invalid_argument("Las matrices deben tener el mismo tamaño para sumarlas");
    }

    Matriz<T> resultado(filas, columnas);
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            resultado(i, j) = this->data[i][j] + otra(i, j);
        }
    }
    return resultado;
}
// Declaraciones explícitas de las plantillas
template class Matriz<int>;
template class Matriz<float>;
template class Matriz<std::complex<float>>;
template class Matriz<std::complex<double>>;
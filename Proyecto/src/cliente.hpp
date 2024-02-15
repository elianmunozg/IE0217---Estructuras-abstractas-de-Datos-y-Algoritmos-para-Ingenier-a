#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
#include <map>
#include <string>
#include <stdexcept>
#include <random>

/**
 * @brief Representa un cliente en un sistema bancario, permitiendo gestionar cuentas y préstamos.
 * 
 * @tparam T Tipo de dato utilizado para los números de cuentas y préstamos.
 */
template<typename T>
class Cliente {
public:
    /**
     * @brief Constructor de la clase Cliente.
     * 
     * @param nombre Nombre del cliente.
     * @param identificacion Identificación numérica del cliente, debe tener exactamente 9 dígitos.
     * @throws std::invalid_argument Si la identificación no tiene 9 dígitos.
     */
    Cliente(const std::string& nombre, int identificacion);

    /**
     * @brief Agrega una nueva cuenta al cliente.
     * 
     * @param tipoCuenta El tipo de cuenta a agregar (por ejemplo, "Ahorros").
     */
    void agregarCuenta(const std::string& tipoCuenta);

    /**
     * @brief Agrega un nuevo préstamo al cliente.
     * 
     * @param tipoPrestamo El tipo de préstamo a agregar (por ejemplo, "Hipotecario").
     */
    void agregarPrestamo(const std::string& tipoPrestamo);

    /**
     * @brief Obtiene el número asociado a una cuenta específica.
     * 
     * @param tipoCuenta El tipo de cuenta del cual obtener el número.
     * @return T El número de la cuenta.
     * @throws std::invalid_argument Si el tipo de cuenta no existe.
     */
    T getNumeroCuenta(const std::string& tipoCuenta) const;

    /**
     * @brief Obtiene el número asociado a un préstamo específico.
     * 
     * @param tipoPrestamo El tipo de préstamo del cual obtener el número.
     * @return T El número del préstamo.
     * @throws std::invalid_argument Si el tipo de préstamo no existe.
     */
    T getNumeroPrestamo(const std::string& tipoPrestamo) const;

    /**
     * @brief Obtiene la identificación del cliente.
     * 
     * @return int La identificación del cliente.
     */
    int getId() const { return identificacion_; }

    /**
     * @brief Obtiene el nombre del cliente.
     * 
     * @return std::string El nombre del cliente.
     */
    std::string getNombre() const { return nombre_; }

private:
    int identificacion_; ///< Identificación numérica del cliente.
    std::string nombre_; ///< Nombre del cliente.
    std::map<std::string, T> numerosCuentas_; ///< Mapa de tipos de cuenta a números de cuenta.
    std::map<std::string, T> numerosPrestamos_; ///< Mapa de tipos de préstamo a números de préstamo.

    /**
     * @brief Valida que la identificación tenga exactamente 9 dígitos.
     * 
     * @param identificacion La identificación a validar.
     * @return true Si la identificación es válida.
     * @return false Si la identificación no es válida.
     */
    bool validarIdentificacion(int identificacion) const;

    /**
     * @brief Genera un número aleatorio para ser usado como número de cuenta o préstamo.
     * 
     * @return T Un número aleatorio.
     */
    T generarNumeroAleatorio() const;
};

#endif // CLIENTE_H

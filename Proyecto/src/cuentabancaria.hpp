#ifndef CUENTABANCARIA_HPP
#define CUENTABANCARIA_HPP

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <cmath>

/**
 * @brief Estructura que representa una transacción bancaria.
 * 
 * @tparam T Tipo de dato para el monto de la transacción.
 */
template<typename T>
struct Transaccion {
    std::string tipo;
    T monto;
    std::string fecha;
};

/**
 * @brief Clase que representa una cuenta bancaria.
 * 
 * @tparam T Tipo de dato para el saldo y las transacciones de la cuenta.
 */
template<typename T>
class CuentaBancaria {
private:
    T numeroCuenta;
    std::string tipoCuenta;
    T saldo;
    std::vector<Transaccion<T>> transacciones;

    /**
     * @brief Guarda una transacción en un archivo.
     * 
     * @param transaccion La transacción a guardar.
     */
    void guardarTransaccionEnArchivo(const Transaccion<T>& transaccion) const;

public:
    /**
     * @brief Constructor para crear una nueva cuenta bancaria.
     * 
     * @param numeroCuenta Número de la cuenta bancaria.
     * @param tipoCuenta Tipo de la cuenta bancaria.
     * @param saldoInicial Saldo inicial de la cuenta.
     */
    CuentaBancaria(T numeroCuenta, const std::string& tipoCuenta, T saldoInicial);

    /**
     * @brief Transfiere dinero de esta cuenta a otra cuenta.
     * 
     * @param cuentaDestino La cuenta bancaria destino.
     * @param monto El monto a transferir.
     * @param fecha La fecha de la transferencia.
     * @return true Si la transferencia fue exitosa.
     * @return false Si la transferencia falló (p.ej., saldo insuficiente).
     */
    bool transferir(CuentaBancaria<T>& cuentaDestino, T monto, const std::string& fecha);

    /**
     * @brief Realiza un depósito a plazo en la cuenta.
     * 
     * @param monto El monto del depósito.
     * @param plazoDias El plazo del depósito en días.
     * @param tasaInteres La tasa de interés anual.
     * @param fechaInicio La fecha de inicio del depósito a plazo.
     */
    void depositoAPlazo(T monto, int plazoDias, double tasaInteres, const std::string& fechaInicio);

    /**
     * @brief Deposita dinero en la cuenta.
     * 
     * @param monto El monto a depositar.
     * @param fecha La fecha del depósito.
     */
    void depositar(T monto, const std::string& fecha);

    /**
     * @brief Retira dinero de la cuenta.
     * 
     * @param monto El monto a retirar.
     * @param fecha La fecha del retiro.
     * @return true Si el retiro fue exitoso.
     * @return false Si el retiro falló (p.ej., saldo insuficiente).
     */
    bool retirar(T monto, const std::string& fecha);

    /**
     * @brief Obtiene el saldo actual de la cuenta.
     * 
     * @return T El saldo actual.
     */
    T obtenerSaldo() const;

    /**
     * @brief Obtiene el historial de transacciones de la cuenta.
     * 
     * @return std::vector<Transaccion<T>> El historial de transacciones.
     */
    std::vector<Transaccion<T>> obtenerTransacciones() const;

    /**
     * @brief Obtiene el número de la cuenta bancaria.
     * 
     * @return T El número de la cuenta.
     */
    T obtenerNumeroCuenta() const;
};

#endif // CUENTABANCARIA_HPP
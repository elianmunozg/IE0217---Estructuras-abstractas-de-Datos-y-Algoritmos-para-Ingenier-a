#ifndef CUENTABANCARIA_HPP
#define CUENTABANCARIA_HPP

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <cmath>

/**
 * @struct Transaccion
 * @brief Representa una transacción en la cuenta bancaria.
 * 
 * @tparam T Tipo de dato para el monto de la transacción.
 */
template<typename T>
struct Transaccion {
    std::string tipo; ///< Tipo de transacción (e.g., Depósito, Retiro, Transferencia).
    T monto; ///< Monto de la transacción.
    std::string fecha; ///< Fecha de la transacción.
};

/**
 * @class CuentaBancaria
 * @brief Gestiona una cuenta bancaria, permitiendo depósitos, retiros, transferencias y depósitos a plazo.
 * 
 * @tparam T Tipo de dato para el manejo de montos y saldos.
 */
template<typename T>
class CuentaBancaria {
private:
    T numeroCuenta; ///< Número identificador de la cuenta.
    std::string tipoCuenta; ///< Tipo de la cuenta (e.g., Ahorros, Corriente).
    T saldo; ///< Saldo actual en la cuenta.
    std::vector<Transaccion<T>> transacciones; ///< Historial de transacciones realizadas.

    /**
     * @brief Guarda los detalles de una transacción en un archivo de texto.
     * 
     * @param transaccion La transacción a guardar.
     */
    void guardarTransaccionEnArchivo(const Transaccion<T>& transaccion) const;

public:
    /**
     * @brief Constructor de la clase CuentaBancaria.
     * 
     * @param numeroCuenta Número de la cuenta.
     * @param tipoCuenta Tipo de cuenta.
     * @param saldoInicial Saldo inicial de la cuenta.
     */
    CuentaBancaria(T numeroCuenta, const std::string& tipoCuenta, T saldoInicial);

    /**
     * @brief Realiza una transferencia desde esta cuenta hacia otra cuenta.
     * 
     * @param cuentaDestino Referencia a la cuenta bancaria destino.
     * @param monto Monto a transferir.
     * @param fecha Fecha de la transferencia.
     * @return true si la transferencia fue exitosa, false de lo contrario.
     */
    bool transferir(CuentaBancaria<T>& cuentaDestino, T monto, const std::string& fecha);

    /**
     * @brief Deposita un monto en la cuenta, registrando la transacción.
     * 
     * @param monto Monto a depositar.
     * @param fecha Fecha del depósito.
     */
    void depositar(T monto, const std::string& fecha);

    /**
     * @brief Retira un monto de la cuenta, si el saldo es suficiente.
     * 
     * @param monto Monto a retirar.
     * @param fecha Fecha del retiro.
     * @return true si el retiro fue exitoso, false de lo contrario.
     */
    bool retirar(T monto, const std::string& fecha);

    /**
     * @brief Realiza un depósito a plazo fijo, calculando los intereses y actualizando el saldo al finalizar el plazo.
     * 
     * @param monto Monto del depósito.
     * @param plazoDias Duración del plazo en días.
     * @param tasaInteres Tasa de interés anual.
     * @param fechaInicio Fecha de inicio del plazo.
     */
    void depositoAPlazo(T monto, int plazoDias, double tasaInteres, const std::string& fechaInicio);

    /**
     * @brief Obtiene el saldo actual de la cuenta.
     * 
     * @return Saldo actual de la cuenta.
     */
    T obtenerSaldo() const;

    /**
     * @brief Obtiene el historial de transacciones realizadas en la cuenta.
     * 
     * @return Vector con el historial de transacciones.
     */
    std::vector<Transaccion<T>> obtenerTransacciones() const;

    /**
     * @brief Obtiene el número de la cuenta bancaria.
     * 
     * @return Número de la cuenta.
     */
    T obtenerNumeroCuenta() const;
};

#endif // CUENTABANCARIA_HPP

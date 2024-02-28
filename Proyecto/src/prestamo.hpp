// Prestamo.hpp
#ifndef PRESTAMO_HPP
#define PRESTAMO_HPP

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>
#include <fstream>
#include <map>

/**
 * @brief Clase para representar un préstamo.
 * 
 * La clase Prestamo permite modelar diferentes tipos de préstamos
 * y realizar operaciones relacionadas con los mismos, como el cálculo
 * de la cuota mensual, abonar cuotas, generar reportes y generar
 * tablas de amortización.
 */
class Prestamo {
private:
    std::string idPrestamo; /**< Identificador único del préstamo */
    double montoPrestamo; /**< Monto total del préstamo */
    int cantidadCuotas; /**< Número de cuotas del préstamo */
    double tasaInteres; /**< Tasa de interés anual del préstamo */
    std::string tipoPrestamo; /**< Tipo de préstamo (personalizado, prendario, hipotecario, personal) */
    std::vector<std::pair<double, double>> pagos; /**< Pagos realizados en el préstamo */
    std::map<int, std::vector<double>> tablaAmortizacion; /**< Tabla de amortización del préstamo */


public:
    /**
     * @brief Constructor de la clase Prestamo.
     * @param monto Monto total del préstamo.
     * @param cuotas Número de cuotas del préstamo.
     * @param tasa Tasa de interés anual del préstamo.
     * @param tipo Tipo de préstamo (personalizado, prendario, hipotecario, personal).
     * @param id Identificador único del préstamo.
     */
    Prestamo(double monto, int cuotas, double tasa, std::string tipo, std::string id);

    // Setters
    void establecerMontoPrestamo(double monto);
    void establecerCantidadCuotas(int cuotas);
    void establecerTasaInteres(double tasa);
    void establecerTipoPrestamo(std::string tipo);

    // Getters
    double obtenerMontoPrestamo() const;
    int obtenerCantidadCuotas() const;
    double obtenerTasaInteres() const;
    std::string obtenerTipoPrestamo() const;

    // Métodos para definir tasas preestablecidas
    void configurarTasaPersonal();
    void configurarTasaPrendario();
    void configurarTasaHipotecario();


    /**
     * @brief Calcula la cuota mensual del préstamo.
     * @return Cuota mensual del préstamo.
     */
    // Método para calcular la cuota mensual
    double calcularCuotaMensual() const;

    /**
     * @brief Abona una cuota al préstamo.
     * @param montoAbonado Monto abonado para pagar una cuota del préstamo.
     */
    // Método para abonar cuotas al préstamo
    void abonarCuota(double montoAbonado);

    /**
     * @brief Genera un reporte de los pagos realizados en el préstamo.
     * @param nombreArchivo Nombre del archivo donde se guardará el reporte.
     */
    // Método para generar un reporte de los pagos realizados
    void generarReporte(const std::string& nombreArchivo) const;

    /**
     * @brief Genera una tabla de amortización del préstamo en un archivo .txt.
     * @param nombreArchivo Nombre del archivo donde se guardará la tabla de amortización.
     */
    // Método para escribir la tabla de amortización en un archivo .txt
    void generarTablaAmortizacionTxt(const std::string& nombreArchivo) const;
};

#endif // PRESTAMO_HPP

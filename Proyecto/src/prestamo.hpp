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
class Prestamo {
private:
    std::string idPrestamo;
    double montoPrestamo;
    int cantidadCuotas;
    double tasaInteres;
    std::string tipoPrestamo;
    std::vector<std::pair<double, double>> pagos; // Pares de (capital, intereses)
    std::map<int, std::vector<double>> tablaAmortizacion; // Cuota, [Pago Mensual, Intereses, Capital, Saldo Restante]


public:
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



    // Método para calcular la cuota mensual
    double calcularCuotaMensual() const;

    // Método para abonar cuotas al préstamo
    void abonarCuota(double montoAbonado);

    // Método para generar un reporte de los pagos realizados
    void generarReporte(const std::string& nombreArchivo) const;

    

    // Método para escribir la tabla de amortización en un archivo .txt
    void generarTablaAmortizacionTxt(const std::string& nombreArchivo) const;
};

#endif // PRESTAMO_HPP

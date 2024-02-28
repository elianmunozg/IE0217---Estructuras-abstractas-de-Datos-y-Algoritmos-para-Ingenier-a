/**
 * @file prestamo.hpp
 * @brief Archivo de implementación para la clase Prestamo.
 * 
 * La clase Prestamo permite modelar diferentes tipos de préstamos
 * y realizar operaciones relacionadas con los mismos, como el cálculo
 * de la cuota mensual, abonar cuotas, generar reportes y generar
 * tablas de amortización.
 */
#include "prestamo.hpp"

/**
 * @brief Constructor de la clase Prestamo.
 * 
 * Este constructor inicializa un objeto de la clase Prestamo con los parámetros proporcionados.
 * Calcula la tabla de amortización del préstamo utilizando la fórmula de amortización francesa.
 * 
 * @param monto Monto total del préstamo.
 * @param cuotas Número de cuotas del préstamo.
 * @param tasa Tasa de interés anual del préstamo.
 * @param tipo Tipo de préstamo (personalizado, prendario, hipotecario, personal).
 * @param id Identificador único del préstamo.
 */
Prestamo::Prestamo(double monto, int cuotas, double tasa, std::string tipo, std::string id)
    : montoPrestamo(monto), cantidadCuotas(cuotas), tasaInteres(tasa), tipoPrestamo(tipo), idPrestamo(id){
    // Calcula el pago mensual usando la fórmula de amortización francesa
    double tasaMensual = tasaInteres / 12 / 100;
    double cuotaMensual = (montoPrestamo * tasaMensual) / (1 - pow(1 + tasaMensual, -cantidadCuotas));

    double saldoRestante = montoPrestamo;
    for (int i = 1; i <= cantidadCuotas; ++i) {
        double intereses = saldoRestante * tasaMensual;
        double capital = cuotaMensual - intereses;
        saldoRestante -= capital;

        // Guarda la cuota actual en la tabla de amortización
        tablaAmortizacion[i] = {cuotaMensual, intereses, capital, saldoRestante};
    }
}

/**
 * @brief Establece el monto del préstamo.
 * 
 * @param monto Monto total del préstamo.
 */
void Prestamo::establecerMontoPrestamo(double monto) {
    montoPrestamo = monto;
}

/**
 * @brief Establece la cantidad de cuotas del préstamo.
 * 
 * @param cuotas Número de cuotas del préstamo.
 */
void Prestamo::establecerCantidadCuotas(int cuotas) {
    cantidadCuotas = cuotas;
}

/**
 * @brief Establece la tasa de interés del préstamo.
 * 
 * @param tasa Tasa de interés anual del préstamo.
 */
void Prestamo::establecerTasaInteres(double tasa) {
    tasaInteres = tasa;
}

/**
 * @brief Establece el tipo de préstamo.
 * 
 * @param tipo Tipo de préstamo (personalizado, prendario, hipotecario, personal).
 */
void Prestamo::establecerTipoPrestamo(std::string tipo) {
    tipoPrestamo = tipo;
}

/**
 * @brief Obtiene el monto del préstamo.
 * 
 * @return Monto total del préstamo.
 */
double Prestamo::obtenerMontoPrestamo() const {
    return montoPrestamo;
}

/**
 * @brief Obtiene la cantidad de cuotas del préstamo.
 * 
 * @return Número de cuotas del préstamo.
 */
int Prestamo::obtenerCantidadCuotas() const {
    return cantidadCuotas;
}

/**
 * @brief Obtiene la tasa de interés del préstamo.
 * 
 * @return Tasa de interés anual del préstamo.
 */
double Prestamo::obtenerTasaInteres() const {
    return tasaInteres;
}

/**
 * @brief Obtiene el tipo de préstamo.
 * 
 * @return Tipo de préstamo (personalizado, prendario, hipotecario, personal).
 */
std::string Prestamo::obtenerTipoPrestamo() const {
    return tipoPrestamo;
}

/**
 * @brief Configura la tasa de interés para un préstamo personal.
 * 
 * Esta función establece la tasa de interés preestablecida para un préstamo personal.
 */
void Prestamo::configurarTasaPersonal() {
    tasaInteres = 8.5;
}

/**
 * @brief Configura la tasa de interés para un préstamo prendario.
 * 
 * Esta función establece la tasa de interés preestablecida para un préstamo prendario.
 */
void Prestamo::configurarTasaPrendario() {
    tasaInteres = 10.5;
}

/**
 * @brief Configura la tasa de interés para un préstamo hipotecario.
 * 
 * Esta función establece la tasa de interés preestablecida para un préstamo hipotecario.
 */
void Prestamo::configurarTasaHipotecario() {
    tasaInteres = 6.5;
}

/**
 * @brief Calcula la cuota mensual del préstamo.
 * 
 * @return Cuota mensual del préstamo.
 */
double Prestamo::calcularCuotaMensual() const {
    double tasaMensual = tasaInteres / 12 / 100;
    double cuota = (montoPrestamo * tasaMensual) / (1 - pow(1 + tasaMensual, -cantidadCuotas));
    return cuota;
}

/**
 * @brief Abona una cuota al préstamo.
 * 
 * Esta función abona una cuota al préstamo, reduciendo el saldo restante.
 * 
 * @param montoAbonado Monto abonado para pagar una cuota del préstamo.
 */
void Prestamo::abonarCuota(double montoAbonado) {
    // Asumimos que el pago se realiza en orden y por el monto completo de la cuota.
    if (pagos.size() >= cantidadCuotas) {
        std::cout << "Todas las cuotas ya fueron abonadas." << std::endl;
        return;
    }

    // Encontrar la próxima cuota a pagar
    int cuotaAPagar = pagos.size() + 1;
    auto& detalleCuota = tablaAmortizacion[cuotaAPagar];

    double interes = detalleCuota[1];
    double capital = montoAbonado - interes;

    // Ajustar saldo restante
    detalleCuota[3] -= capital;

    // Registrar el pago
    pagos.push_back({capital, interes});

   
}

/**
 * @brief Genera un reporte de los pagos realizados en el préstamo.
 * 
 * Esta función genera un reporte detallado de los pagos realizados en el préstamo,
 * incluyendo el capital abonado, los intereses pagados y el saldo restante.
 * 
 * @param nombreArchivo Nombre del archivo donde se guardará el reporte.
 */
void Prestamo::generarReporte(const std::string& nombreArchivo) const {
    std::ofstream archivoReporte(nombreArchivo);
    if (!archivoReporte.is_open()) {
        std::cerr << "No se pudo abrir el archivo para escribir el reporte del préstamo." << std::endl;
        return;
    }

    archivoReporte << "Reporte de préstamo para ID: " << idPrestamo << "\n\n";
    archivoReporte << "Detalle de Pagos Realizados:\n";
    archivoReporte << "Cuota\tCapital\tIntereses\tTotal Pagado\n";
    archivoReporte << "--------------------------------------------------\n";

    double totalCapital = 0;
    double totalIntereses = 0;
    int cuotaNum = 1; // Iniciar el contador de cuotas
    for (const auto& pago : pagos) {
        double totalPorCuota = pago.first + pago.second; // Suma de capital e intereses para esta cuota
        archivoReporte << cuotaNum << "\t" // Imprimir el número de cuota
                       << std::fixed << std::setprecision(2) << pago.first << "\t" 
                       << std::fixed << std::setprecision(2) << pago.second << "\t" 
                       << std::fixed << std::setprecision(2) << totalPorCuota << "\n"; // Total pagado en la cuota
        totalCapital += pago.first; // Suma al total del capital
        totalIntereses += pago.second; // Suma al total de intereses
        cuotaNum++; // Incrementar el número de cuota para la siguiente iteración
    }

    // Calcular el saldo restante del préstamo
    double saldoRestante = montoPrestamo - totalCapital;

    // Resumen al final del reporte
    archivoReporte << "\nResumen:\n";
    archivoReporte << "Total pagado hacia el capital: $" << std::fixed << std::setprecision(2) << totalCapital << "\n";
    archivoReporte << "Total pagado en intereses: $" << std::fixed << std::setprecision(2) << totalIntereses << "\n";
    archivoReporte << "Saldo restante del préstamo: $" << std::fixed << std::setprecision(2) << saldoRestante << "\n";

    archivoReporte.close();
}

/**
 * @brief Genera una tabla de amortización del préstamo en un archivo .txt.
 * 
 * Esta función genera una tabla de amortización detallada del préstamo y la guarda en un archivo de texto.
 * La tabla incluye información sobre cada cuota mensual, los intereses, el capital y el saldo restante.
 * 
 * @param nombreArchivo Nombre del archivo donde se guardará la tabla de amortización.
 */
void Prestamo::generarTablaAmortizacionTxt(const std::string& nombreArchivo) const {
    std::ofstream archivoSalida(nombreArchivo);
    if (!archivoSalida.is_open()) {
        std::cerr << "No se pudo abrir el archivo para escribir la tabla de amortización." << std::endl;
        return;
    }

    double cuotaMensual = calcularCuotaMensual();
    double saldo = montoPrestamo;
    double totalInteres = 0;

    archivoSalida << "Cuota\tPago Mensual\tIntereses\tCapital\tSaldo Restante\n";

    for (int i = 1; i <= cantidadCuotas; ++i) {
        double intereses = saldo * (tasaInteres / 12 / 100);
        double capital = cuotaMensual - intereses;
        saldo -= capital;
        totalInteres += intereses;

        archivoSalida << i << "\t"
                      << std::fixed << std::setprecision(2) << cuotaMensual << "\t"
                      << std::fixed << std::setprecision(2) << intereses << "\t"
                      << std::fixed << std::setprecision(2) << capital << "\t"
                      << std::fixed << std::setprecision(2) << saldo << "\n";
    }

    archivoSalida << "Total de intereses pagados: " << std::fixed << std::setprecision(2) << totalInteres << "\n";
    archivoSalida.close();
}
// Prueba de funcionalidad del método generarTablaAmortizacionTxt esta prueba se hizo antes de implementar el atributo id
// Por lo que si se quiere probar se debera agregar a los objetos Prestamo existentes
// int main() {
//     // Crear un préstamo personalizado
//     double monto;
//     int cuotas;
//     double tasa;
//     std::string tipo;

//     std::cout << "Ingrese los detalles para un préstamo personalizado:\n";
//     std::cout << "Monto del préstamo: ";
//     std::cin >> monto;
//     std::cout << "Cantidad de cuotas: ";
//     std::cin >> cuotas;
//     std::cout << "Tasa de interés (anual en %): ";
//     std::cin >> tasa;
//     tipo = "personalizado";

//     Prestamo prestamoPersonalizado(monto, cuotas, tasa, tipo);
//     prestamoPersonalizado.generarTablaAmortizacionTxt("TablaPersonalizado.txt");

//     // Crear un préstamo prendario
//     Prestamo prestamoPrendario(15000, 36, 0, "prendario");
//     prestamoPrendario.configurarTasaPrendario();
//     prestamoPrendario.generarTablaAmortizacionTxt("TablaPrendario.txt");

//     // Crear un préstamo hipotecario
//     Prestamo prestamoHipotecario(200000, 240, 0, "hipotecario");
//     prestamoHipotecario.configurarTasaHipotecario();
//     prestamoHipotecario.generarTablaAmortizacionTxt("TablaHipotecario.txt");

//     // Crear un préstamo personal
//     Prestamo prestamoPersonal(10000, 60, 0, "personal");
//     prestamoPersonal.configurarTasaPersonal();
//     prestamoPersonal.generarTablaAmortizacionTxt("TablaPersonal.txt");

//     std::cout << "Las tablas de amortización han sido generadas.\n";

//     return 0;
// }

// Prueba del método abono
// int main() {
//     // Crear un préstamo hipotecario
//     Prestamo prestamoHipotecario(200000, 240, 6.5, "hipotecario", "HIP123");
//     double cuotaMensual = prestamoHipotecario.calcularCuotaMensual();
    
//     // Simular abonos a las primeras tres cuotas
//     std::cout << "Abonando cuotas..." << std::endl;
//     prestamoHipotecario.abonarCuota(prestamoHipotecario.calcularCuotaMensual());
   
//     prestamoHipotecario.abonarCuota(prestamoHipotecario.calcularCuotaMensual());
    
//     prestamoHipotecario.abonarCuota(prestamoHipotecario.calcularCuotaMensual());
//     std::cout << "La cuota mensual es: $" << std::fixed << std::setprecision(2) << cuotaMensual << std::endl;

//     // Generar y mostrar el reporte de los pagos realizados
//     std::cout << "Generando reporte de préstamo..." << std::endl;
//     prestamoHipotecario.generarReporte("ReportePrestamoHIP123.txt");

//     std::cout << "Reporte generado. Revisa el archivo 'ReportePrestamoHIP123.txt' para ver los detalles." << std::endl;

//     return 0;
// }
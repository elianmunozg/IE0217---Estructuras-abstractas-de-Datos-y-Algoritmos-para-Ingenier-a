/**
 * @file cuentabancaria.hpp
 * @brief Archivo de implementación para la clase CuentaBancaria
 * 
 * La clase CuentaBancaria permite gestionar una cuenta bancaria, permitiendo depósitos,
 * retiros, transferencias y depósitos a plazo.
 */
#include "cuentabancaria.hpp"
#include "cliente.cpp"


/**
 * @brief Constructor que inicializa una cuenta bancaria con un número, tipo y saldo inicial.
 * 
 * @tparam T Tipo de dato para el saldo y las transacciones de la cuenta.
 * @param numeroCuenta Número identificador de la cuenta.
 * @param tipoCuenta Tipo de la cuenta (Ahorros, Corriente, etc.).
 * @param saldoInicial Saldo inicial de la cuenta.
 */
template<typename T>
CuentaBancaria<T>::CuentaBancaria(T numeroCuenta, const std::string& tipoCuenta, T saldoInicial)
    : numeroCuenta(numeroCuenta), tipoCuenta(tipoCuenta), saldo(saldoInicial) {}

/**
 * @brief Deposita un monto en la cuenta bancaria y registra la transacción.
 * 
 * Este método incrementa el saldo de la cuenta bancaria por el monto especificado y registra
 * la transacción en el historial de transacciones de la cuenta. Además, guarda los detalles
 * de la transacción en un archivo de texto asociado con la cuenta bancaria.
 * 
 * @tparam T Tipo de dato numérico para el saldo y las transacciones.
 * @param monto Monto del depósito a realizar.
 * @param fecha Fecha en la que se realiza el depósito, en formato de cadena de texto.
 */
template<typename T>
void CuentaBancaria<T>::depositar(T monto, const std::string& fecha) {
    saldo += monto;
    Transaccion<T> transaccion = {"Depósito", monto, fecha};
    transacciones.push_back(transaccion);
    guardarTransaccionEnArchivo(transaccion); // Actualizado para no usar ID de cliente
}

/**
 * @brief Intenta retirar un monto de la cuenta, verificando primero si el saldo es suficiente.
 * 
 * Este método verifica si el saldo actual de la cuenta es suficiente para realizar el retiro. 
 * Si el saldo es suficiente, reduce el saldo de la cuenta por el monto especificado y registra 
 * la transacción en el historial de transacciones de la cuenta. La transacción también se guarda
 * en un archivo de texto asociado con la cuenta bancaria, detallando el tipo de transacción, 
 * el monto y la fecha. Si el saldo no es suficiente para cubrir el retiro, la operación es rechazada
 * y no se modifica el saldo ni se registra la transacción.
 * 
 * @tparam T Tipo de dato numérico para el saldo y las transacciones de la cuenta.
 * @param monto Monto que se desea retirar de la cuenta.
 * @param fecha Fecha en la que se realiza el retiro, en formato de cadena de texto.
 * @return true si el retiro fue exitoso y el saldo suficiente; false si el saldo es insuficiente.
 */
template<typename T>
bool CuentaBancaria<T>::retirar(T monto, const std::string& fecha) {
    if (monto > saldo) {
        return false;
    } else {
        saldo -= monto;
        transacciones.push_back(Transaccion<T>{"Retiro", monto, fecha});
        Transaccion<T> transaccion = {"Retiro", monto, fecha};
        guardarTransaccionEnArchivo(transaccion); 

        return true;
    }
}

/**
 * @brief Realiza una transferencia de fondos de esta cuenta a otra cuenta especificada.
 * 
 * Este método facilita la transferencia de un monto específico de dinero de la cuenta actual a
 * otra cuenta bancaria. La operación se divide en dos pasos principales: primero, intenta retirar
 * el monto especificado de la cuenta actual. Si el retiro es exitoso, el monto se deposita en la
 * cuenta de destino. La transacción se registra en ambos, la cuenta de origen y la cuenta destino,
 * indicando respectivamente "Transferencia Enviada" y "Transferencia Recibida", junto con los detalles
 * del monto y la fecha de la transacción. Se garantiza que ambas acciones, el retiro y el depósito,
 * se ejecuten para completar la transferencia. Si el saldo de la cuenta de origen es insuficiente,
 * la transferencia no se realiza y la función retorna `false`.
 * 
 * @tparam T Tipo de dato numérico para el saldo y las transacciones.
 * @param cuentaDestino Referencia a la cuenta bancaria que recibirá el monto transferido.
 * @param monto El monto de dinero a transferir.
 * @param fecha La fecha en la que se realiza la transferencia, en formato de cadena de texto.
 * @return true si tanto el retiro como el depósito se realizan con éxito, false si el saldo
 * de la cuenta de origen es insuficiente para realizar la transferencia.
 */
template<typename T>
bool CuentaBancaria<T>::transferir(CuentaBancaria<T>& cuentaDestino, T monto, const std::string& fecha) {
    if (this->retirar(monto, fecha)) { // Intenta retirar de la cuenta actual
        cuentaDestino.depositar(monto, fecha); // Deposita en la cuenta destino

        // Registra la transacción de transferencia en la cuenta origen
        Transaccion<T> transaccionOrigen = {"Transferencia Enviada", monto, fecha};
        this->guardarTransaccionEnArchivo(transaccionOrigen);

        // Registra la transacción de transferencia en la cuenta destino
        Transaccion<T> transaccionDestino = {"Transferencia Recibida", monto, fecha};
        cuentaDestino.guardarTransaccionEnArchivo(transaccionDestino);

        return true;
    } else {
        return false; // No se pudo realizar la transferencia por falta de fondos
    }
}

/**
 * @brief Realiza un depósito a plazo, añadiendo intereses al saldo final basado en la tasa proporcionada.
 * 
 * Este método permite al titular de la cuenta realizar un depósito a plazo fijo, el cual es una inversión
 * que permanece en la cuenta por un período específico de días. Los intereses generados durante este plazo
 * se calculan al final del mismo y se suman al saldo total de la cuenta. La transacción, incluyendo el monto
 * inicial del depósito más los intereses acumulados, se registra en el historial de transacciones de la cuenta.
 * Además, se guarda un registro de esta operación en un archivo de texto asociado con la cuenta, detallando
 * el tipo de transacción, el monto total acreditado y la fecha de inicio del depósito a plazo.
 * 
 * El cálculo de intereses se realiza mediante una fórmula de interés simple, basada en la tasa de interés anual
 * proporcionada, la cantidad del depósito y la duración del depósito en días. Este método asume que la tasa de
 * interés es una tasa anual y ajusta el cálculo de intereses al período específico del depósito.
 * 
 * @tparam T Tipo de dato numérico para manejar el saldo y las transacciones, permitiendo flexibilidad en el
 * manejo de diferentes tipos numéricos (por ejemplo, int, float, double).
 * @param monto El monto del depósito inicial que el titular de la cuenta desea colocar a plazo fijo.
 * @param plazoDias La duración del depósito a plazo, expresada en días, determinando el período durante el
 * cual el monto depositado generará intereses.
 * @param tasaInteres La tasa de interés anual aplicada al monto depositado para calcular los intereses
 * generados durante el plazo del depósito.
 * @param fechaInicio La fecha en la que se inicia el depósito a plazo, utilizada para registrar la transacción
 * y calcular el período de generación de intereses.
 */
template<typename T>
void CuentaBancaria<T>::depositoAPlazo(T monto, int plazoDias, double tasaInteres, const std::string& fechaInicio) {
    // Calcular interés simple o compuesto según la necesidad
    double interes = monto * (tasaInteres / 365) * plazoDias; // Interés simple 

    // El interés se añade al final del plazo
    T total = monto + interes;

    // Actualiza el saldo
    saldo += total;

    // Registra la transacción
    Transaccion<T> transaccion = {"Depósito a Plazo", total, fechaInicio};
    guardarTransaccionEnArchivo(transaccion);
}

/**
 * @brief Abona una cuota de préstamo a la cuenta, restando del saldo y registrando la transacción.
 * 
 * Este método intenta realizar un abono a la cuota de un préstamo específico, disminuyendo el saldo de la cuenta
 * por el monto especificado. Si el saldo es suficiente para cubrir el abono, se registra la transacción
 * como un "Abono Préstamo", incluyendo el número del préstamo en la descripción. La transacción se guarda
 * tanto en el historial interno de transacciones de la cuenta como en un archivo de texto para su registro.
 * En caso de no contar con fondos suficientes, se muestra un mensaje de error y no se realiza el abono.
 * 
 * @param monto Monto de la cuota del préstamo a abonar.
 * @param numeroPrestamo Número identificador del préstamo al cual se está abonando.
 * @param fecha Fecha en la que se realiza el abono.
 * 
 * @return void No retorna ningún valor. Sin embargo, modifica el saldo de la cuenta y actualiza el historial de transacciones.
 */
template<typename T>
void CuentaBancaria<T>::abonarCuotaPrestamo(T monto, T numeroPrestamo, const std::string& fecha) {
    // Utiliza el método retirar para disminuir el saldo de la cuenta
    if (this->retirar(monto, fecha)) {
        // Registra la transacción específica de abono a cuota de préstamo
        // Nota: La transacción de retiro ya fue registrada por el método retirar, así que aquí solo registramos el propósito específico del retiro
        Transaccion<T> transaccionAbono = {"Abono Préstamo " + std::to_string(numeroPrestamo), monto, fecha};
        this->guardarTransaccionEnArchivo(transaccionAbono);
    } else {
        // Opcional: Manejar el caso de no poder realizar el abono por falta de fondos
        std::cerr << "No se pudo realizar el abono a la cuota del préstamo por falta de fondos." << std::endl;
    }
}


/**
 * @brief Obtiene el saldo actual de la cuenta.
 * 
 * @tparam T Tipo de dato numérico para el saldo.
 * @return T Saldo actual de la cuenta.
 */
template<typename T>
T CuentaBancaria<T>::obtenerSaldo() const {
    return saldo;
}

/**
 * @brief Obtiene un vector con todas las transacciones realizadas en la cuenta.
 * 
 * @tparam T Tipo de dato numérico para el monto de las transacciones.
 * @return std::vector<Transaccion<T>> Vector que contiene todas las transacciones realizadas.
 */
template<typename T>
std::vector<Transaccion<T>> CuentaBancaria<T>::obtenerTransacciones() const {
    return transacciones;
}

/**
 * @brief Obtiene el número de cuenta bancaria.
 * 
 * @tparam T Tipo de dato numérico utilizado para el número de cuenta.
 * @return T Número de la cuenta bancaria.
 */
template<typename T>
T CuentaBancaria<T>::obtenerNumeroCuenta() const {
    return numeroCuenta;
}

/**
 * @brief Guarda los detalles de una transacción en un archivo de texto asociado con el número de cuenta.
 * 
 * Este método es responsable de persistir los detalles de cada transacción realizada (depósitos, retiros,
 * transferencias o deposito a plazo.) en un archivo de texto. El archivo está nombrado de manera única para cada cuenta
 * bancaria usando el número de cuenta como parte del nombre del archivo, asegurando que las transacciones
 * de diferentes cuentas se mantengan separadas. Cada entrada en el archivo incluye el tipo de transacción,
 * el monto y la fecha, separados por comas, siguiendo el formato CSV (Valores Separados por Comas) para
 * facilitar su lectura y análisis. Si por alguna razón el archivo no puede ser abierto o creado, se muestra
 * un mensaje de error en la salida estándar de errores, pero el error no se propaga más allá de eso.
 * 
 * @tparam T Tipo de dato numérico para el monto de la transacción, asegurando que el método pueda manejar
 * tanto enteros como flotantes dependiendo de cómo se configure la clase CuentaBancaria.
 * @param transaccion Referencia constante a la instancia de Transaccion<T> que contiene los detalles de
 * la transacción a ser guardada. Esto incluye el tipo de transacción, el monto y la fecha en que se realizó.
 */
template<typename T>
void CuentaBancaria<T>::guardarTransaccionEnArchivo(const Transaccion<T>& transaccion) const {
    std::string nombreArchivo = "transacciones_" + std::to_string(numeroCuenta) + ".txt";
    std::ofstream archivo(nombreArchivo, std::ios::app); // Abre el archivo en modo append
    if (archivo.is_open()) {
        archivo << transaccion.tipo << "," << transaccion.monto << "," << transaccion.fecha << std::endl;
        archivo.close();
    } else {
        std::cerr << "No se pudo abrir el archivo " << nombreArchivo << " para escribir." << std::endl;
    }
}

// Verificación de funcionamiento de guardado de datos de las transacciones en el txt(depositar y retirar)
// Y del funcionamiento del método obtener transacciones
// int main() {
//     // Crear un cliente
//     Cliente<int> cliente("Juan Pérez", 123456789);
    
//     // Agregar una cuenta de ahorros con un saldo inicial (suponiendo que esto también crea la cuenta)
//     cliente.agregarCuenta("Ahorros");
    
//     // Se obtiene el numero de cuenta de cliente
//     int numeroCuentaAhorros = cliente.getNumeroCuenta("Ahorros");
    
//     // Crear una cuenta bancaria con el número de cuenta generado
//     CuentaBancaria<int> cuentaAhorros(numeroCuentaAhorros, "Ahorros", 1000);
    
//     // Realizar operaciones
//     cuentaAhorros.depositar(500, "2023-01-01");
//     bool exitoRetiro = cuentaAhorros.retirar(200, "2023-01-02");
    
//     // Mostrar información actualizada
//     std::cout << "Saldo después de transacciones: " << cuentaAhorros.obtenerSaldo() << std::endl;

//     // Obtener y mostrar las transacciones
//     auto transacciones = cuentaAhorros.obtenerTransacciones();
//     std::cout << "Transacciones realizadas:" << std::endl;
//     for (const auto& transaccion : transacciones) {
//         std::cout << "Tipo: " << transaccion.tipo << ", Monto: $" << transaccion.monto << ", Fecha: " << transaccion.fecha << std::endl;
//     }

//     return 0;
// }


//Verificación de funcionamiento del método transferencia
// int main() {
//     // Creación de dos cuentas bancarias con número de cuenta, tipo de cuenta y saldo inicial
//     CuentaBancaria<double> cuentaOrigen(123456, "Ahorro", 1000.0);
//     CuentaBancaria<double> cuentaDestino(654321, "Corriente", 500.0);

//     // Muestra el saldo inicial de ambas cuentas
//     std::cout << "Saldo inicial cuenta origen: " << cuentaOrigen.obtenerSaldo() << std::endl;
//     std::cout << "Saldo inicial cuenta destino: " << cuentaDestino.obtenerSaldo() << std::endl;

//     // Realiza una transferencia de la cuenta origen a la cuenta destino
//     double montoTransferencia = 200.0;
//     if (cuentaOrigen.transferir(cuentaDestino, montoTransferencia, "2024-02-18")) {
//         std::cout << "Transferencia realizada con éxito." << std::endl;
//     } else {
//         std::cout << "La transferencia no se pudo realizar." << std::endl;
//     }

//     // Muestra el saldo final de ambas cuentas después de la transferencia
//     std::cout << "Saldo final cuenta origen: " << cuentaOrigen.obtenerSaldo() << std::endl;
//     std::cout << "Saldo final cuenta destino: " << cuentaDestino.obtenerSaldo() << std::endl;
//     // Obtener y mostrar las transacciones
//     auto transacciones = cuentaDestino.obtenerTransacciones();
//     std::cout << "Transacciones realizadas:" << std::endl;
//     for (const auto& transaccion : transacciones) {
//         std::cout << "Tipo: " << transaccion.tipo << ", Monto: $" << transaccion.monto << ", Fecha: " << transaccion.fecha << std::endl;
//     }


//     return 0;
// }


// //Prueba del metodo deposito a plazo
// int main() {
//     // Creación de una cuenta bancaria con número de cuenta, tipo de cuenta y saldo inicial
//     CuentaBancaria<double> cuenta(123456, "Colones", 1000.0);

//     // Muestra el saldo inicial de la cuenta
//     std::cout << "Saldo inicial: " << cuenta.obtenerSaldo() << std::endl;

//     // Realiza un depósito a plazo
//     double montoDeposito = 500.0; // Monto del depósito
//     int plazoDias = 30; // Plazo del depósito en días
//     double tasaInteres = 0.05; // Tasa de interés anual
//     cuenta.depositoAPlazo(montoDeposito, plazoDias, tasaInteres, "2024-02-18");

//     // Muestra el saldo final de la cuenta después del depósito a plazo
//     std::cout << "Saldo final después del depósito a plazo: " << cuenta.obtenerSaldo() << std::endl;
    
//     return 0;
// }

// //Comprobación de funcionamiento del metodo abonar prestamo
// int main() {
//     // Creación de la cuenta bancaria desde la que se abonará la cuota del préstamo
//     CuentaBancaria<double> cuentaOrigen(123456789, "Ahorros", 10000.0);

//     // Creación de otra cuenta bancaria para demostración (opcional para este ejemplo)
//     CuentaBancaria<double> cuentaDestino(987654321, "Corriente", 5000.0);

//     // Monto de la cuota del préstamo a abonar
//     double montoCuotaPrestamo = 1500.0;
//     // Número de préstamo
//     double numeroPrestamo = 11223344;
//     // Fecha del abono
//     std::string fecha = "2023-02-15";

//     // Realizando el abono a la cuota del préstamo
//     std::cout << "Abonando cuota de préstamo...\n";
//     cuentaOrigen.abonarCuotaPrestamo(montoCuotaPrestamo, numeroPrestamo, fecha);

//     // Verificando el saldo después del abono
//     std::cout << "Saldo después del abono: $" << cuentaOrigen.obtenerSaldo() << std::endl;

//     // Imprimiendo el historial de transacciones
//     std::cout << "Historial de transacciones:\n";
//     auto transacciones = cuentaOrigen.obtenerTransacciones();
//     for (const auto& transaccion : transacciones) {
//         std::cout << transaccion.tipo << " - Monto: $" << transaccion.monto << " - Fecha: " << transaccion.fecha << std::endl;
//     }

//     return 0;
// }
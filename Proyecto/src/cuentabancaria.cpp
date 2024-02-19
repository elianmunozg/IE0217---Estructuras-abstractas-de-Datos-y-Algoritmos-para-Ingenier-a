#include "cuentabancaria.hpp"
#include "cliente.cpp"



template<typename T>
CuentaBancaria<T>::CuentaBancaria(T numeroCuenta, const std::string& tipoCuenta, T saldoInicial)
    : numeroCuenta(numeroCuenta), tipoCuenta(tipoCuenta), saldo(saldoInicial) {}

template<typename T>
void CuentaBancaria<T>::depositar(T monto, const std::string& fecha) {
    saldo += monto;
    Transaccion<T> transaccion = {"Depósito", monto, fecha};
    transacciones.push_back(transaccion);
    guardarTransaccionEnArchivo(transaccion); // Actualizado para no usar ID de cliente
}


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

template<typename T>
T CuentaBancaria<T>::obtenerSaldo() const {
    return saldo;
}

template<typename T>
std::vector<Transaccion<T>> CuentaBancaria<T>::obtenerTransacciones() const {
    return transacciones;
}

template<typename T>
T CuentaBancaria<T>::obtenerNumeroCuenta() const {
    return numeroCuenta;
}
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
int main() {
    // Crear un cliente
    Cliente<int> cliente("Juan Pérez", 123456789);
    
    // Agregar una cuenta de ahorros con un saldo inicial (suponiendo que esto también crea la cuenta)
    cliente.agregarCuenta("Ahorros");
    
    // Se obtiene el numero de cuenta de cliente
    int numeroCuentaAhorros = cliente.getNumeroCuenta("Ahorros");
    
    // Crear una cuenta bancaria con el número de cuenta generado
    CuentaBancaria<int> cuentaAhorros(numeroCuentaAhorros, "Ahorros", 1000);
    
    // Realizar operaciones
    cuentaAhorros.depositar(500, "2023-01-01");
    bool exitoRetiro = cuentaAhorros.retirar(200, "2023-01-02");
    
    // Mostrar información actualizada
    std::cout << "Saldo después de transacciones: " << cuentaAhorros.obtenerSaldo() << std::endl;

    // Obtener y mostrar las transacciones
    auto transacciones = cuentaAhorros.obtenerTransacciones();
    std::cout << "Transacciones realizadas:" << std::endl;
    for (const auto& transaccion : transacciones) {
        std::cout << "Tipo: " << transaccion.tipo << ", Monto: $" << transaccion.monto << ", Fecha: " << transaccion.fecha << std::endl;
    }

    return 0;
}
// //Verificación de funcionamiento del método transferencia
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

//     return 0;
// }
// //Prueba del metodo deposito a plazo
// int main() {
//     // Creación de una cuenta bancaria con número de cuenta, tipo de cuenta y saldo inicial
//     CuentaBancaria<double> cuenta(123456, "Ahorro", 1000.0);

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
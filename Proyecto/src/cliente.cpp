/**
 * @file cliente.hpp
 * @brief Archivo de implementación para la clase Cliente.
 * 
 * Define la implementación de los métodos declarados en Cliente.h. Esta clase gestiona
 * la información y operaciones relacionadas con los clientes, incluyendo la gestión de
 * cuentas y préstamos mediante números identificativos.
 */

#include "cliente.hpp" // Incluye la definición de la clase Cliente.
#include <stdexcept>
#include <random>


/**
 * @brief Constructor que inicializa un nuevo objeto Cliente.
 * 
 * Este constructor crea un cliente con un nombre y un número de identificación. Valida que
 * la identificación tenga exactamente 9 dígitos.
 * 
 * @param nombre Nombre del cliente.
 * @param identificacion Identificación numérica del cliente.
 * @throw std::invalid_argument Si la identificación no tiene 9 dígitos.
 */
template<typename T>
Cliente<T>::Cliente(const std::string& nombre, int identificacion)
    : nombre_(nombre), identificacion_(identificacion) {
    if (!validarIdentificacion(identificacion)) {
        throw std::invalid_argument("Identificación no válida");
    }
}


/**
 * @brief Agrega una nueva cuenta al cliente.
 * 
 * @param tipoCuenta El tipo de cuenta a agregar (por ejemplo, "Ahorros").
 */
template<typename T>
void Cliente<T>::agregarCuenta(const std::string& tipoCuenta) {
    numerosCuentas_[tipoCuenta] = generarNumeroAleatorio();
}

/**
 * @brief Agrega un nuevo préstamo al cliente.
 * 
 * @param tipoPrestamo El tipo de préstamo a agregar (por ejemplo, "Hipotecario").
 */
template<typename T>
void Cliente<T>::agregarPrestamo(const std::string& tipoPrestamo) {
    numerosPrestamos_[tipoPrestamo] = generarNumeroAleatorio();
}


/**
 * @brief Obtiene el número de cuenta asociado a un tipo de cuenta específico.
 * 
 * @param tipoCuenta El tipo de cuenta del cual obtener el número.
 * @return T El número de la cuenta.
 * @throw std::invalid_argument Si el tipo de cuenta no existe.
 */
template<typename T>
T Cliente<T>::getNumeroCuenta(const std::string& tipoCuenta) const {
    auto it = numerosCuentas_.find(tipoCuenta);
    if (it == numerosCuentas_.end()) {
        throw std::invalid_argument("Tipo de cuenta no encontrado");
    }
    return it->second;
}

/**
 * @brief Obtiene el número de préstamo asociado a un tipo de préstamo específico.
 * 
 * @param tipoPrestamo El tipo de préstamo del cual obtener el número.
 * @return T El número del préstamo.
 * @throw std::invalid_argument Si el tipo de préstamo no existe.
 */

template<typename T>
T Cliente<T>::getNumeroPrestamo(const std::string& tipoPrestamo) const {
    auto it = numerosPrestamos_.find(tipoPrestamo);
    if (it == numerosPrestamos_.end()) {
        throw std::invalid_argument("Tipo de préstamo no encontrado");
    }
    return it->second;
}

/**
 * @brief Valida que la identificación del cliente tenga exactamente 9 dígitos.
 * 
 * @param identificacion La identificación a validar.
 * @return true Si la identificación es válida.
 * @return false Si la identificación no es válida.
 */
template<typename T>
bool Cliente<T>::validarIdentificacion(int identificacion) const {
    std::string idStr = std::to_string(identificacion);
    return idStr.length() == 9;
}

/**
 * @brief Genera un número aleatorio dentro de un rango específico para ser usado como número de cuenta o préstamo.
 * 
 * @return T Un número aleatorio.
 */
template<typename T>
T Cliente<T>::generarNumeroAleatorio() const {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> dis(1, 9999999); // Rango de ejemplo
    return static_cast<T>(dis(gen));
}
//Ejemplo de uso
// int main() {
//     try {
//         // Descomentar el siguiente bloque de código para probrar su funcionalidad.

//         // Crea un nuevo cliente de tipo 'int' para los números de las cuentas y préstamos.
//         Cliente<int> cliente1("Juan Pérez", 123456789);

//         // Agrega una cuenta de ahorros y un préstamo hipotecario al primer cliente.
//         cliente1.agregarCuenta("Ahorros");
//         cliente1.agregarPrestamo("Hipotecario");

//         // Recupera y muestra la información de la cuenta y del préstamo del primer cliente.
//         int numeroCuentaAhorros = cliente1.getNumeroCuenta("Ahorros");
//         int numeroPrestamoHipotecario = cliente1.getNumeroPrestamo("Hipotecario");

//         std::cout << "Información del Cliente 1:" << std::endl;
//         std::cout << "ID: " << cliente1.getId() << std::endl;
//         std::cout << "Nombre: " << cliente1.getNombre() << std::endl;
//         std::cout << "Número de Cuenta (Ahorros): " << numeroCuentaAhorros << std::endl;
//         std::cout << "Número de Préstamo (Hipotecario): " << numeroPrestamoHipotecario << std::endl;

//         // Crea otro cliente con tipo 'int' para los números de las cuentas y préstamos.
//         Cliente<int> cliente2("Ana García", 987654321);

//         // Agrega una cuenta corriente y un préstamo personal al segundo cliente.
//         cliente2.agregarCuenta("Corriente");
//         cliente2.agregarPrestamo("Personal");

//         // Recupera y muestra la información de la cuenta y del préstamo del segundo cliente.
//         int numeroCuentaCorriente = cliente2.getNumeroCuenta("Corriente");
//         int numeroPrestamoPersonal = cliente2.getNumeroPrestamo("Personal");

//         std::cout << "\nInformación del Cliente 2:" << std::endl;
//         std::cout << "ID: " << cliente2.getId() << std::endl;
//         std::cout << "Nombre: " << cliente2.getNombre() << std::endl;
//         std::cout << "Número de Cuenta (Corriente): " << numeroCuentaCorriente << std::endl;
//         std::cout << "Número de Préstamo (Personal): " << numeroPrestamoPersonal << std::endl;

//     } catch (const std::exception& e) {
//         // Captura cualquier excepción que ocurra en el bloque try y muestra el mensaje de error.
//         std::cerr << "Error: " << e.what() << std::endl;
//     }

//     return 0; // Finaliza el programa con éxito.
// }
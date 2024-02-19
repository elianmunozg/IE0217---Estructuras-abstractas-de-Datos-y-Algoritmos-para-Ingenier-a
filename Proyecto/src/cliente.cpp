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
 * @brief Agrega una nueva cuenta bancaria al cliente con un número de cuenta generado aleatoriamente.
 * 
 * Este método asigna un nuevo número de cuenta, generado aleatoriamente, a un tipo específico de cuenta
 * bancaria (como "Ahorros" o "Corriente"). Esto permite al cliente tener múltiples cuentas de diferentes
 * tipos, cada una identificada por un número único.
 * 
 * @param tipoCuenta El tipo de la nueva cuenta a agregar, especificando su categoría (por ejemplo, "Ahorros").
 */
template<typename T>
void Cliente<T>::agregarCuenta(const std::string& tipoCuenta) {
    numerosCuentas_[tipoCuenta] = generarNumeroAleatorio();
}

/**
 * @brief Agrega un nuevo préstamo al cliente con un número de préstamo generado aleatoriamente.
 * 
 * Este método asigna un nuevo número de préstamo, generado aleatoriamente, a un tipo específico de préstamo
 * (como "Hipotecario" o "Personal"). Permite al cliente acceder a diferentes tipos de préstamos, cada uno
 * identificado por un número único.
 * 
 * @param tipoPrestamo El tipo del nuevo préstamo a agregar, especificando su categoría (por ejemplo, "Hipotecario").
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
 * @brief Obtiene el número asociado a un tipo específico de cuenta bancaria del cliente.
 * 
 * Busca entre las cuentas bancarias del cliente para encontrar una que coincida con el tipo especificado
 * y devuelve su número de cuenta. Si el tipo de cuenta no se encuentra entre las cuentas del cliente, se
 * lanza una excepción.
 * 
 * @param tipoCuenta El tipo de cuenta del cual obtener el número (por ejemplo, "Ahorros").
 * @return T El número de la cuenta asociada con el tipo especificado.
 * @throw std::invalid_argument Si el tipo de cuenta especificado no existe en el registro del cliente.
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
 * @brief Obtiene el número asociado a un tipo específico de préstamo del cliente.
 * 
 * Realiza una búsqueda entre los préstamos del cliente para encontrar uno que coincida con el tipo especificado
 * y devuelve su número de préstamo. Si el tipo de préstamo no se encuentra, se lanza una excepción.
 * 
 * @param tipoPrestamo El tipo de préstamo del cual obtener el número (por ejemplo, "Hipotecario").
 * @return T El número del préstamo asociado con el tipo especificado.
 * @throw std::invalid_argument Si el tipo de préstamo especificado no existe en el registro del cliente.
 */
template<typename T>
bool Cliente<T>::validarIdentificacion(int identificacion) const {
    std::string idStr = std::to_string(identificacion);
    return idStr.length() == 9;
}

/**
 * @brief Genera un número aleatorio dentro de un rango predefinido, destinado a ser usado como número único para cuentas o préstamos.
 * 
 * Utiliza una distribución uniforme para generar números aleatorios dentro de un rango específico. Este método
 * es útil para asignar identificadores únicos a nuevas cuentas bancarias o préstamos, asegurando que cada uno tenga
 * un número distintivo. La generación de números aleatorios se basa en un dispositivo de entropía del sistema para
 * inicializar el generador de números pseudoaleatorios, proporcionando una secuencia de números que es difícil de predecir.
 * 
 * @tparam T Define el tipo de dato numérico del número generado. Este tipo debe ser compatible con la conversión desde
 * un entero, ya que los números aleatorios se generan inicialmente como enteros dentro del rango especificado.
 * 
 * @return T Un número aleatorio generado dentro del rango [1, 9999999].
 * 
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
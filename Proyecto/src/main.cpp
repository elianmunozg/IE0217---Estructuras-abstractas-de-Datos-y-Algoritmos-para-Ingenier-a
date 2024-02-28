
#include "cuentabancaria.cpp"
#include "prestamo.cpp"

#include <iostream>
#include <string>
#include <chrono>
#include <iomanip>
#include <sstream>
#include <limits>

/* Definición del mapa de clientes registrados. */
std::map<int, Cliente<int>> clientesRegistrados;

/* Función para crear clientes, se utiliza la clase cliente para realizarlo */
void poblarClientesRegistrados() {
    // Cliente de ejemplo 1
    Cliente<int> cliente1("Juan Pérez", 123456789);
    cliente1.agregarCuenta("Colones");
    cliente1.agregarPrestamo("Hipotecario");
    clientesRegistrados.emplace(cliente1.getId(), cliente1);
    
    // Cliente de ejemplo 2
    Cliente<int> cliente2("Ana García", 987654321);
    cliente2.agregarCuenta("Dolares");
    cliente2.agregarPrestamo("Personal");
    clientesRegistrados.emplace(cliente2.getId(), cliente2);

    
}

/* Función para obtener la fecha actual en formato YYYY-MM-DD */
std::string obtenerFechaActual() {
    auto ahora = std::chrono::system_clock::now();
    auto tiempoComoTiempoT = std::chrono::system_clock::to_time_t(ahora);
    std::ostringstream fechaStream;
    fechaStream << std::put_time(std::localtime(&tiempoComoTiempoT), "%Y-%m-%d");
    return fechaStream.str();
}
/* Función main, se encarga de controlar la interfaz del usuario*/
int main() {

    poblarClientesRegistrados();
    int modoOperacion = 0;

    std::cout << "Elaborado por: Elian Munoz Gomez" << std::endl;
    std::cout << "Bienvenido al Sistema de Gestion Bancaria." << std::endl;
    bool continuar = true;
    while (continuar) {
        std::cout << "Por favor, seleccione el modo de operacion:" << std::endl;
        std::cout << "1. Atencion a Clientes" << std::endl;
        std::cout << "2. Informacion General sobre Prestamos" << std::endl;
        std::cout << "3. Salir" << std::endl; // Nueva opción para salir

        std::cin >> modoOperacion;
        
        if (std::cin.fail() || modoOperacion < 1 || modoOperacion > 3) {
            std::cout << "Opción no válida, por favor intente de nuevo." << std::endl;
            std::cin.clear(); // Clear error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the rest of the line
            continue; // Skip the rest of the loop and start over
        }



        switch (modoOperacion) {
            case 1:{
                bool continuarSubmenu = true;
                while (continuarSubmenu) {
                    std::cout << "Has seleccionado la Atención a Clientes." << std::endl;
                    std::cout << "Por favor, elige una opción:" << std::endl;
                    std::cout << "1. Información de cuentas bancarias(Transacciones y saldo)" << std::endl;
                    std::cout << "2. Realizar Transacciones (depósitos, retiros, transferencias, depósitos a plazo, abonar préstamos.)" << std::endl;
                    std::cout << "3. Crear usuario" << std::endl;
                    std::cout << "4. Salir" << std::endl;
                    
                    int opcionCliente;
                    std::cin >> opcionCliente;

                    if (std::cin.fail() || (opcionCliente < 1 || opcionCliente > 4)) {
                        std::cout << "Opción no válida, por favor intente de nuevo." << std::endl;
                        std::cin.clear(); // Limpia los flags de error de std::cin
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignora el resto de la línea
                        continue; // Comienza la próxima iteración del bucle while
                    }
                            
                    switch (opcionCliente) {
                        case 1: {
                            try {


                                std::cout << "Has seleccionado: Informacion de cuentas bancarias." << std::endl;
                                std::cout << "Por favor, ingrese su numero de identificacion:" << std::endl;
                                
                                int idCliente;
                                std::cin >> idCliente;

                                auto it = clientesRegistrados.find(idCliente);
                                if (it != clientesRegistrados.end()) {
                                    Cliente<int>& cliente = it->second;
                                    std::cout << "Información del Cliente:" << std::endl;
                                    std::cout << "Nombre: " << cliente.getNombre() << std::endl;
                                    
                                    std::ofstream archivoTransacciones("transacciones_cliente_" + std::to_string(cliente.getId()) + ".txt");
                                   
                                    if (archivoTransacciones.is_open()) {
                                        for (const auto& tipoCuenta : {"Colones", "Dolares"}) {
                                            try {
                                                int numeroCuenta = cliente.getNumeroCuenta(tipoCuenta);
                                                CuentaBancaria<int> cuenta(numeroCuenta, tipoCuenta, 0);
                                                
                                                auto transacciones = cuenta.obtenerTransacciones(); 
                                                
                                                archivoTransacciones << "Transacciones para cuenta en " << tipoCuenta << " (Número de cuenta: " << numeroCuenta << "):\n";
                                                for (const auto& transaccion : transacciones) {
                                                    archivoTransacciones << "Tipo: " << transaccion.tipo << ", Monto: $" << transaccion.monto << ", Fecha: " << transaccion.fecha << std::endl;
                                                }
                                                archivoTransacciones << "\n";
                                                std::cout << "Saldo de su cuenta en "<< tipoCuenta <<":" << cuenta.obtenerSaldo() << std::endl;
                                            } catch (const std::invalid_argument& e) {
                                                std::cout << "No se encontró cuenta de tipo " << tipoCuenta << std::endl;
                                            }
                                        }
                                        archivoTransacciones.close();
                                        std::cout << "Archivo de transaccione creado exitosamente." << std::endl;
                                    } else {
                                        std::cerr << "No se pudo abrir el archivo para escribir las transacciones." << std::endl;
                                    }
                                    for (const auto& tipoCuenta : {"Colones", "Dolares"}) {
                                        try {
                                            int numeroCuenta = cliente.getNumeroCuenta(tipoCuenta);
                                            std::cout << "Número de Cuenta (" << tipoCuenta << "): " << numeroCuenta << std::endl;
                                        } catch (const std::invalid_argument& e) {
                                            // No hay cuenta de este tipo
                                            std::cout << "No se encontró cuenta de tipo " << tipoCuenta << std::endl;
                                        }
                                    }
                                    
                                } else {
                                    std::cout << "Cliente no encontrado con ID: " << idCliente << std::endl;
                                }

                                

                            } catch (const std::exception& e) {
                                std::cerr << "Error: " << e.what() << std::endl;
                            }

                            break;
                        }
                        case 2: {
                             try {
                                std::cout << "Has seleccionado: Realizar Transacciones." << std::endl;
                                std::cout << "Por favor, ingrese su número de identificación:" << std::endl;
                                
                                int idCliente;
                                std::cin >> idCliente;

                                auto it = clientesRegistrados.find(idCliente);
                                if (it != clientesRegistrados.end()) {
                                    Cliente<int>& cliente = it->second;
                                    std::cout << "Información del Cliente:" << std::endl;
                                    std::cout << "Nombre: " << cliente.getNombre() << std::endl;

                                    bool tipoCuentaSeleccionado = false;
                                    bool tieneCuenta = false;
                                    std::string tipoCuentaSeleccionada;

                                    while (!tipoCuentaSeleccionado) {
                                        std::cout << "Por favor, seleccione el tipo de cuenta con la que desea realizar la transacción:" << std::endl;
                                        std::cout << "1. Colones" << std::endl;
                                        std::cout << "2. Dolares" << std::endl;
                                        


                                        int opcionTipoCuenta;
                                        std::cin >> opcionTipoCuenta;
                                        bool continuarTransacciones = true;

                                        switch (opcionTipoCuenta) {
                                            case 1:
                                                tipoCuentaSeleccionada = "Colones";
                                                tipoCuentaSeleccionado = true;
                                                
                                                
                                                break;
                                            case 2:
                                                tipoCuentaSeleccionada = "Dolares";
                                                tipoCuentaSeleccionado = true;
                                                break;
                                            
                                            
                                            default:
                                                std::cout << "Opción no válida. Por favor, intente de nuevo." << std::endl;
                                                std::cin.clear(); // Limpia los errores de entrada
                                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Descarta la entrada hasta la próxima línea
                                                break;
                                        }
                                        // Verificación de la existencia del tipo de cuenta seleccionada
                                        try {
                                            int numeroCuenta = cliente.getNumeroCuenta(tipoCuentaSeleccionada);
                                            std::cout << "Número de Cuenta (" << tipoCuentaSeleccionada << "): " << numeroCuenta << std::endl;
                                            tieneCuenta = true;
                                            tipoCuentaSeleccionado = true;
                                        } catch (const std::invalid_argument& e) {
                                            std::cout << "No se encontró cuenta de tipo " << tipoCuentaSeleccionada << std::endl;
                                            tieneCuenta = false;
                                            tipoCuentaSeleccionado = false; // Permite al usuario intentar de nuevo
                                        }

                                        if (!tieneCuenta) {
                                            continuarTransacciones = false; // Si no tiene cuenta, no continúa a transacciones
                                        }


                                        
                                        

                                        int opcionTransaccion;
                                    
                                        while (continuarTransacciones) {
                                            std::cout << "\nSeleccione la operación que desea realizar:" << std::endl;
                                            std::cout << "1. Depósito" << std::endl;
                                            std::cout << "2. Retiro" << std::endl;
                                            std::cout << "3. Transferencia" << std::endl;
                                            std::cout << "4. Depósito a plazo" << std::endl;
                                            std::cout << "5. Abonar a préstamo" << std::endl;
                                            std::cout << "6. Volver al menú principal" << std::endl;

                                            std::cin >> opcionTransaccion;

                                            switch (opcionTransaccion) {
                                                case 1:
                                                    // // Lógica para realizar un depósito.
                                                    // double montoDeposito;
                                                    // std::string fechaDeposito;
                                                    // std::cout << "Ingrese el monto a depositar:" << std::endl;
                                                    // while (!(std::cin >> montoDeposito) || montoDeposito <= 0) {
                                                    //     std::cout << "Monto inválido. Por favor, ingrese un valor positivo." << std::endl;
                                                    //     std::cin.clear(); // Limpia los errores de entrada
                                                    //     std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Descarta la entrada hasta la próxima línea
                                                    // }
                                                    // std::cout << "Ingrese la fecha del depósito (formato YYYY-MM-DD):" << std::endl;
                                                    // std::cin >> fechaDeposito; // Aquí podrías implementar una validación más compleja de la fecha si es necesario

                                                    // // Aquí asumimos que tienes una función validarFecha que verifica el formato y la validez de la fecha
                                                    // // Obtener la fecha actual con el formato requerido
                                                    // std::string fechaActual = obtenerFechaActual();


                                                    // // Si llegado este punto, tanto el monto como la fecha son válidos, se procede a realizar el depósito
                                                    // // Suponiendo que cuentaAhorros es la cuenta sobre la cual se realiza el depósito
                                                    // cuenta.depositar(montoDeposito, fechaActual);
                                                    // std::cout << "Depósito realizado exitosamente." << std::endl;
                                                    // break;
                                                    
                                                case 2:
                                                    // Lógica para realizar un retiro.
                                                    break;
                                                case 3:
                                                    // Lógica para realizar una transferencia.
                                                    break;
                                                case 4:
                                                    // Lógica para realizar un depósito a plazo.
                                                    break;
                                                case 5:
                                                    // Lógica para abonar a un préstamo.
                                                    break;
                                                case 6:
                                                    std::cout << "Volviendo al menú principal..." << std::endl;
                                                    continuarTransacciones = false;
                                                    break;
                                                default:
                                                    std::cout << "Opción no válida, por favor intente de nuevo." << std::endl;
                                                    std::cin.clear(); // Limpia los errores de entrada
                                                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Descarta la entrada hasta la próxima línea
                                                    break;
                                            }
                                        }
                                        }
                                
                                    


                                    
                                } else {
                                    std::cout << "Cliente no encontrado con ID: " << idCliente << std::endl;
                                }
                            } catch (const std::exception& e) {
                                std::cerr << "Error: " << e.what() << std::endl;
                            }
                            break;
                        }
                        case 3:
                            // Logica para crear usuario
                            break;
                        case 4:
                            std::cout << "Saliendo del servicio al cliente..." << std::endl;
                            continuarSubmenu = false; // Establecer continuar a false para salir del bucle del menú de servicio al cliente
                           

                            break;
                        }        
                }
            }
            case 2:{

                //Informacion general prestamos
                // Variables comunes para la entrada del usuario
                double monto;
                int cuotas;
                double tasa;
                std::string tipo;
                int opcion;
                std::string id_simulacion_prestamo;
                id_simulacion_prestamo = "simulacion";
                //Variable para controlar el while del menú de informacion de prestamos
                bool continuarInformacionPrestamos = true;
                while (continuarInformacionPrestamos)
                {
                     // Mostrar menú al usuario
                std::cout << "Seleccione el tipo de préstamo a generar:\n";
                std::cout << "1. Préstamo Personalizado\n";
                std::cout << "2. Préstamo Prendario\n";
                std::cout << "3. Préstamo Hipotecario\n";
                std::cout << "4. Préstamo Personal\n";
                std::cout << "5. Salir\n";

                std::cout << "Ingrese una opción: ";
                std::cin >> opcion;

                if (std::cin.fail() || (opcion < 1 || opcion > 5)) {
                        std::cout << "Opción no válida, por favor intente de nuevo." << std::endl;
                        std::cin.clear(); // Limpia los flags de error de std::cin
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignora el resto de la línea
                        continue; // Comienza la próxima iteración del bucle while
                }
                switch(opcion) {
                    case 1: 
                        // Préstamo Personalizado
                         // Solicitar y validar el monto del préstamo
                        do {
                            std::cout << "Monto del préstamo: ";
                            std::cin >> monto;
                            if (std::cin.fail() || monto <= 0) {
                                std::cout << "Valor no válido, por favor ingrese un número entero positivo.\n";
                                std::cin.clear(); // Limpia los flags de error de std::cin
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignora el resto de la línea
                            } else {
                                break; // Salir del bucle si el valor es válido
                            }
                        } while (true);

                        // Solicitar y validar la cantidad de cuotas
                        do {
                            std::cout << "Cantidad de cuotas: ";
                            std::cin >> cuotas;
                            if (std::cin.fail() || cuotas <= 0) {
                                std::cout << "Valor no válido, por favor ingrese un número entero positivo.\n";
                                std::cin.clear();
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            } else {
                                break;
                            }
                        } while (true);

                        // Solicitar y validar la tasa de interés
                        do {
                            std::cout << "Tasa de interés (anual en %): ";
                            std::cin >> tasa;
                            if (std::cin.fail() || tasa < 0) {
                                std::cout << "Valor no válido, por favor ingrese un número positivo.\n";
                                std::cin.clear();
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            } else {
                                break;
                            }
                        } while (true);
                        tipo = "personalizado";

                        {
                            Prestamo prestamoPersonalizado(monto, cuotas, tasa, tipo,  id_simulacion_prestamo);
                            prestamoPersonalizado.generarTablaAmortizacionTxt("TablaPersonalizado.txt");
                        }
                        break;

                    case 2: // Préstamo Prendario
                        {
                            // Solicitar y validar el monto del préstamo
                            do {
                                std::cout << "Monto del préstamo: ";
                                std::cin >> monto;
                                if (std::cin.fail() || monto <= 0) {
                                    std::cout << "Valor no válido, por favor ingrese un número entero positivo.\n";
                                    std::cin.clear(); // Limpia los flags de error de std::cin
                                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignora el resto de la línea
                                } else {
                                    break; // Salir del bucle si el valor es válido
                                }
                            } while (true);
                            Prestamo prestamoPrendario(monto, 36, 0, "prendario",  id_simulacion_prestamo);
                            prestamoPrendario.configurarTasaPrendario();
                            prestamoPrendario.generarTablaAmortizacionTxt("TablaPrendario.txt");
                        }
                        break;

                    case 3: // Préstamo Hipotecario
                        {   
                            std::cout << "Monto del préstamo: ";
                            std::cin >> monto;
                            Prestamo prestamoHipotecario(monto, 240, 0, "hipotecario",  id_simulacion_prestamo);
                            prestamoHipotecario.configurarTasaHipotecario();
                            prestamoHipotecario.generarTablaAmortizacionTxt("TablaHipotecario.txt");
                        }
                        break;

                    case 4: // Préstamo Personal
                        {   
                            do {
                                std::cout << "Monto del préstamo: ";
                                std::cin >> monto;
                                if (std::cin.fail() || monto <= 0) {
                                    std::cout << "Valor no válido, por favor ingrese un número entero positivo.\n";
                                    std::cin.clear(); // Limpia los flags de error de std::cin
                                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignora el resto de la línea
                                } else {
                                    break; // Salir del bucle si el valor es válido
                                }
                            } while (true);
                            Prestamo prestamoPersonal(monto, 60, 0, "personal", id_simulacion_prestamo);
                            prestamoPersonal.configurarTasaPersonal();
                            prestamoPersonal.generarTablaAmortizacionTxt("TablaPersonal.txt");
                        }
                        break;
                    case 5: //Salir del menu de Informacion genral de prestamos
                        {
                            continuarInformacionPrestamos = false;
                            break;
                        }

                    default:
                        std::cout << "Opción no válida. Intente de nuevo\n";
                        break;
                }


                } 
            }    
            case 3:{
                std::cout << "Saliendo del sistema..." << std::endl;
                continuar = false; // Establecer continuar a false para salir del bucle
                break;
            default:
                std::cout << "Opción no válida." << std::endl;
                break;
            }
        }
        }
    
    return 0;
}


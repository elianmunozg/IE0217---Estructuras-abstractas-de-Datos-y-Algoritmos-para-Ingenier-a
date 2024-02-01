class SalaryNotInRangeError(Exception):
    """Excepción lanzada por errores en el salario de entrada.

    Atributos:
        salary -- salario de entrada que causó el error
        message -- explicación del error
    """

    def __init__(self, salary, message="Salary is not in (5000, 15000) range"):
        self.salary = salary  # Guarda el salario que causó el error.
        self.message = message  # Mensaje por defecto que explica el error.
        super().__init__(self.message)  # Inicializa la clase base Exception con el mensaje.

salary = int(input("Enter salary amount: "))  # Pide al usuario que ingrese la cantidad del salario.
if not 5000 < salary < 15000:
    raise SalaryNotInRangeError(salary)  # Si el salario no está en el rango, lanza la excepción personalizada.

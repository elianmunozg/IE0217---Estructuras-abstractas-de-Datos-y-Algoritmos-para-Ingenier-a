# define Python user-defined exceptions
class InvalidAgeException(Exception):
    "Raised when the input value is less than 18"  # Documentación de la excepción.
    pass

# you need to guess this number
number = 18  # Este número debe ser adivinado, aunque el comentario es incorrecto, debería ser "edad mínima".

try:
    input_num = int(input("Enter a number: "))  # Pide al usuario que ingrese un número.
    if input_num < number:
        raise InvalidAgeException  # Si el número es menor que 18, lanza la excepción.
    else:
        print("Eligible to Vote")  # Si el número es 18 o mayor, es elegible para votar.
except InvalidAgeException:
    print("Exception occurred: Invalid Age")  # Captura la excepción definida por el usuario.

def smart_divide(func):  # Definición de un decorador llamado smart_divide.
    def inner(a, b):  # Función interna que actúa como el decorador propiamente dicho.
        print("I am going to divide", a, "and", b)
        if b == 0:  # Verifica si el divisor b es cero.
            print("Whoops! cannot divide")  # Si b es cero, imprime un mensaje de error.
            return  # Finaliza la función sin ejecutar la división.
        return func(a, b)  # Si b no es cero, realiza la llamada a la función original.
    return inner  # Retorna la función interna decorada.

@smart_divide  # Aplica el decorador a la siguiente función.
def divide(a, b):  # Define la función original que realiza una división.
    print(a/b)  # Imprime el resultado de la división.

# Prueba de la función decorada con división válida.
divide(2, 5)

# Prueba de la función decorada con división por cero.
divide(2, 0)

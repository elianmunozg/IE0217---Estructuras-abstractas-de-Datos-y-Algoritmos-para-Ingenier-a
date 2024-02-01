def star(func):
    def inner(*args, **kwargs):  # Definición de una función interna que acepta cualquier número de argumentos y argumentos con clave.
        print("*" * 15)  # Imprime una línea de asteriscos para decorar.
        func(*args, **kwargs)  # Llama a la función original con los argumentos proporcionados.
        print("*" * 15)  # Imprime otra línea de asteriscos después de llamar a la función original.
    return inner  # Retorna la función decoradora.

def percent(func):
    def inner(*args, **kwargs):  # Definición de otra función interna con la misma capacidad de aceptar argumentos.
        print("%" * 15)  # Imprime una línea de signos de porcentaje para decorar.
        func(*args, **kwargs)  # Llama a la función original con los argumentos proporcionados.
        print("%" * 15)  # Imprime otra línea de signos de porcentaje después de llamar a la función original.
    return inner  # Retorna la función decoradora.

@star  # Aplica el decorador 'star' a la siguiente función.
@percent  # Aplica el decorador 'percent' a la siguiente función.
def printer(msg):  # Define una función que imprime un mensaje.
    print(msg)  # Imprime el mensaje proporcionado.

printer("Hello")  # Llama a la función 'printer' con el mensaje "Hello".

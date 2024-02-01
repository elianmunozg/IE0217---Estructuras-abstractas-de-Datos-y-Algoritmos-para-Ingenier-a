def make_pretty(func):  # Define un decorador que toma una función como argumento.
    def inner():  # Define la función interna, que es el decorador propiamente dicho.
        print("I got decorated")  # Imprime un mensaje antes de llamar a la función original.
        func()  # Llama a la función original.
    return inner  # Retorna la función interna.

# define la función ordinaria
def ordinary():  # Define una función ordinaria que imprime un mensaje.
    print("I am ordinary")  # Imprime que es una función ordinaria.

# decora la función ordinaria
decorated_func = make_pretty(ordinary)  # Decora la función ordinary con make_pretty.

# llama a la función decorada
decorated_func()  # Ejecuta la función decorada que imprime ambos mensajes.

@make_pretty  # Aplica el decorador make_pretty a la función siguiente.
def ordinary():  # Define una función ordinaria que imprime un mensaje.
    print("I am ordinary")  # Imprime que es una función ordinaria.

ordinary()  # Ejecuta la función ya decorada, que imprime ambos mensajes.

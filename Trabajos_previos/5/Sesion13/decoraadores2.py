def add(x, y):  # Definición de una función simple para sumar dos números.
    return x + y  # Retorna la suma de x y y.

def calculate(func, x, y):  # Definición de una función que toma otra función y dos argumentos.
    return func(x, y)  # Llama a la función pasada como argumento con x y y.

result = calculate(add, 4, 6)  # Llama a calculate con la función add y los números 4 y 6.
print(result)  # Imprime el resultado, 10.

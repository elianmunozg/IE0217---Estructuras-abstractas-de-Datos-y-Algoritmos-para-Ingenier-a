def outer(x):  # Definición de la función externa con parámetro x.
    def inner(y):  # Definición de la función anidada con parámetro y.
        return x + y  # La función anidada suma los parámetros x y y.
    return inner  # La función externa retorna la función anidada.

add_five = outer(5)  # Crea una función que añade cinco a su argumento.
result = add_five(6)  # Llama a la función add_five con 6, lo que da como resultado 11.
print(result)  # Imprime el resultado, 11.

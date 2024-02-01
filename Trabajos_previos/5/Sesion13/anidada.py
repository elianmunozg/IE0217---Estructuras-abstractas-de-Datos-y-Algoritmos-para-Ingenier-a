def greet():  # Definición de la función externa sin parámetros.
    # variable definida fuera de la función interna
    name = "John"  # Define la variable name con el valor "John" dentro de la función externa.

    # retornar una función anónima anidada
    return lambda: "Hi " + name  # Retorna una función lambda que utiliza la variable name.

# llamar a la función externa
message = greet()  # Llama a la función externa y guarda la función lambda retornada en message.

# llamar a la función interna
print(message())  # Llama a la función lambda almacenada en message e imprime el resultado.

# Salida: Hi John

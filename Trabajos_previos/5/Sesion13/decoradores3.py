def greeting(name):  # Definición de la función con parámetro name.
    def hello():  # Definición de la función anidada sin parámetros.
        return "Hello, " + name + "!"  # La función anidada retorna un saludo con el nombre.
    return hello  # La función principal retorna la función anidada.

greet = greeting("Atlantis")  # Crea una función de saludo para "Atlantis".
print(greet())  # Llama a la función de saludo y imprime "Hello, Atlantis!".

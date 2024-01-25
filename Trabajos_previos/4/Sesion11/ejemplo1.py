# Imprime un saludo inicial
print("Hola Mundo desde Python")

contador = 15

# Verifica si el valor de contador es mayor que 10
if contador > 10:
    print("Contador es mayor a 10")
    print("Hola desde el if")

    # Verifica si el valor de contador es mayor que 18 dentro del primer if
    if contador > 18:
        print("Y además es mayor que 18")

# Esta línea se ejecuta independientemente de las condiciones anteriores
print("Esto ocurre después del if")

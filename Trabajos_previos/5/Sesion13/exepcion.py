# Se inicia un bloque de manejo de excepciones con try.
try:
    numerator = 10  # Se asigna el valor 10 a la variable 'numerator' (numerador).
    denominator = 0  # Se asigna el valor 0 a la variable 'denominator' (denominador).

    # Se intenta realizar la división del numerador entre el denominador.
    result = numerator/denominator
    # Esta línea se imprimirá si la división es exitosa, lo cual no es posible aquí.
    print(result)
except:
    # Si ocurre un error durante el try, se ejecutará este bloque.
    # Imprime un mensaje de error específico para una división por cero.
    print("Error: Denominator cannot be 0.")

# Este comentario indica la salida del programa si se ejecuta.

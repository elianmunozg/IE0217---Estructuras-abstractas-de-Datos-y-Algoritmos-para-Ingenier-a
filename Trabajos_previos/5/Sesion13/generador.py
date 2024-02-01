def my_generator(n):  # Definición de la función generadora con parámetro n.
    # inicializar contador
    value = 0  # Inicia el contador en 0.

    # bucle hasta que el contador sea menor que n
    while value < n:  # Mientras el contador sea menor que n, continúa el bucle.
        # producir el valor actual del contador
        yield value  # 'yield' retorna el valor actual y pausa la ejecución.
# iterar sobre el objeto generador producido por my_generator
# iterar sobre el objeto generador producido por my_generator
for value in my_generator(3):  # Itera sobre los valores generados por my_generator con n=3.
    # imprimir cada valor producido por el generador
    print(value)  # Imprime el valor actual producido por el generador.


# crear el objeto generador
squares_generator = (i * i for i in range(5))

# iterar sobre el generador e imprimir los valores
for i in squares_generator:
    print(i)  # Imprime los cuadrados de 0 a 4 (0, 1, 4, 9, 16).

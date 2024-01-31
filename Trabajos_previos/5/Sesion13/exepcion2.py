try:
    even_numbers = [2, 4, 6, 8]  # Se crea una lista con números pares.
    print(even_numbers[5])  # Se intenta acceder al elemento con índice 5.
except ZeroDivisionError:
    print("Denominator cannot be 0.")  # Este bloque capturaría un error de división por cero, pero no es relevante aquí.
except IndexError:
    print("Index Out of Bound.")  # Este bloque captura el error cuando el índice no existe en la lista.

# Output: Index Out of Bound  # La salida indica que el índice 5 no existe en la lista.

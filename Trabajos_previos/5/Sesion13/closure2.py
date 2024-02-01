def make_multiplier_of(n):  # Definición de la función que crea multiplicadores.
    def multiplier(x):  # Función anidada que multiplica un número por n.
        return x * n  # Retorna el resultado de la multiplicación.
    return multiplier  # Retorna la función multiplier.

# Multiplicador de 3
times3 = make_multiplier_of(3)  # times3 es un multiplicador por 3.

# Multiplicador de 5
times5 = make_multiplier_of(5)  # times5 es un multiplicador por 5.

# Salida: 27
print(times3(9))  # Imprime el resultado de 9 * 3.

# Salida: 15
print(times3(5))  # Imprime el resultado de 5 * 3.

# Salida: 30
print(times5(times3(2)))  # Imprime el resultado de 2 * 3 * 5.

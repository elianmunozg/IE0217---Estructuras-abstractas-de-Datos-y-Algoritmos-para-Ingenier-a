def fibonacci_numbers(nums):
    x, y = 0, 1  # Inicializa los dos primeros números de la secuencia de Fibonacci.
    for _ in range(nums):
        x, y = y, x + y  # Actualiza los valores de x e y con los dos siguientes números de la secuencia.
        yield x  # Produce el siguiente número de Fibonacci.

def square(nums):
    for num in nums:
        yield num**2  # Produce el cuadrado del número actual.

# Uso de generadores en pipeline
print(sum(square(fibonacci_numbers(10))))  # Imprime la suma de los cuadrados de los primeros 10 números de Fibonacci.

# Salida: 4895

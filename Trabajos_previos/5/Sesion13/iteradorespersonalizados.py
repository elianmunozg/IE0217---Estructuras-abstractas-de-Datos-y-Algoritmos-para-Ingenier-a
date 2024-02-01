class PowTwo:
    """Clase para implementar un iterador de potencias de dos."""

    def __init__(self, max=0):
        self.max = max  # Define el número máximo de potencias a generar.

    def __iter__(self):
        self.n = 0  # Inicializa el contador para el iterador.
        return self  # Retorna el objeto iterador.

    def __next__(self):
        if self.n <= self.max:
            result = 2 ** self.n  # Calcula la potencia de 2 actual.
            self.n += 1  # Incrementa el contador.
            return result  # Retorna la potencia de 2.
        else:
            raise StopIteration  # Levanta una excepción de StopIteration para finalizar la iteración.

# crear un objeto
numbers = PowTwo(3)  # Crea una instancia de PowTwo para generar potencias de dos hasta 2**3.

# crear un iterable a partir del objeto
i = iter(numbers)  # Obtiene un iterador a partir del objeto numbers.

# Usando next para obtener el siguiente elemento del iterador
print(next(i))  # imprime 1 (2**0)
print(next(i))  # imprime 2 (2**1)
print(next(i))  # imprime 4 (2**2)
print(next(i))  # imprime 8 (2**3)
print(next(i))  # Levanta StopIteration ya que ya no hay más elementos.

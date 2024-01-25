# Programa para mostrar números del 1 al 5
# Inicializar la variable
i = 1
n = 5

# Bucle while de i = 1 a 5
while i <= n:
    print(i)
    i = i + 1

# Programa para calcular la suma de números hasta que el usuario ingrese cero
total = 0

# Solicitar al usuario un número
number = int(input('Enter a number: '))

# Sumar números hasta que el número sea cero
while number != 0:
    total += number  # Esto es equivalente a total = total + number
    # Solicitar nuevamente un número entero
    number = int(input('Enter a number: '))

# Mostrar el total
print('Total =', total)

# Programa para verificar si la edad permite votar
age = 32

# La condición de prueba siempre es verdadera
while age > 18:
    print('You can vote')
    # Para evitar un bucle infinito, rompemos después de imprimir una vez
    break

# Programa con un contador y una declaración else
counter = 0

# Bucle mientras el contador sea menor que 3
while counter < 3:
    print('Inside loop')
    counter = counter + 1
else:
    # Esto se ejecuta después de que el bucle while termina
    print('Inside else')

# Como cada sección del código es independiente, se pueden ejecutar en secuencia sin problemas.

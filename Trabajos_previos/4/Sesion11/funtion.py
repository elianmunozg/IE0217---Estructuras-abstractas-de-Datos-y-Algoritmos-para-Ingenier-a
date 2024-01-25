import math

# Definición de la función greet
def greet():
    print('Hello World!')

# Llamada a la función greet
greet()

# Impresión de un mensaje que indica que estamos fuera de la función
print('Outside function')


# Definición de la función find_square
def find_square(num):
    result = num * num  # Calcula el cuadrado del número proporcionado
    return result  # Devuelve el resultado calculado

# Llamada a la función
square = find_square(3)  # Almacena el cuadrado de 3 en la variable square

# Imprime el resultado
print('Square:', square)  # Debería imprimir 'Square: 9'

# sqrt calcula la raíz cuadrada
square_root = math.sqrt(4)
print("Square Root of 4 is", square_root)

# pow() calcula la potencia
power = pow(2, 3)
print("2 to the power 3 is", power)

def add_numbers(a = 7, b = 8):
    sum = a + b
    print('Sum:', sum)

# llamada a la función con dos argumentos
add_numbers(2, 3)

# llamada a la función con un argumento
add_numbers(a = 2)

# llamada a la función sin argumentos
add_numbers()

def display_info(first_name, last_name):
    print('First Name:', first_name)
    print('Last Name:', last_name)

# llamada a la función con argumentos nombrados en diferente orden
display_info(last_name = 'Cartman', first_name
              = 'Eric')


# Definición de la función find_sum para sumar un número variable de argumentos
def find_sum(*numbers):
    result = 0  # Inicializa el resultado en 0

    # Itera sobre los números pasados a la función
    for num in numbers:
        result = result + num  # Suma cada número al resultado

    # Imprime el resultado de la suma
    print("Sum =", result)

# Llamada a la función con 3 argumentos
find_sum(1, 2, 3)

# Llamada a la función con 2 argumentos
find_sum(4, 9)

def factorial(x):
    """This is a recursive function
    to find the factorial of an integer"""

    if x == 1:
        return 1
    else:
        return x * factorial(x-1)

num = 3
print("The factorial of", num, "is", factorial(num))

# Función Lambda sin Argumentos
greet = lambda: print('Hello World')
greet()

# Función Lambda con un Argumento
greet_user = lambda name: print('Hey there,', name)
greet_user('Delilah')

# Uso de `filter()` con una Función Lambda para Filtrar Números Pares
my_list = [1, 5, 4, 6, 8, 11, 3, 12]
new_list = list(filter(lambda x: (x % 2 == 0), my_list))
print(new_list)

# Uso de `map()` con una Función Lambda para Duplicar los Elementos de una Lista
new_list = list(map(lambda x: x * 2, my_list))
print(new_list)



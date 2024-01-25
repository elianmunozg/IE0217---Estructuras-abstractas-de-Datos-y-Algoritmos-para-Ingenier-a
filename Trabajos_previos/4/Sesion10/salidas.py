# Definición de variables
number = -10.6  # Asigna un número flotante a la variable 'number'
name = "TEC2017"  # Asigna una cadena a la variable 'name'

# Imprimir literales y variables
print(5)  # Imprime un número literal
print(number)  # Imprime el valor de la variable 'number'
print(name)  # Imprime el valor de la variable 'name'

# Concatenación de cadenas
print('Este curso es ' + name)  # Concatena y imprime una cadena con el valor de la variable 'name'

# Uso de parámetros sep y end en print
print('New Year', 2023, 'See you soon', sep='.')  # Imprime argumentos separados por puntos

# Imprimir en la misma línea con un espacio al final
print('Good Morning', end=' ')  # Imprime una cadena y usa un espacio como terminador en lugar de un salto de línea
print('It is rainy today')  # Imprime otra cadena que se sigue en la misma línea

# Formateo de cadenas con .format()
x = 5  # Asigna un número entero a la variable 'x'
y = 10  # Asigna otro número entero a la variable 'y'

# Imprime una cadena con los valores de las variables 'x' y 'y' insertados en ella
print('The value of x is {} and y is {}'.format(x, y))

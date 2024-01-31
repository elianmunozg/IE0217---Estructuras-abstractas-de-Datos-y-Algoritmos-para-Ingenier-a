# programa para imprimir el recíproco de números pares
try:
    num = int(input("Enter a number: "))  # Solicita al usuario ingresar un número.
    assert num % 2 == 0  # Asegura que el número ingresado sea par.
except:
    print("Not an even number!")  # Si el número no es par, imprime un mensaje.
else:
    reciprocal = 1/num  # Si el número es par, calcula el recíproco.
    print(reciprocal)  # Imprime el recíproco.

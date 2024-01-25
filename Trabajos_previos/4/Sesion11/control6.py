# Este programa imprime los números impares de 1 a 10
num = 0
while num < 10:  # Mientras 'num' sea menor que 10
    num += 1  # Incrementa 'num'
    if (num % 2) == 0:
        continue  # Si 'num' es par, continua con el siguiente número
    print(num)  # Imprime 'num' si es impar

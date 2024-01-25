# Este programa imprime números de 0 a 4, pero omite el 3
for i in range(5):  # Itera sobre un rango de 0 a 4
    if i == 3:
        continue  # Si el número es 3, ignora el resto del bloque y continua con el siguiente número
    print(i)  # Imprime el número si no es 3

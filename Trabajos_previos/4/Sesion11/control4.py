# Este programa busca los primeros 5 múltiplos de 6
i = 1
while i <= 10:  # Mientras 'i' sea menor o igual a 10
    print('6 *', i, '=', 6 * i)  # Imprime el múltiplo de 6 por 'i'
    if i >= 5:  # Si se han impreso 5 múltiplos
        break  # Termina el bucle
    i = i + 1  # Incrementa 'i'

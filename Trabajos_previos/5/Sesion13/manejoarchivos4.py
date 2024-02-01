try:
    file1 = open("test.txt", "r")  # Intenta abrir el archivo 'test.txt' en modo de lectura.
    read_content = file1.read()  # Intenta leer todo el contenido del archivo.
    print(read_content)  # Intenta imprimir el contenido leído.
finally:
    # cerrar el archivo
    file1.close()  # Asegura que el archivo se cierre correctamente, incluso si hay un error.

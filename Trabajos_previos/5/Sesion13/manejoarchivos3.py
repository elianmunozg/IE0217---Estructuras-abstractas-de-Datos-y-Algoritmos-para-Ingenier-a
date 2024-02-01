with open("test.txt", "r") as file1:  # Abre el archivo 'test.txt' en modo de lectura utilizando un gestor de contexto.
    read_content = file1.read()  # Lee el contenido completo del archivo.
    print(read_content)  # Imprime el contenido leído en la consola.

try:
    file1 = open("test.txt", "r")  # Intenta abrir el archivo 'test.txt' en modo de lectura.
    read_content = file1.read()  # Intenta leer todo el contenido del archivo.
    print(read_content)  # Intenta imprimir el contenido leído.
finally:
    # cerrar el archivo
    file1.close()  # Asegura que el archivo se cierre correctamente, incluso si hay un error.

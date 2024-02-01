# abrir un archivo
file1 = open("test.txt", "r")  # Abre el archivo 'test.txt' en modo de lectura.

# leer el archivo
read_content = file1.read()  # Lee el contenido completo del archivo.
print(read_content)  # Imprime el contenido del archivo en la consola.

# cerrar el archivo
file1.close()  # Cierra el archivo para liberar recursos del sistema.

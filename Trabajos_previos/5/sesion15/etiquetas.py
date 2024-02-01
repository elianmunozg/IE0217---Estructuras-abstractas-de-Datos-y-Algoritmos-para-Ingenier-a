import matplotlib.pyplot as plt  # Importamos la librería matplotlib.pyplot con el alias plt.

# Definimos los datos para los ejes X e Y.
x = [1, 2, 3, 4, 5]  # Lista de valores para el eje X.
y = [10, 12, 5, 8, 14]  # Lista de valores para el eje Y correspondientes a cada punto en X.

# Creamos un gráfico de línea con los datos proporcionados.
plt.plot(x, y, label='Datos de ejemplo')  # Se dibuja un gráfico de línea y se añade una etiqueta para la leyenda.

# Añadimos etiquetas a los ejes X e Y.
plt.xlabel('Eje X')  # Etiqueta para el eje X.
plt.ylabel('Eje Y')  # Etiqueta para el eje Y.

# Añadimos un título al gráfico.
plt.title('Gráfico de Línea con Etiquetas y Título')  # Título del gráfico.

# Añadimos la leyenda al gráfico.
plt.legend()  # Muestra la leyenda, que en este caso es 'Datos de ejemplo'.

# Mostramos el gráfico.
plt.show()  # Esta función muestra el gráfico en una ventana interactiva.

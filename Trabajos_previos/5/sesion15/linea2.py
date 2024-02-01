# Importamos la librería matplotlib.pyplot con el alias plt para la creación de gráficos.
import matplotlib.pyplot as plt

# Definimos los datos para los ejes X e Y del gráfico.
x = [1, 2, 3, 4, 5]  # Valores en el eje X.
y = [10, 12, 5, 8, 14]  # Valores correspondientes en el eje Y para cada valor en X.

# Creamos un gráfico de línea con los datos proporcionados.
plt.plot(x, y)  # La función 'plot' dibuja el gráfico de línea con los datos de x e y.

# Añadimos etiquetas y título al gráfico.
plt.xlabel('Eje X')  # Establece 'Eje X' como la etiqueta para el eje horizontal.
plt.ylabel('Eje Y')  # Establece 'Eje Y' como la etiqueta para el eje vertical.
plt.title('Gráfico de Línea Simple')  # Añade 'Gráfico de Línea Simple' como el título del gráfico.

# Guardamos el gráfico en un archivo de imagen PNG.
plt.savefig('grafico.png')  # Guarda el gráfico actual en un archivo llamado 'grafico.png'.

# Finalmente, mostramos el gráfico.
plt.show()  # Abre la ventana del visualizador de Matplotlib para mostrar el gráfico.

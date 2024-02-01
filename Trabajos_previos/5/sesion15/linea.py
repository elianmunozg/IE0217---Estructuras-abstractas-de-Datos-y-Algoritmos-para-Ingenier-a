# Importamos la librería matplotlib.pyplot para crear gráficos.
import matplotlib.pyplot as plt

# Definimos los datos para los ejes X e Y.
x = [1, 2, 3, 4, 5]  # Valores en el eje X.
y = [10, 12, 5, 8, 14]  # Valores en el eje Y correspondientes a cada punto en X.

# Creamos un gráfico de línea con los datos proporcionados.
plt.plot(x, y)  # La función plot dibuja un gráfico de línea.

# Añadimos etiquetas a los ejes X e Y.
plt.xlabel('Eje X')  # Añade una etiqueta al eje X.
plt.ylabel('Eje Y')  # Añade una etiqueta al eje Y.

# Añadimos un título al gráfico.
plt.title('Gráfico de Línea Simple')  # Establece el título del gráfico.

# Activamos la cuadrícula en el gráfico para facilitar la lectura de los valores.
plt.grid(True)  # El argumento True activa la cuadrícula en el gráfico.

# Mostramos el gráfico.
plt.show()  # Abre la ventana del visualizador para mostrar el gráfico.

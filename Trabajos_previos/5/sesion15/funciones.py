import matplotlib.pyplot as plt  # Importamos la librería matplotlib.pyplot para crear gráficos.
import numpy as np  # Importamos la librería numpy para realizar operaciones matemáticas.

# Generamos un conjunto de 100 puntos entre 0 y 2*pi para el eje X.
x = np.linspace(0, 2 * np.pi, 100)  # np.linspace crea un arreglo de valores espaciados uniformemente.

# Calculamos los valores de seno y coseno de los puntos en x.
y1 = np.sin(x)  # Calcula el seno de cada punto en x.
y2 = np.cos(x)  # Calcula el coseno de cada punto en x.

# Creamos dos gráficos de línea para las funciones seno y coseno.
plt.plot(x, y1, label='Seno')  # Gráfico de la función seno con una etiqueta.
plt.plot(x, y2, label='Coseno')  # Gráfico de la función coseno con una etiqueta.

# Añadimos etiquetas y título al gráfico.
plt.xlabel('Ángulo (rad)')  # Etiqueta para el eje X.
plt.ylabel('Valor')  # Etiqueta para el eje Y.
plt.title('Funciones')  # Título del gráfico.

# Añadimos la leyenda al gráfico para identificar las líneas.
plt.legend()  # Muestra una leyenda con las etiquetas de las líneas.

# Mostramos el gráfico generado.
plt.show()  # Abre la ventana del visualizador para mostrar el gráfico.

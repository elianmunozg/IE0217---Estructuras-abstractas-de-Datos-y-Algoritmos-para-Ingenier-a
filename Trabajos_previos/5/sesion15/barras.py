import matplotlib.pyplot as plt  # Importa la librería matplotlib.pyplot con el alias plt para la creación de gráficos.

# Datos para el gráfico de barras.
categorias = ['A', 'B', 'C', 'D']  # Categorías que se mostrarán en el eje X.
valores = [15, 8, 12, 10]  # Valores correspondientes a cada categoría que se mostrarán en el eje Y.

# Creación del gráfico de barras.
plt.bar(categorias, valores, color='royalblue')  # Dibuja un gráfico de barras con las categorías y valores definidos.

# Configuración de las etiquetas y título del gráfico.
plt.xlabel('Categorías')  # Etiqueta para el eje X.
plt.ylabel('Valores')  # Etiqueta para el eje Y.
plt.title('Gráfico de Barras Verticales')  # Título del gráfico.

plt.show()  # Muestra el gráfico generado.

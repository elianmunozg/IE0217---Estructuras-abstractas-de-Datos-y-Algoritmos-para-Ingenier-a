import matplotlib.pyplot as plt  # Importa la librería matplotlib para la creación de gráficos.

# Se crean un par de listas que serán nuestros ejes.
x = [1, 2, 3, 4, 5]  # Valores para el eje X.
y = [10, 12, 5, 8, 14]  # Valores para el eje Y correspondientes a cada punto en X.

plt.plot(x, y, label='Datos de ejemplo')  # Dibuja el gráfico de línea con los datos de las listas x e y.

# Añade una anotación en el gráfico.
plt.annotate('Valor Máximo', xy=(5, 14), xytext=(3, 16),
             arrowprops=dict(facecolor='black', shrink=0.05))  # Señala con una flecha y texto el valor máximo.

plt.xlabel('Eje X')  # Etiqueta para el eje X.
plt.ylabel('Eje Y')  # Etiqueta para el eje Y.
plt.title('Gráfico con Anotación')  # Título del gráfico.
plt.legend()  # Muestra la leyenda del gráfico.

plt.show()  # Muestra el gráfico generado.

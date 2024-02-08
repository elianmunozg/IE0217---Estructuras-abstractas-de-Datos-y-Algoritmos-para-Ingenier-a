from sklearn.cluster import KMeans  # Importamos KMeans para realizar clustering.
import numpy as np  # Importamos NumPy para cálculos numéricos y manejo de arreglos.
import matplotlib.pyplot as plt  # Importamos Matplotlib para visualización de datos.

# Generar datos aleatorios
np.random.seed(42)  # Fijamos la semilla para reproducibilidad.
X = np.random.rand(100, 2) * 10  # 100 puntos bidimensionales en un rango de 0 a 10.

# Calcular la inercia para diferentes valores de k (número de clústeres)
inertias = []  # Lista para almacenar los valores de inercia para cada k.
for k in range(1, 11):  # Probamos k desde 1 hasta 10.
    kmeans = KMeans(n_clusters=k, random_state=42)  # Instanciamos KMeans con k clústeres.
    kmeans.fit(X)  # Ajustamos el modelo a los datos.
    inertias.append(kmeans.inertia_)  # Agregamos la inercia del modelo a la lista.

# Graficar el método del codo
plt.plot(range(1, 11), inertias, marker='o')  # Gráfico de la inercia en función de k.
plt.title('Método del Codo')  # Título del gráfico.
plt.xlabel('Número de Clusters (k)')  # Etiqueta del eje X.
plt.ylabel('Inercia')  # Etiqueta del eje Y.
plt.show()  # Mostramos el gráfico.

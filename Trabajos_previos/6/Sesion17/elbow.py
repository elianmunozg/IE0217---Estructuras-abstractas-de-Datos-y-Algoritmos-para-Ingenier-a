# Importamos KMeans para realizar clustering.
from sklearn.cluster import KMeans
# Importamos NumPy para cálculos numéricos y manejo de arreglos.
import numpy as np
# Importamos Matplotlib para visualización de datos.
import matplotlib.pyplot as plt

# Generar datos aleatorios
np.random.seed(42)  # Fijamos la semilla para reproducibilidad.
# 100 puntos bidimensionales en un rango de 0 a 10.
X = np.random.rand(100, 2) * 10

# Calcular la inercia para diferentes valores de k (número de clústeres)
inertias = []  # Lista para almacenar los valores de inercia para cada k.
for k in range(1, 11):  # Probamos k desde 1 hasta 10.
    # Instanciamos KMeans con k clústeres.
    kmeans = KMeans(n_clusters=k, random_state=42)
    kmeans.fit(X)  # Ajustamos el modelo a los datos.
    # Agregamos la inercia del modelo a la lista.
    inertias.append(kmeans.inertia_)

# Graficar el método del codo
# Gráfico de la inercia en función de k.
plt.plot(range(1, 11), inertias, marker='o')
plt.title('Método del Codo')  # Título del gráfico.
plt.xlabel('Número de Clusters (k)')  # Etiqueta del eje X.
plt.ylabel('Inercia')  # Etiqueta del eje Y.
plt.show()  # Mostramos el gráfico.

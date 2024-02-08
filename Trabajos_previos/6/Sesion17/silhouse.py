from sklearn.cluster import KMeans  # Importamos KMeans para realizar clustering.
from sklearn.metrics import silhouette_score  # Importamos la métrica para calcular el coeficiente de silueta.
import matplotlib.pyplot as plt  # Matplotlib para la visualización de datos.
import numpy as np  # NumPy para cálculos numéricos y manejo de arreglos.

# Generar datos aleatorios
np.random.seed(42)  # Fijamos la semilla para reproducibilidad.
X = np.random.rand(100, 2) * 10  # 100 puntos bidimensionales en un rango de 0 a 10.

# Calcular el coeficiente de silueta para diferentes valores de k
silhouette_scores = []  # Lista para almacenar los puntajes de silueta para cada k.
for k in range(2, 20):  # Evaluamos desde 2 hasta 19 clústeres (el coeficiente de silueta no se define para k=1).
    kmeans = KMeans(n_clusters=k, random_state=42)  # Instanciamos KMeans con k clústeres.
    kmeans.fit(X)  # Ajustamos el modelo a los datos.
    score = silhouette_score(X, kmeans.labels_)  # Calculamos el coeficiente de silueta.
    silhouette_scores.append(score)  # Añadimos el puntaje a la lista.

# Graficar el método de la silueta
plt.plot(range(2, 20), silhouette_scores, marker='o')  # Gráfico de los puntajes de silueta en función de k.
plt.title('Método de la Silueta')  # Título del gráfico.
plt.xlabel('Número de Clusters (k)')  # Etiqueta del eje X.
plt.ylabel('Coeficiente de Silueta')  # Etiqueta del eje Y.
plt.show()  # Mostramos el gráfico.

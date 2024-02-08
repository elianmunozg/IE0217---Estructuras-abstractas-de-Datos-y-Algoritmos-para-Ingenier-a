import matplotlib.pyplot as plt  # Para la visualización de datos.
# Para generar datos en forma de lunas.
from sklearn.datasets import make_moons
from sklearn.cluster import DBSCAN  # Algoritmo de clustering DBSCAN.

# Generar datos de ejemplo (luna creciente)
# 200 muestras con forma de dos lunas.
X, _ = make_moons(n_samples=200, noise=0.05, random_state=42)

# Configurar y ajustar el modelo DBSCAN
# Instanciamos DBSCAN con radio de 0.3 y un mínimo de 5 muestras por clúster.
dbscan = DBSCAN(eps=0.3, min_samples=5)
# Ajustamos el modelo a los datos y obtenemos las etiquetas de clúster.
dbscan_labels = dbscan.fit_predict(X)

# Visualizar resultados
plt.scatter(
    # Puntos coloreados por clúster.
    X[:, 0], X[:, 1], c=dbscan_labels, cmap='viridis', edgecolor='k', s=50
)
plt.title('Resultado del Clustering DBSCAN')  # Título del gráfico.
plt.xlabel('Característica 1')  # Etiqueta del eje X.
plt.ylabel('Característica 2')  # Etiqueta del eje Y.
plt.show()  # Mostramos el gráfico de dispersión.

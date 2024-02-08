import matplotlib.pyplot as plt  # Para visualización de datos.
# Para clustering jerárquico y visualización del dendrograma.
from scipy.cluster.hierarchy import dendrogram, linkage
# Para generar datos sintéticos en forma de "blobs".
from sklearn.datasets import make_blobs
# Para realizar clustering jerárquico con scikit-learn.
from sklearn.cluster import AgglomerativeClustering

# Generar datos de ejemplo
# Crear 50 muestras con 3 centros.
X, y = make_blobs(n_samples=50, centers=3, random_state=42, cluster_std=1.0)

# Configuración de Hierarchical Clustering con enlace completo
# Realizar clustering jerárquico con enlace completo.
Z = linkage(X, method='complete')

# Visualizar el dendrograma
plt.figure(figsize=(10, 5))  # Establecer tamaño de la figura.
dendrogram(Z)  # Crear el dendrograma con la matriz de enlace Z.
plt.title('Dendrograma Hierarchical Clustering')  # Título del dendrograma.
plt.xlabel('Índice del Punto de Datos')  # Etiqueta del eje X.
plt.ylabel('Distancia')  # Etiqueta del eje Y.
plt.show()  # Mostrar el dendrograma.

# Configuración de Hierarchical Clustering con scikit-learn
# Instanciar AgglomerativeClustering para 3 clústeres.
agg_clustering = AgglomerativeClustering(n_clusters=3)
# Ajustar el modelo y predecir las etiquetas de los clústeres.
agg_labels = agg_clustering.fit_predict(X)

# Visualizar resultados
plt.scatter(
    # Pintar puntos con colores según el clúster.
    X[:, 0], X[:, 1], c=agg_labels, cmap='viridis', edgecolor='k', s=50
)
# Título del gráfico de dispersión.
plt.title('Resultado del Clustering Jerárquico')
plt.xlabel('Característica 1')  # Etiqueta del eje X.
plt.ylabel('Característica 2')  # Etiqueta del eje Y.
plt.show()  # Mostrar el gráfico de dispersión.

from sklearn.cluster import KMeans
from sklearn.metrics import silhouette_score
import matplotlib.pyplot as plt
from sklearn.preprocessing import StandardScaler

def determinar_numero_optimo_clusters(datos):
    """
    Determina el número óptimo de clusters utilizando el método del codo y el índice de Silhouette.
    """
    # Escalar los datos
    scaler = StandardScaler()
    datos_escalados = scaler.fit_transform(datos)
    
    # Método del codo
    inercias = []
    for k in range(1, 11):
        kmeans = KMeans(n_clusters=k, random_state=42)
        kmeans.fit(datos_escalados)
        inercias.append(kmeans.inertia_)
    
    plt.figure(figsize=(10, 6))
    plt.plot(range(1, 11), inercias, marker='o')
    plt.title('Método del Codo')
    plt.xlabel('Número de Clusters')
    plt.ylabel('Inercia')
    plt.show()
    
    # Método de Silhouette
    silhouette_scores = []
    for k in range(2, 11):  # Silhouette no se puede calcular para k=1
        kmeans = KMeans(n_clusters=k, random_state=42)
        kmeans.fit(datos_escalados)
        score = silhouette_score(datos_escalados, kmeans.labels_)
        silhouette_scores.append(score)
    
    plt.figure(figsize=(10, 6))
    plt.plot(range(2, 11), silhouette_scores, marker='o')
    plt.title('Puntuación de Silhouette')
    plt.xlabel('Número de Clusters')
    plt.ylabel('Silhouette Score')
    plt.show()

def aplicar_kmeans(datos, n_clusters):
    """
    Aplica KMeans al conjunto de datos con el número especificado de clusters y visualiza los resultados.
    """
    # Escalar los datos
    scaler = StandardScaler()
    datos_escalados = scaler.fit_transform(datos)
    
    # Aplicar KMeans
    kmeans = KMeans(n_clusters=n_clusters, random_state=42)
    clusters = kmeans.fit_predict(datos_escalados)
    
    # Visualizar los clusters
    # Esta visualización es básica y asume que se seleccionan 2 características para el análisis
    plt.figure(figsize=(10, 6))
    plt.scatter(datos_escalados[:, 0], datos_escalados[:, 1], c=clusters, cmap='viridis', marker='o', edgecolor='black', s=50, alpha=0.6)
    plt.title(f'Clusters de Vehículos con K={n_clusters}')
    plt.xlabel('Característica 1 (escalada)')
    plt.ylabel('Característica 2 (escalada)')
    plt.show()

    return clusters

# Importamos las bibliotecas necesarias para el procesamiento de los datos y la ejecución de algoritmos de clustering
from sklearn.preprocessing import StandardScaler
from sklearn.cluster import KMeans
import pandas as pd
import matplotlib.pyplot as plt

# Cargamos los datos desde un archivo CSV en un DataFrame de pandas

data = pd.read_csv('average_spend_frequency_time_spent.csv')

# Exploramos los primeros registros del conjunto de datos para entender su estructura
print(data.head())

# Preprocesamiento de los datos para mejorar los resultados del clustering
# Estandarizamos las características para que tengan una media de 0 y una desviación estándar de 1
scaler = StandardScaler()
scaled_data = scaler.fit_transform(data)

# Utilizamos el método del codo para encontrar el número óptimo de clusters
# El método del codo consiste en variar la cantidad de clusters (k) y calcular la inercia para cada k
# La inercia mide cuán cercanos están los puntos de datos a su centroide
inertia = []
for k in range(1, 11):
    kmeans = KMeans(n_clusters=k, random_state=42)
    kmeans.fit(scaled_data)
    inertia.append(kmeans.inertia_)

# Graficamos los resultados del método del codo para visualizar el punto donde el cambio en inercia se reduce significativamente
plt.plot(range(1, 11), inertia, marker='o')
plt.title('Método del Codo para Selección de k')
plt.xlabel('Número de Clusters (k)')
plt.ylabel('Inercia')
plt.show()

# Seleccionamos un número de clusters basándonos en la gráfica del método del codo
# Asumimos que el número óptimo de clusters es 4
kmeans = KMeans(n_clusters=4, random_state=42)
cluster_labels = kmeans.fit_predict(scaled_data)

# Agregamos las etiquetas de los clusters al conjunto de datos original para poder identificar a qué cluster pertenece cada punto
data['Cluster'] = cluster_labels

# Realizamos un análisis de segmentos para entender las características de cada cluster
segment_analysis = data.groupby('Cluster').mean()

# Visualizamos los segmentos de clientes utilizando un gráfico de dispersión
plt.figure(figsize=(12, 6))
for cluster in range(4):
    plt.scatter(data[data['Cluster'] == cluster]['Frequency'],
                data[data['Cluster'] == cluster]['Avg_Spend'],
                label=f'Cluster {cluster}')
plt.title('Segmentación de Clientes por Frecuencia y Gasto Promedio')
plt.xlabel('Frecuencia de Visita')
plt.ylabel('Gasto Promedio')
plt.legend()
plt.show()

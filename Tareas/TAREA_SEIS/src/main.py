from car_analysis import regression, limpieza
from car_analysis.clustering import determinar_numero_optimo_clusters, aplicar_kmeans
from kaggle.api.kaggle_api_extended import KaggleApi

import pandas as pd

def descargar_datos(dataset='akshaydattatraykhare/car-details-dataset', path='.', unzip=True):
    api = KaggleApi()
    api.authenticate()
    api.dataset_download_files(dataset, path=path, unzip=unzip)
    print("Conjunto de datos descargado y descomprimido con éxito.")

def cargar_datos(archivo_csv):
    return pd.read_csv(archivo_csv)
def preparar_datos_transmision(datos_limpios):
    # Asume que `datos_limpios` ya tiene una columna 'transmission_Manual' como resultado de get_dummies o similar.
    X = datos_limpios[['transmission_Manual']].values  # Usa .values para obtener un array de NumPy
    y = datos_limpios['selling_price'].values
    return X, y

def main():
    # Descargar el conjunto de datos
    descargar_datos()
    # Cargar y limpiar datos
    datos = cargar_datos('CAR DETAILS FROM CAR DEKHO.csv')
    datos_limpios = limpieza.limpiar_datos(datos)

    # Preparar datos para el análisis de transmisión
    X, y = preparar_datos_transmision(datos_limpios)

    # Seleccionar características relevantes para el clustering
    # Asumamos que queremos analizar basándonos en 'year' y 'selling_price' como ejemplo
    datos_para_clustering = datos_limpios[['year', 'selling_price']]

    # Determinar el número óptimo de clusters
    determinar_numero_optimo_clusters(datos_para_clustering)
    
    # Aplicar K-Means con el número óptimo de clusters decidido (asumiendo que decidimos 3 basado en el análisis)
    n_clusters_optimo = 3
    aplicar_kmeans(datos_para_clustering, n_clusters_optimo)
    
    # Verificar las columnas disponibles después de la limpieza
    print(datos_limpios.columns)
    
    if 'year' in datos_limpios.columns:
        X = datos_limpios[['year']].values.reshape(-1, 1)  # Asegúrate de que sea 2D
        y = datos_limpios['selling_price'].values
        
        # Realizar y visualizar regresión lineal
        regression.realizar_analisis(X, y, "Precio de los vehículos a lo largo de los años (Lineal)", "Año", "Precio de Venta", es_lineal=True)
        
        # Realizar y visualizar regresión no lineal
        regression.realizar_analisis(X, y, "Precio de los vehículos a lo largo de los años (No Lineal)", "Año", "Precio de Venta", es_lineal=False, grado=3)
    else:
        print("La columna 'year' no está disponible después de la limpieza.")
    

    if 'transmission_Manual' in datos_limpios.columns:
        X, y = preparar_datos_transmision(datos_limpios)
        
        # Realizar y visualizar regresión lineal
        regression.realizar_analisis(X, y, "Impacto de la Transmisión en el Precio de Vehículos (Lineal)", "Transmisión (0=Automática, 1=Manual)", "Precio de Venta", es_lineal=True)
        
        # Realizar y visualizar regresión no lineal
        regression.realizar_analisis(X, y, "Impacto de la Transmisión en el Precio de Vehículos (No Lineal)", "Transmisión (0=Automática, 1=Manual)", "Precio de Venta", es_lineal=False, grado=3)
    else:
        print("La columna 'transmission_Manual' no está disponible después de la limpieza.")


if __name__ == "__main__":
    main()

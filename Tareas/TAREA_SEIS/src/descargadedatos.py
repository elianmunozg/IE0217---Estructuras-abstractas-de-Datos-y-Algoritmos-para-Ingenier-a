from kaggle.api.kaggle_api_extended import KaggleApi

# Inicializar la API
api = KaggleApi()
api.authenticate()

# Nombre del conjunto de datos: usuario/nombre-del-conjunto-de-datos
dataset = 'akshaydattatraykhare/car-details-dataset'

# Descargar el conjunto de datos y descomprimirlo en el directorio actual
api.dataset_download_files(dataset, path='.', unzip=True)

print("Descarga completada.")

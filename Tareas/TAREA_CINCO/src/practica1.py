# Se importan las librerías necesarias para manejar los datos e imprimir los resultados en forma de gráficos
import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
import os


class DataManager:
    """
        La clase DataManager se encarga de la carga y la limpieza de los datos de un archivo CSV.
        
        Attributes:
            file_path (str): La ruta al archivo CSV que se va a cargar y limpiar.
            data_cleaned (DataFrame): Un DataFrame de pandas que contiene los datos ya limpios y listos para su análisis.
            
        Methods:
            load_and_clean_data(): Carga los datos del CSV, realiza una limpieza preliminar y los almacena en `data_cleaned`.
            get_cleaned_data(): Devuelve el DataFrame de los datos ya limpios.
        """
    def __init__(self, file_path):
        """
        Inicializa la instancia de DataManager con la ruta del archivo proporcionada.
        
        Parameters:
            file_path (str): La ruta al archivo CSV que se va a cargar y limpiar.
        """
        self.file_path = file_path
        self.data_cleaned = None

    def load_and_clean_data(self):
        """
        Carga los datos desde el archivo CSV indicado en `file_path`. Realiza la limpieza de datos eliminando filas innecesarias,
        renombrando columnas y convirtiendo las cadenas numéricas con comas a valores numéricos. Los datos limpios se almacenan en `data_cleaned`.
        
        El método maneja excepciones para evitar que el programa falle si hay problemas al cargar el archivo.
        """
        try:
            data = pd.read_csv(self.file_path, skiprows=1)
            data = data.iloc[:9]  # Mantener solo las primeras 9 filas
            data.columns = ['Category', '2002', '2003', '2004', '2005']
            data = data.apply(lambda x: x.str.replace(',', '') if x.name in [
                              '2002', '2003', '2004', '2005'] else x)
            data[['2002', '2003', '2004', '2005']] = data[['2002', '2003',
                                                           '2004', '2005']].apply(pd.to_numeric, errors='coerce')
            self.data_cleaned = data
        except Exception as e:
            print(f"Error loading the file: {e}")

    def get_cleaned_data(self):
        """
        Devuelve el DataFrame de los datos limpios almacenados en `data_cleaned`.
        
        Returns:
            DataFrame: Un DataFrame de pandas que contiene los datos ya limpios y listos para su análisis.
        """
        return self.data_cleaned


class DataAnalyzer:
    """
    La clase DataAnalyzer se encarga de analizar un conjunto de datos de objetos prohibidos interceptados en aeropuertos.
    
    Attributes:
        data (DataFrame): Un DataFrame que contiene los datos que serán analizados.
        
    Methods:
        analyze_data(): Procesa y analiza los datos, proporcionando estadísticas descriptivas y identificando tendencias.
    """
    def __init__(self, data):
        """
        Inicializa la instancia de DataAnalyzer con el DataFrame de datos a analizar.
        
        Parameters:
            data (DataFrame): Un DataFrame de pandas que contiene los datos a analizar.
        """
        self.data = data

    def analyze_data(self):
        """
        Realiza el análisis de los datos proporcionados.
        
        El método maneja excepciones para garantizar que las operaciones de cadena se apliquen solo a columnas de tipo cadena y
        realiza la conversión a tipo numérico de manera segura. Calcula y muestra estadísticas descriptivas, identifica la categoría
        con la mayor cantidad de objetos interceptados y muestra las tendencias a lo largo de los años.
        
        Utiliza un enfoque robusto para la conversión de datos, controlando los errores y proporcionando comentarios útiles para la depuración.
        """
        for year in ['2002', '2003', '2004', '2005']:
            try:
                # Intenta reemplazar comas y convertir a numérico
                self.data[year] = pd.to_numeric(
                    self.data[year].str.replace(',', ''), errors='coerce')
            except AttributeError:
                # Manejo de excepciones en caso de que la columna no sea una cadena
                print(
                    f"Advertencia: La columna {year} no se trató como string. Verificando el tipo de datos...")
                # Verifica y muestra el tipo de datos actual de la columna
                print(
                    f"Tipo de datos actual de la columna {year}: {self.data[year].dtype}")
                # Si la columna ya es numérica, no necesita conversión
                if self.data[year].dtype in ['float64', 'int64']:
                    print(f"La columna {year} ya es de tipo numérico.")
                else:
                    # Si la columna no es numérica, intenta otra forma de conversión o manejo
                    print(
                        f"La columna {year} necesita revisión manual para la conversión.")

       # Estadísticas descriptivas de los datos
        descriptive_stats = self.data.describe()

        # Calcular totales por categoría excluyendo 'Total prohibited items' y 'Enplanements'
        total_per_category = self.data.set_index('Category').sum(axis=1).drop(
            ['Total prohibited items', 'Enplanements '], errors='ignore')

        # Identificar la categoría con el mayor número de objetos interceptados
        max_category = total_per_category.idxmax()
        max_value = total_per_category.max()

        print(
            f"La categoría específica con más objetos interceptados es '{max_category}' con un total de {max_value} objetos.")
        print("\nEstadísticas descriptivas por año:\n", descriptive_stats)

        # Tendencias a lo largo de los años
        totals_by_year = self.data.sum()[1:]  # Excluir la columna de categoría
        print("\nTotales por año:\n", totals_by_year)

       


class DataVisualizer:
    """
    La clase DataVisualizer se encarga de crear visualizaciones gráficas a partir de un conjunto de datos de objetos prohibidos interceptados en aeropuertos.

    Attributes:
        data (DataFrame): Un DataFrame que contiene los datos que serán visualizados.

    Methods:
        plot_totals_by_year(): Crea y muestra un gráfico de líneas de los totales por año.
        plot_most_confiscated_item(): Crea y muestra un gráfico de barras del objeto más confiscado.
        plot_heatmap(): Crea y muestra un heatmap de los objetos prohibidos interceptados por categoría y año.
        plot_boxplot(): Crea y muestra un boxplot de los objetos prohibidos interceptados por año para cada categoría.
    """
    
    def __init__(self, data):
        """
        Inicializa la instancia de DataVisualizer con el DataFrame de datos a visualizar.

        Parameters:
            data (DataFrame): Un DataFrame de pandas que contiene los datos a visualizar.
        """
        self.data = data

    def plot_totals_by_year(self):
        """
        Genera un gráfico de líneas que representa los totales de objetos prohibidos interceptados por año.
        Muestra las tendencias a lo largo del tiempo y destaca cómo cambia la cantidad de interceptaciones.
        """
        totals_by_year = self.data[['2002', '2003', '2004', '2005']].sum()
        plt.figure(figsize=(10, 6))
        totals_by_year.plot(kind='line', marker='o', linestyle='-',
                            color='skyblue', linewidth=2, markersize=8)
        plt.title('Evolución de Objetos Prohibidos Interceptados por Año')
        plt.xlabel('Año')
        plt.ylabel('Cantidad Total de Objetos Interceptados')
        plt.grid(axis='both', linestyle='--')
        plt.xticks(rotation=45)
        plt.tight_layout()
        plt.show()

    def plot_most_confiscated_item(self):
        """
        Genera un gráfico de barras que representa el número de decomisos por categoría.
        Identifica y resalta la categoría con el mayor número de objetos confiscados.
        """
        total_per_category = self.data.set_index('Category').sum(axis=1).drop(
            ['Total prohibited items', 'Enplanements '], errors='ignore')
        most_confiscated_category = total_per_category.idxmax()
        most_confiscated_value = total_per_category.max()

        plt.figure(figsize=(8, 6))
        total_per_category.sort_values().plot(kind='bar', color='lightblue')
        plt.title('Objetos Prohibidos Interceptados por Categoría')
        plt.xlabel('Categoría')
        plt.ylabel('Cantidad de Decomisos')
        plt.xticks(rotation=45)
        plt.grid(axis='y', linestyle='--')
        plt.tight_layout()
        plt.show()

    def plot_heatmap(self):
        """
        Genera un heatmap para visualizar la cantidad de objetos prohibidos interceptados, categorizados por tipo y año.
        Este gráfico ayuda a identificar rápidamente las categorías y los años con mayores incidencias.
        """
        plt.figure(figsize=(10, 8))
        sns.heatmap(self.data.set_index('Category').drop(
            ['Total prohibited items', 'Enplanements '], errors='ignore'), annot=True, fmt="d", cmap='Blues')
        plt.title('Heatmap de Objetos Prohibidos Interceptados por Categoría y Año')
        plt.ylabel('Categoría')
        plt.xlabel('Año')
        plt.show()

    def plot_boxplot(self):
        """
        Genera boxplots que muestran la distribución de la cantidad de objetos prohibidos interceptados por año para cada categoría.
        Esta visualización es útil para identificar la variabilidad y los valores atípicos en los datos.
        """
        melted_data = self.data.melt(
            id_vars='Category', var_name='Year', value_name='Items Intercepted')
        melted_data = melted_data[melted_data['Category'].isin(
            ['Total prohibited items', 'Enplanements ']) == False]  # Excluir totales y enplanements
        plt.figure(figsize=(12, 8))
        sns.boxplot(x='Year', y='Items Intercepted', data=melted_data)
        plt.title('Distribución de Objetos Prohibidos Interceptados por Año')
        plt.xlabel('Año')
        plt.ylabel('Cantidad de Objetos Interceptados')
        plt.show()

#Se obtiene la ruta al directorio actual donde se ejecuta el script
current_dir = os.path.dirname(os.path.abspath(__file__))

# Se construye la ruta al archivo CSV utilizando la ruta al directorio actual
file_path = os.path.join(current_dir, 'table_02_16b.csv')

# Cargar y limpiar los datos
data_manager = DataManager(file_path)
data_manager.load_and_clean_data()
cleaned_data = data_manager.get_cleaned_data()

# Analizar los datos
data_analyzer = DataAnalyzer(cleaned_data)
data_analyzer.analyze_data()

# Visualizar los datos
data_visualizer = DataVisualizer(cleaned_data)
data_visualizer.plot_totals_by_year()

# Visualizar el objeto con más decomisos
data_visualizer.plot_most_confiscated_item()

# Visualizar el heatmap
data_visualizer.plot_heatmap()

# Visualizar el boxplot
data_visualizer.plot_boxplot()


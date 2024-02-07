# Se importan las librerías necesarias para manejar los datos e imprimir los resultados en forma de gráficos
import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns


class DataManager:
    def __init__(self, file_path):
        self.file_path = file_path
        self.data_cleaned = None

    def load_and_clean_data(self):
        """Carga y limpia el archivo CSV."""
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
        """Devuelve los datos limpios."""
        return self.data_cleaned


class DataAnalyzer:
    def __init__(self, data):
        self.data = data

    def analyze_data(self):
        """Realiza análisis en los datos con manejo de excepciones."""
        for year in ['2002', '2003', '2004', '2005']:
            try:
                # Intenta reemplazar comas y convertir a numérico
                self.data[year] = pd.to_numeric(
                    self.data[year].str.replace(',', ''), errors='coerce')
            except AttributeError:
                # Si se produce un AttributeError, probablemente debido a que la columna no es de tipo string
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

        # Calcular estadísticas descriptivas
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

        # Identificar tendencias
        totals_by_year = self.data.sum()[1:]  # Excluir la columna de categoría
        print("\nTotales por año:\n", totals_by_year)

       


class DataVisualizer:
    def __init__(self, data):
        self.data = data

    def plot_totals_by_year(self):
        """Visualiza los totales por año en un gráfico de líneas."""
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
        """Visualiza el objeto con más decomisos."""
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
        """Visualiza un heatmap de los objetos prohibidos interceptados por categoría a lo largo de los años."""
        plt.figure(figsize=(10, 8))
        sns.heatmap(self.data.set_index('Category').drop(
            ['Total prohibited items', 'Enplanements '], errors='ignore'), annot=True, fmt="d", cmap='Blues')
        plt.title('Heatmap de Objetos Prohibidos Interceptados por Categoría y Año')
        plt.ylabel('Categoría')
        plt.xlabel('Año')
        plt.show()

    def plot_boxplot(self):
        """Visualiza boxplots de los objetos prohibidos interceptados a lo largo de los años para cada categoría."""
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


file_path = 'table_02_16b.csv'

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

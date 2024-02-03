# Importamos las librerías necesarias para el manejo de datos y visualización.
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

# Definimos la clase Prestamo, que modelará el comportamiento y datos de un préstamo.
class Prestamo:
    # El método inicializador toma el monto del préstamo, la tasa de interés anual y el número de cuotas.
    def __init__(self, monto_prestamo, tasa_interes_anual, cuotas):
        # Establecemos las variables de instancia con los valores proporcionados.
        self.monto_prestamo = monto_prestamo
        self.tasa_interes_anual = tasa_interes_anual
        self.cuotas = cuotas
        # Inicializamos la amortización llamando al método calcular_amortizacion.
        self.amortizacion = self.calcular_amortizacion()

    # Método para calcular la amortización del préstamo.
    def calcular_amortizacion(self):
        try:
            # Convertimos la tasa de interés anual a una tasa mensual dividiendo entre 12 y 100.
            tasa_interes_mensual = self.tasa_interes_anual / 12 / 100
            
            # Calculamos la cuota mensual que se debe pagar en el préstamo.
            cuota_mensual = (tasa_interes_mensual * self.monto_prestamo) / \
                            (1 - (1 + tasa_interes_mensual) ** -self.cuotas)
            
            # Inicializamos el saldo restante al monto total del préstamo.
            saldo_restante = self.monto_prestamo
            # Inicializamos una lista vacía para almacenar el plan de amortización.
            amortizacion = []
            
            # Iteramos sobre el número total de cuotas.
            for cuota in range(1, self.cuotas + 1):
                # Calculamos el interés pendiente basado en el saldo restante y la tasa de interés mensual.
                interes_pendiente = saldo_restante * tasa_interes_mensual
                # La parte de la cuota que se aplica al principal se calcula restando el interés pendiente de la cuota mensual.
                amortizacion_principal = cuota_mensual - interes_pendiente
                # Actualizamos el saldo restante restando la cantidad que se aplicó al principal.
                saldo_restante -= amortizacion_principal
                # Añadimos un diccionario con los detalles de la cuota actual a la lista de amortización.
                amortizacion.append({'Cuota': cuota, 'Interés': interes_pendiente, 
                                    'Amortización': amortizacion_principal, 'Saldo Restante': saldo_restante})
            # Retornamos la lista de amortización.
            return amortizacion
        except ZeroDivisionError:
            # Capturamos la excepción para el caso en que el número de cuotas sea cero, lo cual causaría una división por cero.
            print("Error: La cantidad de cuotas no puede ser cero.")
            # Retornamos una lista vacía como señal de que hubo un error.
            return []
   
    # Método para genrar el reporte 
    def generar_reporte(self, archivo_salida):
        try:
            # Convertimos la amortización almacenada en la instancia a un DataFrame de Pandas.
            df = pd.DataFrame(self.amortizacion)
            # Exportamos el DataFrame a un archivo CSV sin incluir el índice del DataFrame.
            df.to_csv(archivo_salida, index=False)
            # Confirmamos la creación del archivo con un mensaje.
            print(f'Reporte generado con éxito: {archivo_salida}')
        except Exception as e:
            # Capturamos cualquier excepción que pueda ocurrir durante la generación del reporte y mostramos un mensaje.
            print(f'Ocurrió un error al generar el reporte: {str(e)}')
    
    # Método graficar la amortización
    def graficar_amortizacion(self):
        # Convertimos la amortización almacenada en la instancia a un DataFrame de Pandas.
        df = pd.DataFrame(self.amortizacion)
        
        # Creamos un arreglo NumPy a partir de las columnas de interés y amortización del DataFrame.
        data = np.array([df['Interés'], df['Amortización']])
        
        # Generamos un gráfico de barras apiladas con los datos de interés y amortización para cada cuota.
        plt.bar(df['Cuota'], data[0], label='Interés')
        plt.bar(df['Cuota'], data[1], bottom=data[0], label='Amortización')
        
        # Establecemos las etiquetas del eje x y del eje y.
        plt.xlabel('Número de cuota')
        plt.ylabel('Monto ($)')
        
        # Establecemos el título del gráfico.
        plt.title('Amortización e Interés por Cuota')
        
        # Mostramos la leyenda del gráfico.
        plt.legend()
        
        # Mostramos el gráfico generado.
        plt.show()

def main():
    # Solicita al usuario ingresar el monto del préstamo y valida la entrada.
    while True:
        try:
            monto = float(input("Ingrese el monto del préstamo: "))
            if monto <= 0:
                print("Por favor, ingrese un monto positivo.")
                continue
            break
        except ValueError:
            print("Entrada inválida. Por favor, ingrese un número válido.")

    # Solicita al usuario ingresar la tasa de interés anual y valida la entrada.
    while True:
        try:
            tasa = float(input("Ingrese la tasa de interés anual (%): "))
            if tasa <= 0:
                print("Por favor, ingrese una tasa de interés positiva.")
                continue
            break
        except ValueError:
            print("Entrada inválida. Por favor, ingrese un número válido.")

    # Solicita al usuario ingresar el número de cuotas y valida la entrada.
    while True:
        try:
            cuotas = int(input("Ingrese la cantidad de cuotas: "))
            if cuotas <= 0:
                print("Por favor, ingrese un número de cuotas mayor que cero.")
                continue
            break
        except ValueError:
            print("Entrada inválida. Por favor, ingrese un número entero válido.")

    # Después de validar la entrada, continuamos con el proceso de creación del préstamo.
    prestamo = Prestamo(monto, tasa, cuotas)
    archivo_salida = "amortizacion.csv"
    prestamo.generar_reporte(archivo_salida)

    # Imprimimos los detalles del préstamo.
    print(f"Monto del préstamo: {monto}")
    print(f"Tasa de interés anual: {tasa}%")
    print(f"Total de cuotas: {cuotas}")
    
    # Mostramos la tabla de amortización.
    print(prestamo.amortizacion)
    
    # Graficamos la amortización.
    prestamo.graficar_amortizacion()

# Verifica si el script es el punto de entrada principal para ejecutar la función main.
if __name__ == "__main__":
    main()



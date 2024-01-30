class Alergia:
    def __init__(self):
        self.alergias = {}

    def agregar_alergia(self, nombre, valor):
        self.alergias[nombre] = valor

    def imprimir_todas(self):
        for nombre, valor in self.alergias.items():
            print(f"Alergia: {nombre}, Valor: {valor}")

    def imprimir_especifica(self, nombre):
        if nombre in self.alergias:
            valor = self.alergias[nombre]
            print(f"Alergia: {nombre}, Valor: {valor}")
        else:
            print(f"No se encontró la alergia: {nombre}")

# Creación de la instancia de la clase Alergia y adición de las alergias
gestor_alergias = Alergia()
alergias_a_agregar = {
    "Huevos": 1, "Cacahuetes": 2, "Mariscos": 4, "Fresas": 8, "Tomates": 16,
    "Chocolate": 32, "Polen": 64, "Gatos": 128, "Sardinas": 256, "Gluten": 512,
    "Almendras": 536870912, "Canela": 1073741824, "Altramuces": 2147483648, 
    "Mantequilla": 4294967296, "Pepino": 8589934592, "Cangrejo": 17179869184, 
    "Almejas": 34359738368, "Anacardos": 68719476736, "Coliflor": 137438953472, 
    "Pimienta": 274877906944, "Arándanos": 549755813888, "Pera": 1099511627776, 
    "Cerveza": 2199023255552, "Guisantes": 4398046511104, "Ciruelas": 8796093022208, 
    "Trigo": 17592186044416, "Higos": 35184372088832, "Centeno": 70368744177664, 
    "Pistachos": 140737488355328, "Cangrejo de río": 281474976710656, "Col": 562949953421312,
    "Huevo": 1024, "Nueces": 2048, "Leche": 4096, "Soja": 8192, "Miel": 16384,
    "Piña": 32768, "Ajo": 65536, "Maíz": 131072, "Kiwi": 262144, "Menta": 524288,
    "Gambas": 1048576, "Apio": 2097152, "Pescado": 4194304, "Manzanas": 8388608,
    "Cilantro": 16777216, "Aguacate": 33554432, "Zanahorias": 67108864, "Berenjenas": 134217728,
    "Lentejas": 268435456
}


for nombre, valor in alergias_a_agregar.items():
    gestor_alergias.agregar_alergia(nombre, valor)

# Ejemplo de uso
#gestor_alergias.imprimir_todas()
#print("\nEjemplo de alergia específica:")
#gestor_alergias.imprimir_especifica("Chocolate")

# Definición de la clase EvaluacionEspecifica
class EvaluacionEspecifica:
    def __init__(self, gestor_alergias):
        self.gestor_alergias = gestor_alergias

    def evaluar_alergias(self, puntuacion):
        alergias_personales = []
        for nombre, valor in self.gestor_alergias.alergias.items():
            if puntuacion & valor:
                alergias_personales.append((nombre, valor))
        return alergias_personales

    def imprimir_evaluacion(self, puntuacion):
        alergias_personales = self.evaluar_alergias(puntuacion)
        print(f"Puntuación total de alergias: {puntuacion}")
        if alergias_personales:
            print("Desglose de alergias:")
            for nombre, valor in alergias_personales:
                print(f"- {nombre} (Valor: {valor})")
        else:
            print("No se encontraron alergias para esta puntuación.")

# Ejemplo de uso con la puntuación 34
#evaluador = EvaluacionEspecifica(gestor_alergias)
#evaluador.imprimir_evaluacion(33)

# Definición de la clase TiposDeAlergias
class TiposDeAlergias:
    def __init__(self, gestor_alergias):
        # Acceso a la clase Alergia para comparar con las entradas del usuario
        self.gestor_alergias = gestor_alergias
        # Almacenamiento de las alergias ingresadas por el usuario
        self.alergias_usuario = []
        # Almacenamiento de nombres y valores no coincidentes
        self.nombres_no_encontrados = []
        self.valores_no_encontrados = []

    def agregar_alergia(self, nombre=None, valor=None):
        # Verificar si se ha ingresado nombre, valor o ambos
        if nombre and valor:
            # Si se ingresa nombre y valor, se verifica si coinciden con los existentes
            if valor in self.gestor_alergias.alergias.values() and nombre in self.gestor_alergias.alergias:
                self.alergias_usuario.append((nombre, valor))
            else:
                # Si no coinciden, se agregan a las listas de no encontrados
                if nombre not in self.gestor_alergias.alergias:
                    self.nombres_no_encontrados.append(nombre)
                if valor not in self.gestor_alergias.alergias.values():
                    self.valores_no_encontrados.append(valor)
        elif nombre:
            # Solo se ingresa el nombre
            if nombre in self.gestor_alergias.alergias:
                self.alergias_usuario.append((nombre, self.gestor_alergias.alergias[nombre]))
            else:
                self.nombres_no_encontrados.append(nombre)
        elif valor:
            # Solo se ingresa el valor
            encontrado = False
            for nom, val in self.gestor_alergias.alergias.items():
                if val == valor:
                    self.alergias_usuario.append((nom, valor))
                    encontrado = True
                    break
            if not encontrado:
                self.valores_no_encontrados.append(valor)

    def imprimir_alergias_usuario(self):
        print("Alergias del usuario:", self.alergias_usuario)
        print("Nombres de alergias no encontrados:", self.nombres_no_encontrados)
        print("Valores de alergias no encontrados:", self.valores_no_encontrados)

# Creación de la instancia de la clase TiposDeAlergias
gestor_tipos_de_alergias = TiposDeAlergias(gestor_alergias)

# Ejemplos de agregado de alergias por el usuario
#gestor_tipos_de_alergias.agregar_alergia(nombre="Polen")  # Solo nombre
#gestor_tipos_de_alergias.agregar_alergia(valor=128)       # Solo valor
#gestor_tipos_de_alergias.agregar_alergia("Perros", 256)   # Nombre y valor que no coinciden
#gestor_tipos_de_alergias.agregar_alergia("Manzanas", 8388608)  # Nombre y valor que coinciden

# Imprimir las alergias del usuario y las listas de no coincidentes
#gestor_tipos_de_alergias.imprimir_alergias_usuario()


# Definición de la clase EvaluacionGeneral 
class EvaluacionGeneral:
    def __init__(self, alergias_usuario, nombres_no_encontrados, valores_no_encontrados):
        # Alergias del usuario ya evaluadas (nombre y valor)
        self.alergias_usuario = alergias_usuario
        # Almacenamiento de alergias con nombre pero sin valor y viceversa
        self.alergias_sin_puntuacion = nombres_no_encontrados
        self.alergias_desconocidas = valores_no_encontrados

    def calcular_puntuacion_general(self):
        # Calcula la puntuación general sumando los valores de todas las alergias conocidas
        return sum(valor for _, valor in self.alergias_usuario)

    def calcular_promedio(self):
        # Calcular el promedio de las alergias conocidas y desconocidas
        total_conocido = sum(valor for _, valor in self.alergias_usuario)
        total_desconocido = len(self.alergias_desconocidas)
        return (total_conocido + total_desconocido) / (len(self.alergias_usuario) + total_desconocido) if total_desconocido > 0 else total_conocido

    def imprimir_resultados(self):
        print("Puntuación General de Alergias:", self.calcular_puntuacion_general())
        print("Alergias sin Puntuación:", self.alergias_sin_puntuacion)
        print("Resultados Desconocidos:", self.alergias_desconocidas)
        print("Promedio de Alergias Conocidas y Desconocidas:", self.calcular_promedio())

# El usuario agrega alergias (estos datos normalmente vendrían de la entrada del usuario)
gestor_tipos_de_alergias.agregar_alergia(nombre="Chocolate", valor=32)
gestor_tipos_de_alergias.agregar_alergia(nombre="Polen", valor=64)
gestor_tipos_de_alergias.agregar_alergia(nombre="Nuez desconocida", valor=1000)  # Ejemplo de no coincidencia


# Creación de la instancia de EvaluacionGeneral con los datos procesados
evaluador_general = EvaluacionGeneral(
    gestor_tipos_de_alergias.alergias_usuario, 
    gestor_tipos_de_alergias.nombres_no_encontrados, 
    gestor_tipos_de_alergias.valores_no_encontrados
)

# Uso del evaluador para calcular puntuaciones y promedios
evaluador_general.imprimir_resultados()

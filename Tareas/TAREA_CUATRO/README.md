# Tarea 4

## Parte Teórica
### Diferencia entre una lista y una tupla en Python.
- **Lista:**
  - Mutable: Su contenido puede cambiar.
  - Sintaxis: Se define con corchetes `[]`.
  - Ejemplo: `mi_lista = [1, 2, 3]`

- **Tupla:**
  - Inmutable: Su contenido no puede cambiar una vez creada.
  - Sintaxis: Se define con paréntesis `()`.
  - Ejemplo: `mi_tupla = (1, 2, 3)`

###  Sobrecarga de operadores en Python y cómo se implementa.
La sobrecarga de operadores permite que los operadores estándar como `+`, `-`, `*`, etc., tengan un comportamiento diferente según el tipo de datos con los que se usan.

- **Implementación:**
  - Se realiza definiendo métodos especiales en la clase.
  - Ejemplo: Para sobrecargar `+`, se define el método `__add__(self, other)`.

```python
class Numero:
    def __init__(self, valor):
        self.valor = valor

    def __add__(self, otro):
        return Numero(self.valor + otro.valor)

n1 = Numero(5)
n2 = Numero(3)
n3 = n1 + n2  # Utiliza el método __add__
```
###  Concepto de 'alcance' (scope) de una variable en Python.
El 'alcance' se refiere a la región de un programa donde una variable es accesible.

- **Tipos de Alcance:**
  - Local: Dentro de la función actual.
  - Enclosing: Dentro de las funciones anidadas.
  - Global: A nivel del módulo.
  - Built-in: En el ámbito de los nombres incorporados (nativos de Python).

```python
x = "global"  # Variable global

def funcion():
    y = "local"  # Variable local
    print(x)
    print(y)

funcion()
```
### Decorador en Python y cuál es su función principal.
Un decorador es una función que toma otra función como argumento, añade alguna funcionalidad y retorna una función. Los decoradores permiten modificar el comportamiento de una función o método.

- **Función Principal:**
  - Añadir funcionalidad a una función existente sin modificar su estructura.

```python
def mi_decorador(func):
    def envoltura():
        print("Algo antes de la función.")
        func()
        print("Algo después de la función.")
    return envoltura

@mi_decorador
def decir_hola():
    print("Hola!")

decir_hola()  # Imprime: Algo antes de la función. Hola! Algo después de la función.
```
###  Gestion de las excepciones en Python
La gestión de excepciones se realiza mediante bloques `try`, `except`, `else` y `finally`.

- **Estructura:**
  - `try`: Código que puede causar una excepción.
  - `except`: Código que se ejecuta si hay una excepción.
  - `finally`: Código que se ejecuta siempre, independientemente de si hay una excepción o no.

```python
try:
    x = 1 / 0
except ZeroDivisionError:
    print("No se puede dividir por cero.")
finally:
    print("Bloque finally ejecutado.")
```
### Generadores en Python
Los generadores son una forma sencilla de crear iteradores. Se definen como funciones regulares pero utilizan la sentencia `yield` para devolver datos.

- **Uso:**
  - Para iterar sobre secuencias de datos sin la necesidad de crear y almacenar la secuencia completa en la memoria.

```python
def generador_numeros():
    yield 1
    yield 2
    yield 3

for numero in generador_numeros():
    print(numero)  # Imprime 1, luego 2 y finalmente 3
```

### Diferencia entre `__init__` y `__call__` en Clases de Python
- **`__init__`:**
  - Método constructor de una clase.
  - Se llama automáticamente cuando se crea una instancia de la clase.
  - Utilizado para inicializar los atributos del objeto.

- **`__call__`:**
  - Permite que una instancia de la clase se comporte como una función.
  - Se llama cuando la instancia se 'llama' como si fuera una función.

```python
class Ejemplo:
    def __init__(self, valor):
        self.valor = valor

    def __call__(self):
        print(f"Llamada como función con valor {self.valor}")

obj = Ejemplo(10)
obj()  # Llama al método __call__
```
### Diferencia entre `append()` e `extend()` en Listas de Python

- **`append()`:**
  - Añade un elemento al final de la lista.
  - Si se añade una lista, esta se inserta como un único elemento.

- **`extend()`:**
  - Extiende la lista agregando elementos de un iterable al final.
  - Todos los elementos del iterable se añaden individualmente.

```python
lista = [1, 2, 3]
lista.append([4, 5])    # Resultado: [1, 2, 3, [4, 5]]
lista.extend([6, 7])    # Resultado: [1, 2, 3, [4, 5], 6, 7]
```

### Diferencia entre Método de Clase y Método Estático en Python

- **Método de Clase (`@classmethod`):**
  - Recibe la clase como primer argumento en lugar de la instancia.
  - Se utiliza para crear fábricas o métodos que operan en la clase en sí.

- **Método Estático (`@staticmethod`):**
  - No recibe un argumento implícito.
  - Se utiliza como una función normal pero se relaciona con la clase por su contexto.

```python
class MiClase:
    @classmethod
    def metodo_clase(cls):
        return cls()

    @staticmethod
    def metodo_estatico():
        print("Método estático llamado")

MiClase.metodo_clase()    # Crea una instancia de MiClase
MiClase.metodo_estatico() # Llama al método estático
```
### Herencia Simple vs. Herencia Múltiple en Python

- **Herencia Simple:**
  - Una clase deriva de una única clase base.
  - Facilita la reutilización de código y la extensión de las funcionalidades de la clase base.

- **Herencia Múltiple:**
  - Una clase puede derivar de múltiples clases base.
  - Combina características y comportamientos de todas las clases base.

```python
class Base1:
    pass

class Base2:
    pass

class DerivadaSimple(Base1):
    pass

class DerivadaMultiple(Base1, Base2):
    pass
```

### Manejo de Errores de Importación de Módulos en Python
Los errores de importación se manejan utilizando un bloque `try-except`. Se intenta importar el módulo y, en caso de error, se captura la excepción `ImportError`.

```python
try:
    import modulo_inexistente
except ImportError:
    print("El módulo no pudo ser importado.")
```
### Clase vs Objeto en Python

- **Clase:**
  - Es una plantilla para crear objetos.
  - Define atributos y comportamientos para los objetos.

- **Objeto:**
  - Es una instancia de una clase.
  - Posee un estado (atributos) y comportamiento (métodos) definidos por su clase.

```python
class Vehiculo:
    pass

mi_coche = Vehiculo()  # mi_coche es un objeto de la clase Vehiculo
```
### Clase Abstracta vs. Interfaz en Python

- **Clase Abstracta:**
  - No se pueden instanciar directamente.
  - Pueden tener métodos implementados y no implementados (abstractos).

- **Interfaz (en Python, a menudo implementada a través de clases abstractas):**
  - Define un "contrato" o conjunto de métodos que las clases derivadas deben implementar.
  - No suele tener implementación de métodos.

```python
from abc import ABC, abstractmethod

class MiInterfaz(ABC):
    @abstractmethod
    def mi_metodo(self):
        pass
```
### Sobreescritura de Métodos en Python

La sobreescritura de métodos ocurre cuando una clase derivada ofrece una implementación diferente de un método heredado de su clase base.

- **Cómo se Realiza:**
  - Definiendo un método en la clase derivada con el mismo nombre que el método en la clase base.

```python
class Base:
    def saludar(self):
        print("Hola desde la clase base")

class Derivada(Base):
    def saludar(self):
        print("Hola desde la clase derivada")

obj = Derivada()
obj.saludar()  # Imprime: Hola desde la clase derivada
```
## Parte Práctica: Rendimiento 
**Medición de Tiempo de Ejecución**

| Cantidad de Alergias | Ejecuciones | Tiempo Promedio por Ejecución (segundos) |
|----------------------|-------------|------------------------------------------|
| 10                   | 100         | 7.268000008480157e-06                    |
| 50                   | 100         | 1.4238999974622856e-05                   |
| 100                  | 100         | 1.651400001719594e-05                    |
| 200                  | 100         | 3.569299999071518e-05                    |

Los resultados sugieren que el tiempo de ejecución crece con el número de alergias, lo cual es esperado. Sin embargo, el crecimiento no parece ser lineal, indicando que hay eficiencia en la forma en que se manejan las alergias a medida que el conjunto de datos se vuelve más grande. El uso de un diccionario (self.alergias) es eficiente para este propósito además de optimizar el proceso de busqueda en las demás clases.
**Perfilado del Código**
| Función                            | ncalls | tottime  | percall  | cumtime  | percall  |
|------------------------------------|--------|----------|----------|----------|----------|
| `<built-in method builtins.input>` | 13     | 59.695s  | 4.592s   | 59.695s  | 4.592s   |
| `<built-in method builtins.print>` | 118    | 0.060s   | 0.001s   | 0.060s   | 0.001s   |
| `agregar_alergia`                  | 2      | 0.000s   | 0.000s   | 0.000s   | 0.000s   |
| `imprimir_todas`                   | 1      | 0.002s   | 0.002s   | 0.036s   | 0.036s   |
| `imprimir_especifica`              | 1      | 0.000s   | 0.000s   | 0.001s   | 0.001s   |
| `menu_principal`                   | 1      | 0.000s   | 0.000s   | 59.758s  | 59.758s  |
| `evaluar_puntuacion_alergia`       | 1      | 0.000s   | 0.000s   | 2.433s   | 2.433s   |
| `agregar_alergia_usuario`          | 1      | 0.000s   | 0.000s   | 3.920s   | 3.920s   |
| `agregar_nueva_alergia`            | 1      | 0.000s   | 0.000s   | 9.080s   | 9.080s   |
| `evaluar_alergias_usuario`         | 1      | 0.000s   | 0.000s   | 0.002s   | 0.002s   |
| `buscar_alergia_por_nombre`        | 1      | 0.000s   | 0.000s   | 4.074s   | 4.074s   |

Según los datos obtenidos  la mayor parte del tiempo se gasta en {built-in method builtins.input}, lo cual indica que el programa pasa la mayor parte del tiempo esperando la entrada del usuario. Este es un comportamiento esperado para programas interactivos, pero para pruebas de rendimiento, esto puede distorsionar la comprensión del rendimiento real del código.

Uso de la Función print: Se observa una cantidad significativa de tiempo en {built-in method builtins.print}, lo que sugiere que hay muchas operaciones de impresión. Aunque individualmente no consumen mucho tiempo, podrían sumarse y afectar el rendimiento en ciertos contextos.

Eficiencia de las Funciones de Gestión de Alergias: Las funciones relacionadas con la gestión de alergias (agregar_alergia, imprimir_todas, imprimir_especifica, etc.) consumen muy poco tiempo. Esto indica que estas partes del programa son eficientes.

### Conclusión y Recomendaciones

1. **Automatización de Entradas para Pruebas**: 
   - Automatizar entradas para que el tiempo de espera del usuario no afecte las mediciones.

2. **Revisión de Salidas en Consola**: 
   - Reducir las llamadas a `print`, especialmente en bucles.

3. **Enfoque en la Experiencia del Usuario**: 
   - Mejorar la interacción y la presentación de resultados para el usuario.

4. **Análisis Continuo**: 
   - Utilizar `cProfile` para monitorear el impacto de cualquier cambio en el rendimiento.onclusión y Recomendaciones

1. **Automatización de Entradas para Pruebas**: 
   - Automatizar entradas para que el tiempo de espera del usuario no afecte las mediciones.

2. **Revisión de Salidas en Consola**: 
   - Reducir las llamadas a `print`, especialmente en bucles.

3. **Enfoque en la Experiencia del Usuario**: 
   - Mejorar la interacción y la presentación de resultados para el usuario.

4. **Análisis Continuo**: 
   - Utilizar `cProfile` para monitorear el impacto de cualquier cambio en el rendimiento.
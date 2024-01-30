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


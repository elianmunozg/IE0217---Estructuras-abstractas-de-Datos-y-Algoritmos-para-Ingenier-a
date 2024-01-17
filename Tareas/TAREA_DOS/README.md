# Tarea Dos
Este programa consiste en una biblioteca virtua la cual ofrece la una serie de funcionalidades como buscar por nombre, además de poder eliminar algún objeto de la lista o poder agregarlo, otra funcionalidad se basa en poder ordenarlos por precio o por categoría de material, si es audiovisual o lectura.



## Parte Teórica 



### 1. Conceptos Fundamentales de OOP
- **Definición**: La Programación Orientada a Objetos es un paradigma de programación basado en el concepto de "objetos", que pueden contener datos en forma de campos (atributos) y código en forma de procedimientos (métodos).
- **Principios Fundamentales**:
  - **Encapsulamiento**: Ocultamiento del estado interno de los objetos para proteger la integridad de los datos.
  - **Abstracción**: Enfocarse en las características esenciales de un objeto, ignorando detalles irrelevantes.
  - **Herencia**: Capacidad de crear una nueva clase a partir de una existente.
  - **Polimorfismo**: Habilidad de objetos de diferentes clases para ser tratados como instancias de una clase común.

### 2. Herencia en OOP
- **Definición**: Permite que una clase (subclase) herede atributos y métodos de otra clase (superclase).
- **Ejemplo Práctico**: Una clase `Vehículo` puede ser heredada por clases como `Automóvil` y `Bicicleta`, que comparten atributos comunes de `Vehículo`, pero también tienen sus propios atributos específicos.

### 3. Encapsulamiento en OOP
- **Definición**: Es el proceso de ocultar los detalles internos del funcionamiento de un objeto y exponer solo lo necesario.
- **Importancia**: Previene la modificación accidental del estado interno del objeto.
- **Implementación en C++**: Se logra usando especificadores de acceso como `private`, `protected` y `public`.
  - **Ejemplo**: Un atributo marcado como `private` no puede ser accedido directamente desde fuera de la clase.

### 4. Polimorfismo en C++
- **Definición**: Capacidad de una interfaz para adoptar múltiples formas.
- **Polimorfismo de Tipo**: Se logra a través de la herencia, permitiendo que objetos de diferentes clases sean tratados como objetos de una clase común.
- **Polimorfismo de Operador**: Es la sobrecarga de operadores, donde el mismo operador tiene diferentes implementaciones dependiendo de sus argumentos.
  - **Ejemplo**: El operador `+` puede ser sobrecargado para sumar no solo números, sino también concatenar cadenas.

### 5. Abstracción en OOP
- **Definición**: Es el proceso de identificar los aspectos esenciales de una entidad y omitir detalles menos importantes.
- **Relación con OOP**: Facilita la gestión de complejidades al modelar entidades del mundo real como objetos de programación.
- **Aplicación Práctica**: En la creación de clases, se enfoca en atributos y comportamientos relevantes, omitiendo detalles que no son cruciales para el propósito de la clase.
  - **Ejemplo**: En una clase `Automóvil`, se pueden incluir atributos como `marca` y `modelo`, pero omitir detalles como el color de los asientos, a menos que sea relevante para el contexto del programa.

## Continuación: Conceptos de Programación Orientada a Objetos (OOP) y C++

### 6. Clases y Objetos
- **Diferencia**:
  - **Clase**: Es una plantilla o un molde para crear objetos. Define propiedades (atributos) y comportamientos (métodos) de los objetos.
  - **Objeto**: Es una instancia de una clase. Un objeto representa un elemento concreto que ha sido creado usando la plantilla de una clase.
- **Ejemplo**:
  - **Clase**: `Automóvil`, con atributos como `marca` y `modelo`, y métodos como `arrancar()` y `detener()`.
  - **Objeto**: Un objeto específico de `Automóvil`, como un `Automóvil miCoche = new Automóvil("Toyota", "Corolla");`.

### 7. Métodos Virtuales en C++
- **Importancia**: Permiten que una clase derivada proporcione una implementación específica de un método que ya está definido en su clase base.
- **Uso en Polimorfismo**: Permiten que las llamadas a métodos sean resueltas en tiempo de ejecución, lo cual es esencial para implementar polimorfismo en C++.
- **Ejemplo**: 
  - Una clase base `Animal` tiene un método virtual `hacerSonido()`. Las clases derivadas como `Perro` y `Gato` pueden tener su propia implementación de `hacerSonido()`.

### 8. Constructores y Destructores
- **Constructor**: Método especial en una clase que se llama cuando se crea un objeto de esa clase. Su propósito es inicializar el objeto.
- **Destructor**: Método que se llama cuando un objeto está a punto de ser destruido. Se usa para liberar recursos.
- **Ejemplos**:
  - **Constructor**: `Automóvil(String marca, String modelo)` que inicializa un nuevo automóvil con una marca y un modelo específicos.
  - **Destructor**: `~Automóvil()` que podría liberar recursos o realizar tareas de limpieza necesarias cuando un objeto de `Automóvil` se destruye.

### 9. Sobrecarga de Operadores en C++
- **Definición**: La sobrecarga de operadores permite definir o modificar el comportamiento de los operadores estándar (`+`, `-`, `*`, etc.) para trabajar con tipos de datos definidos por el usuario.
- **Ejemplo**: Sobrecargar el operador `+` para concatenar objetos de una clase `Cadena` en lugar de sumar números.

### 10. Templates en C++
- **Concepto**: Los templates permiten crear clases y funciones que pueden operar con cualquier tipo de dato. Esto permite escribir código genérico.
- **Utilidad**: Son útiles en situaciones donde necesitas funciones o clases que funcionan de manera similar para distintos tipos de datos.
  - **Ejemplo**: Una clase `Array<T>` que puede almacenar elementos de cualquier tipo `T` (como `int`, `float`, `string`, etc.).

### 11.Memoria Dinámica en C++
 La memoria dinámica se refiere a la asignación de memoria en tiempo de ejecución. Se utiliza cuando no se conoce la cantidad de memoria que se necesitará durante la compilación o cuando se necesita una cantidad de memoria que puede cambiar durante la ejecución de un programa. La memoria dinámica se gestiona en C++ a través de operadores como new y delete.

 ### 12. Diferencia entre `new` y `malloc` en C++
- **`new`**: Es un operador en C++ que asigna memoria y llama al constructor del objeto.
- **`malloc`**: Es una función en C que solo asigna memoria, sin inicializarla.
- **Cuándo usar**:
  - Utiliza `new` para objetos en C++ para asegurar la correcta inicialización.
  - `malloc` es menos común en C++, preferido si se necesita compatibilidad con C o asignación de memoria sin construcción.

### 13. Fuga de Memoria (Memory Leak) en C++
- **Definición**: Ocurre cuando un programa en C++ reserva memoria dinámicamente y no la libera apropiadamente.
- **Prevención**:
  - Asegúrate de liberar la memoria usando `delete` o `delete[]` después de usar `new`.
  - Usa punteros inteligentes que gestionan automáticamente la memoria.

### 14. Punteros Inteligentes (Smart Pointers)
- **Definición**: Son clases template que proporcionan la funcionalidad de un puntero mientras garantizan la liberación automática de memoria.
- **Ejemplos**:
  - `std::unique_ptr`: Puntero único que posee y gestiona otro objeto a través de un puntero.
  - `std::shared_ptr`: Puntero que mantiene un contador de referencias para permitir que múltiples punteros compartan la propiedad del objeto.

### 15. Diferencia entre `delete` y `delete[]`
- **`delete`**: Se usa para liberar la memoria asignada para un solo objeto.
- **`delete[]`**: Se usa para liberar la memoria asignada para un arreglo de objetos.
- **Contexto de Uso**:
  - Usa `delete` para objetos individuales creados con `new`.
  - Usa `delete[]` para arreglos de objetos creados con `new[]`.

### 16. Algoritmos de Ordenamiento
- **Definición**: Son algoritmos que reorganizan una secuencia de elementos en un orden específico (como ascendente o descendente).
- **Importancia**: Son fundamentales para la eficiencia de los programas y se usan en tareas como búsqueda de datos y optimización de procesos.

### 17. Bubble Sort
- **Funcionamiento**: Repite el paso de pasar por la lista, comparando elementos adyacentes y los intercambia si están en el orden incorrecto.
- **Complejidad Temporal en el Peor Caso**: O(n^2), donde n es el número de elementos.

### 18. QuickSort
- **Descripción**: Selecciona un 'pivote' y divide la lista en elementos menores y mayores que el pivote, y luego ordena las sublistas de manera similar.
- **Ventaja Principal**: Eficiencia en el promedio y mejor caso, con una complejidad temporal promedio de O(n log n).

### 19. Algoritmos de Ordenamiento Estable vs Inestable
- **Estable**: Mantiene el orden relativo de registros con claves iguales. En otras palabras, si dos elementos son iguales según la clave de ordenamiento, su orden relativo se preserva en el resultado final.
  - **Ejemplo**: Merge Sort es un ejemplo de un algoritmo de ordenamiento estable.
- **Inestable**: No garantiza mantener el orden relativo de registros con claves iguales. Esto significa que, para dos elementos iguales según la clave de ordenamiento, su orden relativo podría cambiar en el resultado final.
  - **Ejemplo**: QuickSort es un ejemplo de un algoritmo de ordenamiento inestable.

### 20. Algoritmo de Ordenamiento "Merge Sort"
- **Descripción**: Merge Sort es un algoritmo de dividir para conquistar que divide la lista en mitades, ordena cada una de ellas (usando Merge Sort recursivamente) y luego las combina. Es muy eficiente para listas grandes.
- **Complejidad Temporal**:
  - **General**: O(n log n), donde `n` es el número de elementos a ordenar. Esta complejidad se mantiene en el mejor, promedio y peor caso.
- **Situaciones Preferibles de Uso**:
  - Ideal para listas grandes donde la estabilidad del ordenamiento es importante.
  - Funciona bien con listas enlazadas, ya que no requiere espacio adicional para almacenar listas temporales.
  - Es una buena opción cuando se tienen datos que no caben en la memoria y deben ser ordenados en un medio de almacenamiento externo (como un disco duro).
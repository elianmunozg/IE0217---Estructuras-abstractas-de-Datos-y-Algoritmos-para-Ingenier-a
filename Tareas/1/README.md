# Tarea 1
## Parte Teórica
### 1. Principal diferencia entre C y C++:

- C es un lenguaje de programación procedimental.
- C++ es un lenguaje de programación orientado a objetos que también admite programación procedimental.
- C++ extiende C añadiendo características como clases, herencia, polimorfismo y encapsulamiento.

### 2. Diferencias fundamentales entre lenguajes compilados e interpretados:

- **Lenguaje compilado:**
  - Se traduce completamente a código de máquina antes de ejecutarse (ejemplo: C++).
  - Mayor rendimiento.

- **Lenguaje interpretado:**
  - Se traduce línea por línea durante la ejecución (ejemplo: Python).
  - Mayor portabilidad y flexibilidad.

### 3. Linker en el contexto de lenguajes compilados:

- Un linker combina varios módulos de código objeto en un programa ejecutable.
- Su función principal es resolver las referencias simbólicas y direcciones de memoria.

### 4. Diferencias clave entre tipos de datos derivados y primarios en C++:

- **Primarios:** Representan datos básicos como int, float, char.
- **Derivados:** Construidos a partir de tipos primarios, incluyen arrays, punteros y estructuras.

### 5. Inicializar y declarar una variable:

- **Declarar:** Anunciar el tipo y nombre de la variable.
- **Inicializar:** Asignar un valor a la variable en el momento de la declaración.

### 6. Sobrecarga de funciones en C++:

- Permite definir varias funciones con el mismo nombre pero con diferentes parámetros.
- Beneficios: Mayor flexibilidad y legibilidad del código.

### 7. Puntero en C++:

- Almacena la dirección de memoria de una variable.
- Ejemplo: `int* ptr = &variable;`.

### 8. Variable global en funciones:

- Almacena una copia del valor original de la variable.
- Se elige usar variables globales por su accesibilidad en diferentes funciones.

### 9. Métodos comunes de la biblioteca string en C++:

- `length()`: Devuelve la longitud de la cadena.
- `append(str)`: Añade otra cadena al final.
- `substr(pos, len)`: Devuelve una subcadena.

### 10. Diferencia entre bucle do-while y while:

- **do-while:** Garantiza que el bucle se ejecute al menos una vez, ya que la condición se verifica después de la primera ejecución.
- **while:** Verifica la condición antes de la primera ejecución.



### 11 Almacenar funciones en una estructura en C++ y encapsulamiento:
En C++, no es posible almacenar funciones directamente dentro de una estructura. Sin embargo, se pueden utilizar punteros a funciones para lograr funcionalidades similares. En cuanto al encapsulamiento, los datos sí se pueden encapsular en miembros privados y públicos dentro de una estructura para controlar el acceso.

### 12. División común de código en archivos .hpp, .cpp y main.cpp:

Es común dividir el código en archivos:

- **.hpp (Header):** Contiene las declaraciones de clases, funciones y variables globales.
- **.cpp (Implementation):** Contiene las definiciones de las funciones declaradas en el archivo .hpp.
- **main.cpp:** Contiene la función principal `main()` y sirve como punto de entrada del programa.
Este enfoque facilita la modularidad y el mantenimiento del código.

### 13. Type Casting en C++:

El Type Casting convierte un tipo de dato en otro. Se puede realizar de tres formas:

- **Estático (C++ Style):** `tipoDeseado(variable)`.
- **Estático (C Style):** `(tipoDeseado) variable`.
- **Dinámico (dynamic_cast):** Utilizado en herencia de clases.




### 14. Sentencia goto en C++:

El uso de `goto` no es recomendado porque puede generar código difícil de entender y mantener. En su lugar, se pueden utilizar estructuras de control como bucles (`for`, `while`) y estructuras condicionales (`if`, `switch`) para lograr el mismo resultado.

### 15. Almacenamiento de variables en C++:

Las variables locales se almacenan en la pila, mientras que las variables globales en el segmento de datos. La diferencia principal radica en su alcance y duración.

### 16. Diferencia entre pasar parámetros por valor, por referencia y por puntero:

- **Por valor:** Se pasa una copia del valor original.
- **Por referencia:** Se pasa la dirección de memoria para permitir modificaciones directas.
- **Por puntero:** Se pasa la dirección de memoria, similar a la referencia.

### 17. Puntero para apuntar a un arreglo en C++:

Un puntero que apunta a un arreglo en C++ inicialmente apunta a la primera posición del arreglo. Se puede acceder a todos los datos mediante la aritmética de punteros.

### 18. Punteros dobles en C++:

Los punteros dobles se utilizan para manejar matrices bidimensionales o estructuras de datos complejas. Permiten acceder a diferentes niveles de memoria.

### 19. Diferencia entre break y continue en bucles:

- **break:** Termina inmediatamente el bucle.
- **continue:** Salta a la siguiente iteración del bucle sin ejecutar el código restante dentro del bucle para esa iteración.

### 20. Uso de la directiva #ifndef:

`#ifndef` se utiliza para evitar la inclusión repetida de un archivo de encabezado en C++. Protege contra la inclusión duplicada.

### 21. Puntero this en C++:

`this` es un puntero implícito que apunta al objeto actual dentro de una clase. Se utiliza para referenciar variables de instancia y métodos dentro de la misma clase.

### 22. Puntero nullptr:

`nullptr` es un puntero nulo introducido en C++11. Se utiliza como un valor nulo específico para punteros, proporcionando claridad y seguridad en comparaciones.

### 23. Diferencia entre un arreglo y una lista en C++:

- **Arreglo:** Estructura de datos estática con tamaño fijo.
- **Lista:** Estructura de datos dinámica que puede cambiar de tamaño durante la ejecución.

### 24. Función prototipo en C++:

Un función prototipo declara la firma de una función antes de su implementación. Se coloca al inicio del código y sirve para informar al compilador sobre la existencia de la función antes de su uso.

### 25. Investigación sobre Memory Leak

Un **memory leak** (fuga de memoria) ocurre en programación cuando un programa asigna espacio de memoria dinámica (utilizando funciones como `malloc` en C++ o `new` en C++) para almacenar datos, pero no libera adecuadamente ese espacio cuando ya no es necesario. Como resultado, la memoria asignada no está disponible para otros usos, lo que puede llevar a una degradación del rendimiento del programa y, en casos extremos, a la pérdida de memoria considerable.

Las fuentes comunes de memory leaks incluyen:

1. **No liberar memoria:** Cuando un programador asigna memoria dinámicamente pero olvida liberarla antes de que el programa termine, se produce un memory leak.

2. **Pérdida de referencias:** Si se pierden todas las referencias a un bloque de memoria sin liberarlo, la memoria queda inaccesible y se produce un memory leak.

3. **Ciclos de referencia:** En lenguajes de programación con gestión automática de memoria, como algunos en el entorno Java o C#, los memory leaks pueden ocurrir cuando hay ciclos de referencias entre objetos, lo que impide que el recolector de basura los libere.

Detectar y corregir memory leaks es crucial para escribir programas eficientes y estables. Se utilizan herramientas como analizadores de memoria y técnicas de depuración para identificar y solucionar estos problemas. En C++, se puede utilizar `valgrind` u otras herramientas similares para detectar memory leaks durante la ejecución del programa.

Referencia: [Fuga de memoria - Wikipedia](https://es.wikipedia.org/wiki/Fuga_de_memoria)
## Parte Teórica Makefile
### 1. Variables Comunes en un Makefile

- **CC**: Variable que especifica el compilador de C a utilizar.
- **CFLAGS**: Flags para el compilador de C que pueden incluir opciones de optimización, advertencias, etc.
- **CXXFLAGS**: Similar a `CFLAGS`, pero para el compilador de C++.
- **LDFLAGS**: Flags para el enlazador (`ld`), como rutas para bibliotecas.

### 2. Composición de una Regla en un Makefile

Una regla en un Makefile se compone de:
- **Target**: El objetivo a construir.
- **Prerequisites**: Archivos necesarios para construir el target.
- **Recipe**: Comandos ejecutados para construir el target.

### 3. Definición de Target y su Relación con Prerequisites

**Target:**
- Un archivo que se genera o una acción a ejecutar.

**Prerequisites:**
- Archivos o targets que deben estar actualizados antes de construir el target.

**Relación:**
- El target se reconstruye si cualquier prerequisite ha cambiado.

### 4. Banderas del Compilador gcc

- **-I**: Incluye directorios adicionales en la búsqueda de archivos de cabecera.
- **-c**: Compila o ensambla el código fuente, pero no enlaza.
- **-o**: Especifica el nombre del archivo de salida generado.

### 5. Definición y Utilización de Variables en un Makefile

**Definición:**
- Se asigna un valor a una variable con `=` o `:=`.

**Utilización:**
- Se accede al valor con `$(nombre_variable)`.

**Utilidad:**
- Permiten reutilizar valores y facilitar la modificación del Makefile.

### 6. Utilidad del Símbolo @ en un Makefile

- El símbolo `@` al inicio de una receta evita que el comando se imprima en la consola antes de su ejecución.

### 7. Utilidad de .PHONY en un Makefile

**.PHONY:**
- Se utiliza para marcar targets que no representan archivos.

**Utilidad:**
- Asegura que el comando se ejecute incluso si hay un archivo con el mismo nombre del target.

Referencia: [Conceptos básicos de make y los Makefile](https://old.chuidiang.org/clinux/herramientas/makefile.php)
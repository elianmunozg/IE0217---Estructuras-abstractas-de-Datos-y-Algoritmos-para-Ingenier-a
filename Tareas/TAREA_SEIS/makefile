# Makefile para ejecutar el análisis de datos de vehículos

# Definir el comando de Python dependiendo del sistema operativo
ifeq ($(OS),Windows_NT)
    PYTHON_CMD = python
else
    PYTHON_CMD = python3
endif

# Definir la ruta del script principal
MAIN_SCRIPT = src/main.py

# Definir el comando para la ejecución
RUN_COMMAND = $(PYTHON_CMD) $(MAIN_SCRIPT)

# Regla por defecto para ejecutar el programa
all: run

# Regla para ejecutar el script principal
run:
	@echo "Ejecutando el análisis de datos..."
	@$(RUN_COMMAND)

# Regla para limpiar los archivos compilados de Python (archivos .pyc y directorios __pycache__)
clean:
	@echo "Limpiando..."
	@find . -type f -name "*.pyc" -exec rm -f {} +
	@find . -type d -name "__pycache__" -exec rm -rf {} +

# Regla para descargar datos si no están presentes
datos:
	@echo "Descargando datos..."
	@$(PYTHON_CMD) src/descargadedatos.py

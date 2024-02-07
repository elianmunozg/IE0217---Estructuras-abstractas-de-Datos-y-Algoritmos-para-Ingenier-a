# Makefile para Windows usando Anaconda Python

# Comando de Python, asumiendo que 'python' ya está en tu PATH
PYTHON := conda run -n base python

# Directorio de los scripts
SRC_DIR := src

# Definir las reglas
.PHONY: all run_practica1 run_practica2

all: run_practica1 run_practica2

run_practica1:
	@echo Ejecutando practica1.py usando Anaconda Python
	@$(PYTHON) $(SRC_DIR)/practica1.py

run_practica2:
	@echo Ejecutando practica2.py usando Anaconda Python
	@$(PYTHON) $(SRC_DIR)/practica2.py

OS := $(shell uname)

ifeq ($(OS),Linux)
# Comandos para Linux
run:
	@echo "Running on Linux"
	python3 src/alergias.py
else
# Comandos para otros sistemas operativos
run:
	python src/alergias.py
endif

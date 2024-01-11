# Detectar el sistema operativo usando variables de entorno de Windows
ifeq ($(OS),Windows_NT)
    detected_OS := Windows
else
    detected_OS := $(shell uname -s)
endif

# Configuraciones específicas del OS
ifeq ($(detected_OS),Windows)
    CC=g++
    RM=del /Q /F
    EXECUTABLE=adivina.exe
else
    CC=g++
    RM=rm -f
    EXECUTABLE=adivina.x
endif

# Opciones de compilación
CFLAGS=-c -Wall

# Targets
all: build run

build: main.o game.o
	$(CC) main.o game.o -o $(EXECUTABLE)

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

game.o: game.cpp
	$(CC) $(CFLAGS) game.cpp

clean:
	$(RM) *o $(EXECUTABLE)

run:
	./$(EXECUTABLE)


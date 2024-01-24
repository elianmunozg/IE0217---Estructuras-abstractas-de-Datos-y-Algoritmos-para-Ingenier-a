# Makefile

CXX = g++
CXXFLAGS = -Wall -std=c++11

# Define los nombres de tus archivos fuente y de cabecera aquí
SOURCES_MAIN = .\src\main.cpp .\src\Matriz.cpp
HEADERS_MAIN = .\src\Matriz.hpp .\src\OperacionesBasicas.hpp .\src\OperacionCompleja.hpp
OBJECTS_MAIN = $(SOURCES_MAIN:.cpp=.o)
EXECUTABLE_MAIN = matrices.exe

SOURCES_EMAIL = .\src\main2.cpp .\src\EmailValidator.cpp
HEADERS_EMAIL = .\src\EmailValidator.hpp
OBJECTS_EMAIL = $(SOURCES_EMAIL:.cpp=.o)
EXECUTABLE_EMAIL = email_validator.exe

all: $(EXECUTABLE_MAIN) $(EXECUTABLE_EMAIL)

$(EXECUTABLE_MAIN): $(OBJECTS_MAIN)
	$(CXX) $(CXXFLAGS) $(OBJECTS_MAIN) -o $(EXECUTABLE_MAIN)

$(EXECUTABLE_EMAIL): $(OBJECTS_EMAIL)
	$(CXX) $(CXXFLAGS) $(OBJECTS_EMAIL) -o $(EXECUTABLE_EMAIL)

%.o: %.cpp $(HEADERS_MAIN) $(HEADERS_EMAIL)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS_MAIN) $(EXECUTABLE_MAIN) $(OBJECTS_EMAIL) $(EXECUTABLE_EMAIL)

.PHONY: all clean

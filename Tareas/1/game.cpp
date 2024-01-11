#include "game.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <limits>

/**
 * @file game.cpp
 * @brief Implementación de la clase Game para el juego de adivinanzas.
 */

/**
 * @brief Constructor de la clase Game. Inicializa el generador de números aleatorios y establece los valores iniciales.
 */
Game::Game() : minNumber(1), maxNumber(100), secretNumber(0), currentMode(GameMode::STANDARD) {
    std::srand(std::time(0)); // Inicialización del generador de números aleatorios
}


/**
 * @brief Ejecuta el menú principal del juego y maneja la navegación entre diferentes opciones.
 */
void Game::run() {
    int choice = 0;
    do {
        std::cout << "Menú del Juego de Adivinanzas\n";
        std::cout << "1. Iniciar Juego\n";
        std::cout << "2. Elegir Intervalo\n";
        std::cout << "3. Salir\n";
        std::cout << "Selecciona una opción: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                startGame();
                break;
            case 2:
                chooseInterval();
                break;
            case 3:
                std::cout << "Gracias por jugar. ¡Hasta luego!\n";
                break;
            default:
                std::cout << "Opción no válida. Inténtalo de nuevo.\n";
        }
    } while (choice != 3);
}

/**
 * @brief Inicia una nueva partida del juego, permitiendo al usuario adivinar el número secreto.
 */
void Game::startGame() {
     chooseGameMode();
    secretNumber = generateRandomNumber(minNumber, maxNumber);
    int attempts = 0;
    int maxAttempts = std::max(1, static_cast<int>(std::ceil((maxNumber - minNumber) / 3.0)));
    int guess = 0;

    std::cout << "He pensado un número entre " << minNumber << " y " << maxNumber << ". Tienes " << maxAttempts << " intentos. ¡Intenta adivinarlo!" << std::endl;

    while(attempts < maxAttempts) {
        std::cout << "Intento " << (attempts + 1) << ": ";
        std::cin >> guess;

        if(guess == secretNumber) {
            std::cout << "¡Correcto! Has adivinado el número." << std::endl;
            return;
        } else {
            provideHint(guess);
        }

        attempts++;
    }

    std::cout << "Lo siento, has agotado tus intentos. El número era " << secretNumber << "." << std::endl;
}

/**
 * @brief Permite al usuario establecer el intervalo de números para adivinar.
 */
void Game::chooseInterval() {
    int lowerBound, upperBound;

    std::cout << "Establece el límite inferior del intervalo: ";
    while(!(std::cin >> lowerBound)) {
        std::cout << "Entrada inválida. Por favor, introduce un número entero: ";
        std::cin.clear(); // Limpia el estado de error de cin
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Descarta la entrada incorrecta
    }

    std::cout << "Establece el límite superior del intervalo: ";
    while(!(std::cin >> upperBound) || upperBound <= lowerBound) {
        std::cout << "Entrada inválida. Por favor, introduce un número entero mayor que " << lowerBound << ": ";
        std::cin.clear(); // Limpia el estado de error de cin
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Descarta la entrada incorrecta
    }

    minNumber = lowerBound;
    maxNumber = upperBound;
}

/**
 * @brief Genera y proporciona pistas al usuario basadas en su intento de adivinar el número y el modo de juego seleccionado.
 * @param guess El número intentado por el usuario.
 */
void Game::provideHint(int guess) {
    if (currentMode == GameMode::STANDARD) {
        if(guess < secretNumber) {
            std::cout << "El número es mayor." << std::endl;
        } else {
            std::cout << "El número es menor." << std::endl;
        }
    } else { // Modo desafiante
        int diff = std::abs(secretNumber - guess);
        if (diff >= 20) {
            std::cout << "Congelado." << std::endl;
        } else if (diff >= 10) {
            std::cout << "Frío." << std::endl;
        } else if (diff >= 5) {
            std::cout << "Caliente." << std::endl;
        } else {
            std::cout << "Hirviendo." << std::endl;
        }
    }
}

/**
 * @brief Permite al usuario elegir el modo de juego entre estándar y desafiante.
 */
void Game::chooseGameMode() {
    int mode;
    std::cout << "Elige el modo de juego (1 - Estándar, 2 - Desafiante): ";
    std::cin >> mode;
    currentMode = (mode == 2) ? GameMode::CHALLENGING : GameMode::STANDARD;
}
/**
 * @brief Genera un número aleatorio dentro de un intervalo.
 * 
 * @param min El límite inferior del intervalo.
 * @param max El límite superior del intervalo.
 * @return int El número aleatorio generado.
 */
int Game::generateRandomNumber(int min, int max) {
    return min + std::rand() % ((max + 1) - min);
}
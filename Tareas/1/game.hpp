#ifndef GAME_HPP
#define GAME_HPP

/**
 * @file Game.hpp
 * @brief Declaración de la clase Game para el juego de adivinanzas.
 */

class Game {
public:
    /**
     * @brief Enumerado para los modos de juego disponibles.
     */
    enum class GameMode { STANDARD, CHALLENGING };

    /**
     * @brief Constructor de la clase Game.
     */
    Game();

    /**
     * @brief Inicia la ejecución del juego.
     */
    void run();

private:
    int minNumber, maxNumber, secretNumber;
    GameMode currentMode;

    /**
     * @brief Inicia una nueva partida del juego.
     */
    void startGame();

    /**
     * @brief Permite al usuario elegir el intervalo de números para adivinar.
     */
    void chooseInterval();

    /**
     * @brief Proporciona una pista al usuario basada en su último intento y el modo de juego actual.
     * @param guess El último número adivinado por el usuario.
     */
    void provideHint(int guess);

    /**
     * @brief Genera un número aleatorio dentro de un intervalo.
     * @param min El límite inferior del intervalo.
     * @param max El límite superior del intervalo.
     * @return int El número aleatorio generado.
     */
    int generateRandomNumber(int min, int max);

    /**
     * @brief Permite al usuario seleccionar el modo de juego.
     */
    void chooseGameMode();
};

#endif // GAME_HPP

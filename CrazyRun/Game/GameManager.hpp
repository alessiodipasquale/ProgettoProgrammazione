#include "../Utils/includes.hpp"
#include "LevelManager.hpp"

class GameManager {
    public:
        int lv;
        int points;
        int playerPosition;

        void cleanScreen();

        void mainMenu();

        void information();

        void prepare();

        void start();

        void gameOver();

        int kill();

        void nextLevel();

        void resetScore();

        void resetLv();
};
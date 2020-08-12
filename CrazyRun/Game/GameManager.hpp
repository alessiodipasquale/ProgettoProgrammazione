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

        void start(LevelManager run, level *currentLevel);

        void gameOver();

        int kill();

        void prevLevel();

        void nextLevel();

        void resetScore();

        void resetLv();
};
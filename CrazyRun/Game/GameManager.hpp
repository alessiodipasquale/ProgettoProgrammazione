#include "../Utils/includes.hpp"
#include "LevelManager.hpp"

class GameManager {
    public:
        int currentLevel;
        int points;
        int playerPosition;
        int mapHeight;
        int mapWidth;

        void cleanScreen();

        void mainMenu();

        void information();

        void prepare();

        void start();

        int kill();

        void nextLevel();

        void resetScore();
};
#include "./includes.hpp"

class GameManager {
    public:
        int currentLevel = 0;
        int points = 0;
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
};
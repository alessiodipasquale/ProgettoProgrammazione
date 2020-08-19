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

        int collision();

        int collisionControl();

        char getPlayerCommand();

        void initializeMap(char mat[][MAPWIDTH]);

        void mapConstruction(char mat[][MAPWIDTH], char command, int collisionType, level* currentLevel, int viewPosition);

        void print(char mat[][MAPWIDTH]);

        void increasePointsBy(int value);
};
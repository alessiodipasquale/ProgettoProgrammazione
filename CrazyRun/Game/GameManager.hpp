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

        int levelControl(int startingPoints);

        void prevLevel();

        void nextLevel();

        void resetScore();

        void resetLv();

        int collision();

        int collisionControl();

        char getPlayerCommand();

        void initializeMap(char mat[][MAPWIDTH]);

        void mapConstruction(int density, level* currentLevel, LevelManager run, int viewPosition);

        void print(char mat[][MAPWIDTH], int viewPosition, LevelManager run);

        void increasePointsBy(int value);
};
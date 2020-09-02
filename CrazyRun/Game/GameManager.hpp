#include "../Utils/includes.hpp"
#include "LevelManager.hpp"

struct player{
    int numberOfComponents;
    int xCoordinates[10];
    int yCoordinates[10];
    char components[10];
};

class GameManager {
    public:
        int lv;
        int points;
        int bestScore;
        int playerPosition;

        void cleanScreen();

        void mainMenu();

        void information();

        void prepare(player* pl);

        void newLevelAnimations(bool upOrDown);

        void start(LevelManager run, level *currentLevel, player* backupPlayer);

        void playerSelection();

        void initializePlayer(player*pl, player*backupPlayer);

        void gameOver();

        int kill();

        int levelControl(int startingPoints);

        void prevLevel();

        void nextLevel();

        void resetScore();

        void resetLv();

        int collision();

        int collisionControl(player*pl, Collectible*collectiblesMap[][MAPWIDTH]);

        char getPlayerCommand();

        void modifyPlayerPosition(char command, player*pl);

        void initializeMap(char mat[][MAPWIDTH], player*pl, Collectible*collectiblesMap[][MAPWIDTH]);

        void mapConstruction(int density, level* currentLevel, LevelManager run, int viewPosition);

        void print(char mat[][MAPWIDTH], int viewPosition, LevelManager run, player*pl, Collectible*collectiblesMap[][MAPWIDTH]);

        void modifyPointsBy(int value);
};
#include "../Utils/includes.hpp"
#include "../Scenes/Map.hpp"

struct level{
    Map map;
    int levelNumber;
    int startingPoints;
    level* next;
    level* prev;
};

class LevelManager{
    private:
         level *currentLevel = new level;
         Map currentMap;
    public:
        LevelManager(int startingLevel, int startingPoints);

        level* newLevel();

        level* previousLevel();

        level* nextLevel();

        level* getCurrentLevel();

        int generateDensity();

        int generateTime();
};
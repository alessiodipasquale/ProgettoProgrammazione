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
        bonus*bonusListElement;
        malus*malusListElement;
        car*carsListElement;

    public:
        LevelManager(int startingLevel, int startingPoints);

        level* newLevel();

        level* previousLevel();

        level* nextLevel();

        level* getCurrentLevel();

        int generateDensity();

        int generateTime();

        Map getCurrentMap();

        void initializeCollectiblesLists();

        void updateCollectiblesLists(int threshold);

        bonus*getBonusList();

        malus*getMalusList();

        car*getCarList();
};
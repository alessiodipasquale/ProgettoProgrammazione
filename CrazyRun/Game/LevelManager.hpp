#include "../Utils/includes.hpp"
#include "../Scenes/Map.hpp"

//lista di Map, una per ogni livello passato
struct level{
    Map map;
    level* next;
    level* prev;
};
class LevelManager{
    private:
         level *currentLevel = new level;
         Map currentMap;
    public:
        LevelManager(int curr);

        void newLevel();

        void previousLevel();

        void nextLevel();
};
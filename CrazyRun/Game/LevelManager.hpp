#include "../Utils/includes.hpp"

//lista di Map, una per ogni livello passato

class LevelManager{
    public:
        LevelManager();
        
        void start();

        void newLevel();

        void previousLevel();
};
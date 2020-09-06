#include "../Utils/includes.hpp"
#include "./Collectibles.hpp"


class Map {
    public:
        bonus* getBonusList();
        malus* getMalusList();
        car* getCarsList();
        int getLastConsideredZone();
        void generateNewZone(int numberOfBonus, int numberOfMalus, bool car, int level);
        void updateLastConsideredZone();
 
    private:
        int lastConsideredZone = MAPHEIGHT-1;
        bool generationMatrix[MAPHEIGHT][MAPWIDTH];
        bonus*bonusHead = NULL;
        malus*malusHead = NULL;
        car*carHead = NULL;

        void newMalus(int level, int x, int y);

        void newBonus(int level, int x, int y);

        void newCar(int level, int x, int lastConsideredZone);

};
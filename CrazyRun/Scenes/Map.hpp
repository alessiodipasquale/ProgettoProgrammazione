#include "../Utils/includes.hpp"
#include "./Collectibles.hpp"


class Map { //penso che sia utile come classe, ad esempio si può implementare un metodo che prende in input 
            //un collectible e lo inserisce. O comunque per i metodi di scorrimento/movimento etc.
    public:
        bonus* getBonusList();
        malus* getMalusList();
        car* getCarsList();
        int getLastConsideredZone();
        void generateNewZone(int numberOfBonus, int numberOfMalus, bool car, int level);
        void updateLastConsideredZone();
 
    private:
        int lastConsideredZone;

        bool generationMatrix[MAPHEIGHT][MAPWIDTH];

        bonus*bonusHead = NULL;
        malus*malusHead = NULL;
        car*carHead = NULL;

        void newMalus(int level, int x, int y);

        void newBonus(int level, int x, int y);

        void newCar(int level, int x, int lastConsideredZone);

};
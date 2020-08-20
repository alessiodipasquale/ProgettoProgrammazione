#include "../Utils/includes.hpp"
#include "./Collectibles.hpp"


class Map { //penso che sia utile come classe, ad esempio si può implementare un metodo che prende in input 
            //un collectible e lo inserisce. O comunque per i metodi di scorrimento/movimento etc.
    public:
        void calculateDifficult(int level);

        collectible* getBonusList();
        collectible* getMalusList();
        collectible* getCarsList();
        int getLastConsideredZone();
        void generateNewZone(int numberOfBonus, int numberOfMalus, bool car);
        void updateLastConsideredZone();
 
    private:
        int levelOfMalus;
        int levelOfBonus;
        int lastConsideredZone;

        collectible*bonusHead = NULL;
        collectible*malusHead = NULL;
        collectible*carHead = NULL;

        void newMalus();

        void newBonus();

        void newCar();

};
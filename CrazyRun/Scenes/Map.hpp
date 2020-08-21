#include "../Utils/includes.hpp"
#include "./Collectibles.hpp"


class Map { //penso che sia utile come classe, ad esempio si può implementare un metodo che prende in input 
            //un collectible e lo inserisce. O comunque per i metodi di scorrimento/movimento etc.
    public:
        void calculateDifficult(int level);

        bonus* getBonusList();
        malus* getMalusList();
        car* getCarsList();
        int getLastConsideredZone();
        void generateNewZone(int numberOfBonus, int numberOfMalus, bool car);
        void updateLastConsideredZone();
 
    private:
        int levelOfMalus;
        int levelOfBonus;
        int lastConsideredZone;

        bonus*bonusHead = NULL;
        malus*malusHead = NULL;
        car*carHead = NULL;

        void newMalus();

        void newBonus();

        void newCar();

};
#include "../Utils/includes.hpp"
#include "./Collectibles.hpp"


class Map { //penso che sia utile come classe, ad esempio si può implementare un metodo che prende in input 
            //un collectible e lo inserisce. O comunque per i metodi di scorrimento/movimento etc.
    public:
        void calculateLevelDifficult(int level);
 
    private:
        int levelOfMalus;
        int levelOfBonus;

        collectible*bonusHead = NULL;
        collectible*malusHead = NULL;
        collectible*carHead = NULL;

        void newMalus();

        void newBonus();
};
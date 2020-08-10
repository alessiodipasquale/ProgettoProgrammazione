#include "../Utils/includes.hpp"
#include "./Collectible.hpp"
#include "./Collectibles.hpp"

struct collectible{
        Collectible collect;
        collectible *next; 
};
class Map { //penso che sia utile come classe, ad esempio si può implementare un metodo che prende in input 
            //un collectible e lo inserisce. O comunque per i metodi di scorrimento/movimento etc.
    private:
        int level;
        int numberOfMalus;
        int numberOfBonus;
        int width;

        collectible*head;

        void newMalus();

        void newBonus();
};
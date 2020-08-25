#include "../Utils/includes.hpp"

class Collectible { //classe padre di tutti gli oggetti che possono essere incontrati
    protected:
        int xFromStart; //posizione dal bordo sinistro della mappa
        int yFromStart; // distanza rispetto all' inizio del livello 
        int type; // es: 0 per bonus, 1 per malus, 2 per macchina
        char appearance; // carattere o simbolo identificativo
        int level; //livello in cui viene incontrato
        bool moving; //purtroppo la consegna dice che devono esserci altre macchine, che si presuppone non siano ferme come 
                     //gli altri oggetti, quindi se "moving" è true, a ogni refresh l'oggetto si muoverà comunque verso il basso, 
                     //ma meno rispetto agli altri oggetti 
   public:
        void init();
        int getYFromStart();
        int getXFromStart();
        char getAppearance();
};

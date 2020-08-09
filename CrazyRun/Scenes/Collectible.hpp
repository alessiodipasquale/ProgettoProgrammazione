#include "../Utils/includes.hpp"

class Collectible { //classe padre di tutti gli oggetti che possono essere incontrati
    protected:
        int xFromStart; //posizione dal bordo sinistro della mappa
        int yFromStart; // distanza rispetto all' inizio del livello 
        int type; // es: 0 per bonus, 1 per malus
        int value;
        char appearance; // carattere o simbolo identificativo
        int level; //livello in cui viene incontrato
        int power; // non sapevo come altro chiamarlo, ma in sintesi è la "potenza" (che può essere positiva o negativa) 
                   //per equilibrare un po i livelli    
                   // es: un mega zavattaro ha potenza 3 e ti toglie 1000000 punti e sicuramente faremo in modo che non 
                   // compaia i primi livelli, mentre un raffaele di potenza 1 che te ne toglie 5 magari va bene (idem per i bonus)
        bool moving; //purtroppo la consegna dice che devono esserci altre macchine, che si presuppone non siano ferme come 
                     //gli altri oggetti, quindi se "moving" è true, a ogni refresh l'oggetto si muoverà comunque verso il basso, 
                     //ma meno rispetto agli altri oggetti 
        bool gameOver; //facoltativo, ma in caso di incidente con un altra macchina io terminerei il gioco
};
#include "main.hpp"
using namespace std;

//L' idea è di collezionare tutti gli oggetti in una lista di Collectible, in ordine secondo il livello e 
//la distanza in cui vengono incontrati

class Collectible { //classe padre di tutti gli oggetti che possono essere incontrati
    public:
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

class Ramp : public Collectible { //esempio di oggetto "raccoglibile"
    public:
        Ramp() { //il costruttore si fa così in c++

        }
};

class Map { //penso che sia utile come classe, ad esempio si può implementare un metodo che prende in input 
            //un collectible e lo inserisce. O comunque per i metodi di scorrimento/movimento etc.

};

class Game {
    public:
        int currentLevel = 1;
        int points = 0;
        int playerPosition;
        int mapHeight;
        int mapWidth;

        void prepare(){

        }
        void start(){

        } 
};

int main() {
    //Qui va il menù principale, dove metterei logo, play, info (con una legenda di simboli e punteggi), credits, exit, 
    
    Game game;
    game.prepare();
    game.start();
    return 0;
}

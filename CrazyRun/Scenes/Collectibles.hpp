#include "../Utils/includes.hpp"
#include "Collectible.hpp"

class Ramp : public Collectible { //esempio di oggetto "raccoglibile"
    private:
        int baseValue;
        int power;
    public:
        Ramp();
        void init(int level, int x, int y);
};

class Obstacle : public Collectible {
    private:
        int baseValue;
        int power;
    public: 
        Obstacle();
        void init(int level, int x, int y);
};

class Car : public Collectible {
    public: 
        Car();
        void init(int level, int x, int lastConsideredZone);
};


struct bonus{
        Ramp ramp;
        bonus *next; 
};

struct malus{
        Obstacle obstacle;
        malus *next; 
};

struct car{
        Car vehicle;
        car *next; 
};
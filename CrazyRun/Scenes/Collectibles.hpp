#include "../Utils/includes.hpp"
#include "Collectible.hpp"

class Ramp : public Collectible { //esempio di oggetto "raccoglibile"
    public:
        Ramp();

};

class Obstacle : public Collectible {
    public: 
        Obstacle();
};

class Car : public Collectible {
    public: 
        Car();
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
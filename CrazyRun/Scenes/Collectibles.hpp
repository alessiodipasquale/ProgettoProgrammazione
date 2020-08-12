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
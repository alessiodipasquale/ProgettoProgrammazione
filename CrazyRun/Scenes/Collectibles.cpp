#include "Collectibles.hpp"

Ramp::Ramp() { 
    this->type = 0;
    this->baseValue = 50;
    this->appearance = 'R';
    this->moving = false;
}

void Ramp::init(int level, int x, int y){
    this->power = this->baseValue * ((level / 10)+1);
    this->level = level; 
    this->xFromStart = x;
    this->yFromStart = y;
}

Obstacle::Obstacle() {
    this->type = 1;
    this->baseValue = -100;
    this->appearance = 'X';
    this->moving = false;
}

void Obstacle::init(int level, int x, int y){
    this->power = this->baseValue * ((level / 10)+1);
    this->level = level; 
    this->xFromStart = x;
    this->yFromStart = y;
}

Car::Car(){
    this->type = 1;
    this->power = -500;
    this->appearance = 'C';
    this->moving = true;
}

void Car::init(int level, int x, int lastConsideredZone){
    this->xFromStart = x;
    this->yFromStart = (lastConsideredZone - MAPHEIGHT) + YCARSPAWN;
    this->level = level; 

}
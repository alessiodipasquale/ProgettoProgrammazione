#include "Map.hpp"

void Map::newMalus(){
    //numero random
    if(this->bonusHead == NULL){
        this->bonusHead = new bonus;
        this->bonusHead->next = NULL;
        this->bonusHead->ramp.init();
    } 
}

void Map::newBonus(){
    
}

void Map::newCar(){

}

void Map::generateNewZone(int numberOfBonus, int numberOfMalus, bool car){
    if(car) newCar();
    for (int i=0; i<numberOfBonus; i++){
        newBonus();
    }
    for (int i=0; i<numberOfMalus; i++){
        newMalus();
    }
    
}

void Map::calculateDifficult(int level){
    this->levelOfBonus = level/10;
    this->levelOfMalus = level/10;
}

void Map::updateLastConsideredZone(){
    this->lastConsideredZone += MAPHEIGHT;
}

int Map::getLastConsideredZone(){
    return this->lastConsideredZone;
}

bonus* Map::getBonusList(){
    return this->bonusHead;
}

malus* Map::getMalusList(){
    return this->malusHead;
}

car* Map::getCarsList(){
    return this->carHead;
}
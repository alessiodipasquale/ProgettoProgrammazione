#include "Map.hpp"

void Map::newMalus(){
    //numero random 
}

void Map::newBonus(){
    
}

void Map::generateNewZone(){
    
}

void Map::calculateDifficult(int level){
    this->levelOfBonus = level/10;
    this->levelOfMalus = level/10;
}

int Map::getLastConsideredZone(){
    return this->lastConsideredZone;
}

collectible* Map::getBonusList(){
    return this->bonusHead;
}

collectible* Map::getMalusList(){
    return this->malusHead;
}

collectible* Map::getCarList(){
    return this->carHead;
}
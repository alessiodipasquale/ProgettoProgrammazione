#include "Map.hpp"

void Map::newMalus(){
    //numero random 
}

void Map::newBonus(){
    
}

void Map::generateNewZone(int numberOfBonus, int numberOfMalus, bool car){
    
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

collectible* Map::getBonusList(){
    return this->bonusHead;
}

collectible* Map::getMalusList(){
    return this->malusHead;
}

collectible* Map::getCarsList(){
    return this->carHead;
}
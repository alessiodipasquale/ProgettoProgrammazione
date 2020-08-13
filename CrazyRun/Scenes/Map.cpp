#include "Map.hpp"

void Map::newMalus(){
    //numero random 
}

void Map::newBonus(){
    
}

void Map::calculateLevelDifficult(int level){
    this->levelOfBonus = level/10;
    this->levelOfMalus = level/10;
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
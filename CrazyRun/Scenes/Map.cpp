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
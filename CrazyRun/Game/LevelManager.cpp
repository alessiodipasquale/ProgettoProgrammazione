#include "LevelManager.hpp"
//il primo livello lo genera il costruttore 
LevelManager::LevelManager(int startingLevel, int startingPoints){
    this->currentLevel->prev = NULL;
    this->currentLevel->next = NULL;
    this->currentMap = this->currentLevel->map;
    this->currentLevel->levelNumber = startingLevel;
    this->currentLevel->startingPoints = startingPoints;
}

 //si userà next level, che in caso di bisogno richiama new level
level* LevelManager::newLevel(){  
    this->currentLevel->next = new level;
    this->currentLevel->next->prev = this->currentLevel;
    this->currentLevel = this->currentLevel->next;
    this->currentLevel->next = NULL;
    this->currentMap = this->currentLevel->map;
    this->currentLevel->levelNumber = this->currentLevel->prev->levelNumber + 1;
    this->currentLevel->startingPoints = this->currentLevel->prev->startingPoints + LEVELUPRANGE;
    return this->currentLevel;
}

level* LevelManager::previousLevel(){
    if(this->currentLevel->prev != NULL){
        this->currentLevel = this->currentLevel->prev;
        this->currentMap = this->currentLevel->map;
        return this->currentLevel;
    }else{
        return NULL; //fare controllo ricezione null
    }
}

level* LevelManager::nextLevel(){
     if(this->currentLevel->next != NULL){
        this->currentLevel = this->currentLevel->next;
        this->currentMap = this->currentLevel->map;
        return this->currentLevel;
    }else{
        return this->newLevel();
    }
}

level* LevelManager::getCurrentLevel(){
     if(this->currentLevel != NULL)
        return this->currentLevel;
}

Map LevelManager::getCurrentMap(){
    return this->currentMap;
}

int LevelManager::generateDensity(){
    int cellsNumber = (MAPWIDTH -2) * MAPHEIGHT;
    int max = cellsNumber / 100 * MAXDENSITY; 
    int thresholdController = this->currentLevel->levelNumber;
    if(thresholdController > THRESHOLDLEVELFORMAXDENSITY) thresholdController = THRESHOLDLEVELFORMAXDENSITY;
    return (int)(( thresholdController * max ) / THRESHOLDLEVELFORMAXDENSITY);
}

int LevelManager::generateTime(){
    // 500000 -> 50000
    int time = STARTINGREFRESHTIME - (this->currentLevel->levelNumber * 10000);
    if(time < TIMETHRESHOLD) time = TIMETHRESHOLD;
    return time;
}

void LevelManager::initializeCollectiblesLists(){
    this->bonusListElement = this->currentMap.getBonusList();
    this->malusListElement = this->currentMap.getMalusList();
    this->carsListElement = this->currentMap.getCarsList();
}

void LevelManager::updateCollectiblesLists(int threshold){
    while(this->bonusListElement!=NULL && this->bonusListElement->ramp.getYFromStart() < threshold){
        this->bonusListElement = this->bonusListElement->next;
    }
    while(this->malusListElement!=NULL && this->malusListElement->obstacle.getYFromStart() < threshold){
        this->malusListElement = this->malusListElement->next;
    }
    while(this->carsListElement!=NULL && this->carsListElement->vehicle.getYFromStart() < threshold){
        this->carsListElement = this->carsListElement->next;
    }
}

bonus*LevelManager::getBonusList(){
    return this->bonusListElement;
}

malus*LevelManager::getMalusList(){
    return this->malusListElement;
}

car*LevelManager::getCarList(){
    return this->carsListElement;
}
#include "LevelManager.hpp"
//il primo livello lo genera il costruttore 
LevelManager::LevelManager(int startingLevel, int startingPoints){
    this->currentLevel->prev = NULL;
    this->currentLevel->next = NULL;
    this->currentMap = this->currentLevel->map;
    this->currentLevel->levelNumber = startingLevel;
    this->currentMap.calculateLevelDifficult(this->currentLevel->levelNumber);
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
    this->currentMap.calculateLevelDifficult(this->currentLevel->levelNumber);
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
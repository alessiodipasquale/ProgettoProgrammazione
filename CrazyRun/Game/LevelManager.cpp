#include "LevelManager.hpp"

LevelManager::LevelManager(int curr){
    this->currentLevel->prev = NULL;
    this->currentLevel->next = NULL;
    this->currentMap = this->currentLevel->map;
}

void LevelManager::newLevel(){
    this->currentLevel->next = new level;
    this->currentLevel->next->prev = this->currentLevel;
    this->currentLevel->next = NULL;
    this->currentMap = this->currentLevel->map;
}

void LevelManager::previousLevel(){
    if(this->currentLevel->prev != NULL){
        this->currentLevel = this->currentLevel->prev;
        this->currentMap = this->currentLevel->map;
    }
}

void LevelManager::nextLevel(){
     if(this->currentLevel->next != NULL){
        this->currentLevel = this->currentLevel->next;
        this->currentMap = this->currentLevel->map;
    }
}
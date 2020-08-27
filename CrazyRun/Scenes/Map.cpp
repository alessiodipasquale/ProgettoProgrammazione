#include "Map.hpp"

void Map::newMalus(int level, int x, int y){
    if(this->malusHead == NULL){
        this->malusHead = new malus;
        this->malusHead->next = NULL;
        this->malusHead->obstacle.init(level, x, y);
    }else{
        malus*mHead = this->malusHead;
        while(mHead->next!=NULL && mHead->next->obstacle.getYFromStart() <= y){
            mHead = mHead->next;
        }
        if(mHead->next==NULL){
            mHead ->next= new malus;
            mHead->next->next = NULL;
            mHead->next->obstacle.init(level, x, y);
        }else{
            malus*temp = mHead->next;
            mHead->next = new malus;
            mHead->next->next = temp;
            mHead->next->obstacle.init(level, x,y);
        }
    }
}

void Map::newBonus(int level, int x, int y){

    if(this->bonusHead == NULL){
        this->bonusHead = new bonus;
        this->bonusHead->next = NULL;
        this->bonusHead->ramp.init(level, x, y);
    }else{
        bonus*bHead = this->bonusHead;
        while(bHead->next!=NULL && bHead->next->ramp.getYFromStart() <= y){
            bHead = bHead->next;
        }
        if(bHead->next==NULL){
            bHead ->next = new bonus;
            bHead->next->next = NULL;
            bHead->next->ramp.init(level, x,y);
        }else{
            bonus*temp = bHead->next;
            bHead->next = new bonus;
            bHead->next->next = temp;
            bHead->next->ramp.init(level, x,y);
        }    
    }
}

void Map::newCar(int level, int x, int lastConsideredZone){
    if(this->carHead == NULL){
        this->carHead = new car;
        this->carHead->next = NULL;
        this->carHead->vehicle.init(level, x, lastConsideredZone);
    }else{
        car*cHead = this->carHead;
        while(cHead->next!=NULL){
            cHead = cHead->next;
        }
        cHead->next = new car;
        cHead->next->next = NULL;
        cHead->next->vehicle.init(level, x, lastConsideredZone);
    } 
}

void Map::generateNewZone(int numberOfBonus, int numberOfMalus, bool car, int level){

    for (int i=0; i<MAPHEIGHT; i++) {
        for (int j=0; j<MAPWIDTH; j++){
            if(j == 0 || j == MAPWIDTH-1) this->generationMatrix[i][j] = false;
            else  this->generationMatrix[i][j] = true;
        }
    }

    int x, y, xCar = -1;
    if(car) {
        xCar = (rand() % MAPWIDTH - 3) + 1;  //per evitare che la macchina finisca sui bordi
        newCar(level,  xCar, this->lastConsideredZone);

        for (int i=0; i<MAPHEIGHT; i++) this->generationMatrix[i][xCar] = false;
    }
    for (int i=0; i<numberOfMalus; i++){
        bool ok = false;
        while(!ok){
            x = (rand() % MAPWIDTH - 3) + 1;
            y = (rand() % MAPHEIGHT - 3) + 1;
            if(this->generationMatrix[y][x]){
                ok = true;
                this->generationMatrix[y][x] = false;
            }  
        }
        newMalus(level, x, (this->lastConsideredZone - MAPHEIGHT) + y);
    }

    for (int i=0; i<numberOfBonus; i++){
        bool ok = false;
        while(!ok){
            x = (rand() % MAPWIDTH - 3) + 1;
            y = (rand() % MAPHEIGHT - 3) + 1;
            if(this->generationMatrix[y][x] ){
                ok = true;
                this->generationMatrix[y][x] = false;
            }  
        }
        newBonus(level, x, (this->lastConsideredZone - MAPHEIGHT) + y);
    }
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
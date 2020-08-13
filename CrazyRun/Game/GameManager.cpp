#include "GameManager.hpp"

void GameManager::cleanScreen() {
    system("clear");
}

void GameManager::mainMenu() {
    bool valid = false;
    while(!valid){
        cleanScreen();
        cout<<"********************************************************************"<<endl;
        cout<<"*                       Progetto programmazione                    *"<<endl;
        cout<<"*                                                                  *"<<endl;
        cout<<"*                                                                  *"<<endl;
        cout<<"*                                 ^                                *"<<endl;
        cout<<"*                               < P >                              *"<<endl;
        cout<<"*                                 v                                *"<<endl;
        cout<<"*                                                                  *"<<endl;
        cout<<"*                                                                  *"<<endl;
        cout<<"*                         1. Avvia il gioco                        *"<<endl;
        cout<<"*                                                                  *"<<endl;
        cout<<"*                      2. Informazioni e crediti                   *"<<endl;
        cout<<"*                                                                  *"<<endl;
        cout<<"*                              3. Esci                             *"<<endl;
        cout<<"*                                                                  *"<<endl;
        cout<<"********************************************************************"<<endl;
        cout<<endl;
        cout<<"Seleziona: ";
        int risposta;
        cin>>risposta;
        switch (risposta)
        {
        case 1:
            valid = true;
            prepare();
            break;
        case 2:
            valid = true;
            information();
            break;
        case 3:
            valid = true;
            void kill();
        default:
            break;
        }
    }
}

void GameManager::information() {
    bool valid = false;
    while(!valid){
        cleanScreen();
        cout<<"********************************************************************"<<endl;
        cout<<"*                     Progetto di programmazione                   *"<<endl;
        cout<<"*                                                                  *"<<endl;
        cout<<"*                               Autori                             *"<<endl;
        cout<<"*                         Di Pasquale Alessio                      *"<<endl;
        cout<<"*                         Colamonaco Stefano                       *"<<endl;
        cout<<"*                                                                  *"<<endl;
        cout<<"*               (So che non e' centrato, giuro che fixo)           *"<<endl;
        cout<<"*                                                                  *"<<endl;
        cout<<"*                           1. Torna al menu                       *"<<endl;
        cout<<"*                               2. Esci                            *"<<endl;
        cout<<"********************************************************************"<<endl;
        cout<<endl;
        cout<<"Seleziona: ";
        int risposta;
        cin>>risposta;
        switch (risposta)
        {
        case 1:
            valid = true;
            mainMenu();
            break;
        case 2:
            valid = true;
            kill();
            break;
        default:
            break;
        }
    }
} 

void GameManager:: prepare(){
    cleanScreen();

    resetLv();
    resetScore();

    LevelManager run(this->lv, this->points);
    level *currentLevel = run.getCurrentLevel();

    start(run, currentLevel); 
    kill();
}

void GameManager::gameOver(){
    cout<<"Game Over"<<endl;
}

void GameManager::prevLevel(){

}

void GameManager::nextLevel(){

}

void GameManager::resetScore(){
    this->points = 0;
}

void GameManager::resetLv(){
    this->lv = 1;
}

int GameManager::kill(){
    return 0;
}

void GameManager::increasePointsBy(int value){
    this->points = this->points + value;
};

int GameManager::collision(){
    if(0) {

    }else return -1;
}

void GameManager::collisionControl(){
    int data = collision();
    if (data > -1){
        if (data == 0){

        } else {
            if (data == 1){

            } else {
                gameOver();
            }
        }
    }
}

char GameManager::getPlayerMovement(){

}

void GameManager::print(){

}

void GameManager::start(LevelManager run, level *currentLevel){
    while(true){ 
        //START NEW LEVEL "animations"
        bool levelChanged = false;
        while(!levelChanged){ //condizione di next level
            increasePointsBy(1);
            collisionControl();
            if(this->points >= currentLevel->startingPoints + LEVELUPRANGE){
                currentLevel = run.nextLevel();
                levelChanged = true;
            }
            if(this->points <= currentLevel->startingPoints - LEVELDOWNRANGE){
                if(this->lv == 1) gameOver();
                else {
                    currentLevel = run.previousLevel();
                    levelChanged = true;
                }    
            }
            char movement = getPlayerMovement();
            print();
            
        }
    }
}
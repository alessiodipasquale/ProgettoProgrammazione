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

int GameManager::collisionControl(){
    
}

char GameManager::getPlayerCommand(){
    initscr();
    noecho();
    nodelay(stdscr, true);
    char c1 = getch();
    if (c1 == '\033') { // if the first value is esc
        getch(); // skip the [ 
        char c = getch();      
        switch(c) { // the real value
            case 'A':
                // code for arrow up
                cout<<"su"<<endl;
                return 'u';
            case 'B':
                // code for arrow down
                cout<<"giu'"<<endl;
                return 'd';
            case 'C':
                // code for arrow right
                cout<<"dx"<<endl;
                return 'r';
            case 'D':
                // code for arrow left
                cout<<"sx"<<endl;
                return 'l';
            default:
                cout<<"Error"<<endl;   
        }
    } else {
        if(c1 == 'q'){
            endwin();
            cout<<"sure? (y for yes,  n for no)"<<endl;
            do{
                cin>>c1;
                if(c1 == 'y') {
                    return 0;
                }else {
                    if(c1 == 'n'){
                        cleanScreen();
                        stdscr = newwin(0,0,0,0);
                        return -1;
                    }else cout<<"wrong key pressed"<<endl;  
                }
            }while(c1 != 'y' && c1 != 'n' );  
        }
    }    
}

void GameManager::mapConstruction(char mat[][MAPWIDTH], char command, int collisionType){

}

void GameManager::print(char mat[][MAPWIDTH]){

}

void GameManager::start(LevelManager run, level *currentLevel){
    char command = -1;
    bool inGame = true;
    int collisionType;
    char mat[MAPHEIGHT][MAPWIDTH];

    while(inGame){ 
        //START NEW LEVEL "animations"
        bool levelChanged = false;

        while(!levelChanged){ //condizione di next level

            increasePointsBy(1);
            collisionType = collisionControl();
            //collision stuff

            if(this->points >= currentLevel->startingPoints + LEVELUPRANGE){
                currentLevel = run.nextLevel();
                levelChanged = true;
            }
            if(this->points <= currentLevel->startingPoints - LEVELDOWNRANGE){
                if(this->lv == 1) inGame = false;
                else {
                    currentLevel = run.previousLevel();
                    levelChanged = true;
                }    
            }

            if(!levelChanged && inGame ){
                mapConstruction(mat, command, collisionType);
                print(mat);  
                command = getPlayerCommand();
                if(command == 0) inGame = false;
            }
        }
    }
    gameOver();
}
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
    initscr();
    noecho();
    nodelay(stdscr, true);
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
    char c1 = getch();
    if (c1 == '\033') { // if the first value is esc
        getch(); // skip the [ 
        char c = getch();      
        switch(c) { // the real value
            case 'A':
                return 'u';
            case 'B':
                return 'd';
            case 'C':
                return 'r';
            case 'D':
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
                        initscr();
                        noecho();
                        nodelay(stdscr, true);
                        return -1;
                    }else cout<<"wrong key pressed"<<endl;  
                }
            }while(c1 != 'y' && c1 != 'n' );  
        }
    }    
}

void GameManager::initializeMap(char mat[][MAPWIDTH]){
    for(int i=0; i<MAPHEIGHT; i++){
        for(int j=0; j<MAPWIDTH; j++){
            mat[i][j] = ' ';
        }
    }
}

void GameManager::mapConstruction(int density, level*currentLevel, LevelManager run, int viewPosition){
    int numberOfBonus = 0;
    int numberOfMalus = 0;
    bool car = false;
    if(currentLevel->map.getLastConsideredZone() - viewPosition <= MAPHEIGHT){
        currentLevel->map.updateLastConsideredZone(); //+31
        if(currentLevel->levelNumber > 1){
            numberOfBonus = density/currentLevel->levelNumber;
            if(currentLevel->levelNumber >= 10){
                int random = rand() % 3; 
                if(random == 0){ // 33% di possibilità di spawn
                    car = true;
                    numberOfMalus = density - numberOfBonus - 1;
                }
            }else numberOfMalus = density - numberOfBonus;
        }else numberOfBonus = density;

        currentLevel->map.generateNewZone(numberOfBonus, numberOfMalus, car, currentLevel->levelNumber);    
    }
}

void GameManager::print(char mat[][MAPWIDTH], int viewPosition, LevelManager run){
    //ad ogni chiamata della funzione, le matrici vengono shiftate verso il basso e questi
    //tre controlli si occupano dei nuovi collectible
    clear();
    for(int i = 0; i < MAPHEIGHT; i++){
       for(int j = 0; j < MAPWIDTH; j++){
           if(j==0 || j == MAPWIDTH-1){
               printw("#");
           }else{
               addch(mat[i][j]);
           }
        }
        printw("\n");
    }
    printw("%d",this->points);
    
    for(int i = MAPHEIGHT-1; i >= 0; i--){
       for(int j = MAPWIDTH-2; j > 0; j--){
           if(i==0) mat[i][j] = ' ';
           else mat[i][j] = mat[i-1][j];            
        }
    }

    bonus*bonusList = run.getBonusList();
    malus*malusList = run.getMalusList();
    car*carsList = run.getCarList();

    while(bonusList!=NULL && bonusList->ramp.getYFromStart() < viewPosition + (MAPHEIGHT-1) ){
        mat[0][bonusList->ramp.getXFromStart()] = bonusList->ramp.getAppearance();
        bonusList = bonusList->next;
    }
    while(malusList!=NULL && malusList->obstacle.getYFromStart() < viewPosition + (MAPHEIGHT-1)){
        mat[0][malusList->obstacle.getXFromStart()] = malusList->obstacle.getAppearance();
        malusList = malusList->next;
    }
    while(carsList!=NULL && carsList->vehicle.getYFromStart() < viewPosition + (MAPHEIGHT-1)){
        mat[0][carsList->vehicle.getXFromStart()] = carsList->vehicle.getAppearance();
        carsList = carsList->next;
    }

    run.updateCollectiblesLists( (viewPosition + (MAPHEIGHT-1)) );

}////// ATTENZIONE: IMPLEMENTARE MATRICE GEMELLA CON PUNTATORE A COLLECTIBLE PER OTTIMIZZARE

void GameManager::start(LevelManager run, level *currentLevel){
    char command = -1;
    bool inGame = true;
    int collisionType;
    char mat[MAPHEIGHT][MAPWIDTH];
    int viewPosition;

    while(inGame){ 
        //START NEW LEVEL "animations"
        bool levelChanged = false;
        Map currentMap = run.getCurrentMap();
        initializeMap(mat);
        viewPosition = 0;
        int density = run.generateDensity();
        run.initializeCollectiblesLists();
        bool newLevel = true;

        while(!levelChanged && inGame){ // next level condition
            increasePointsBy(1);
            viewPosition++;
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
                mapConstruction(density, currentLevel, run, viewPosition);
                if(newLevel==true && run.getBonusList()==NULL){ //trovare modo piu elegante
                    run.initializeCollectiblesLists();
                }
                newLevel = false;
                print(mat, viewPosition, run);  
                command = getPlayerCommand();
                if(command == 0) inGame = false;
            }
            int time = run.generateTime();
            usleep(time); 
        }
    }
    gameOver();
}
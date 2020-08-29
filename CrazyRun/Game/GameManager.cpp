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
        cout<<"*                              __________                          *"<<endl;
        cout<<"*                               CrazyRun                           *"<<endl;
        cout<<"*                              ----------                          *"<<endl;
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

            playerSelection();
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
        cout<<"*                         Colamonaco Stefano                       *"<<endl;
        cout<<"*                         Di Pasquale Alessio                      *"<<endl;
        cout<<"*                                                                  *"<<endl;
        cout<<"*                                                                  *"<<endl;
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
void GameManager::playerSelection(){
    int response;
    player*pl = new player;
    do{
        cleanScreen();
        cout<<"select a skin"<<endl;
        cin>>response;
    }while(response != 1 && response != 2 && response != 3);

    if(response == 1){
        pl->numberOfComponents = NUMBEROFCOMPONENTS_1;
        for(int i = 0; i<NUMBEROFCOMPONENTS_1;i++){
            pl->xCoordinates[i] = XCOORDINATES_1[i];
            pl->yCoordinates[i] = YCOORDINATES_1[i];
            pl->components[i] = COMPONENTS_1[i];
        }
    }else{
        if(response==2){
        pl->numberOfComponents = NUMBEROFCOMPONENTS_2;
        for(int i = 0; i<NUMBEROFCOMPONENTS_2;i++){
            pl->xCoordinates[i] = XCOORDINATES_2[i];
            pl->yCoordinates[i] = YCOORDINATES_2[i];
            pl->components[i] = COMPONENTS_2[i];
        }
        }else{
            pl->numberOfComponents = NUMBEROFCOMPONENTS_3;
            for(int i = 0; i<NUMBEROFCOMPONENTS_3;i++){
                pl->xCoordinates[i] = XCOORDINATES_3[i];
                pl->yCoordinates[i] = YCOORDINATES_3[i];
                pl->components[i] = COMPONENTS_3[i];
            }
        }
    }
    prepare(pl);
}

void GameManager:: prepare(player* pl){
    cleanScreen();

    resetLv();
    resetScore();

    LevelManager run(this->lv, this->points);
    level *currentLevel = run.getCurrentLevel();
    initscr();
    noecho();
    nodelay(stdscr, true);
    start(run, currentLevel,pl); 
    kill();
}

void GameManager::gameOver(){
    cout<<"Game Over"<<endl;
}

int GameManager::levelControl(int startingPoints){ // 0: gameOver, 1 nextLevel, 2 previousLevel
    if(this->points >= startingPoints + LEVELUPRANGE) return 1;
    if(this->points <= startingPoints - LEVELDOWNRANGE){
        if(this->lv == 1) return 0;
        else return 2;
    }
    return -1;
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

void GameManager::modifyPlayerPosition(char command, player*pl){
    bool ok = true;
    if(command == 'u'){
        for(int i=0; i<pl->numberOfComponents && ok;i++){
            if(pl->yCoordinates[i]-1 < 0){
                ok = false; 
            }
        }
        if(ok){
            for(int i=0; i<pl->numberOfComponents;i++){
                pl->yCoordinates[i] = pl->yCoordinates[i]-1 ;
            }
        }
    }else{
        if(command == 'd'){
            for(int i=0; i<pl->numberOfComponents && ok;i++){
                if(pl->yCoordinates[i]+1 >= MAPHEIGHT){
                    ok = false; 
                }
            }
            if(ok){
                for(int i=0; i<pl->numberOfComponents;i++){
                    pl->yCoordinates[i] = pl->yCoordinates[i]+1;
                }
            }
        }else{
            if(command == 'l'){
                for(int i=0; i<pl->numberOfComponents && ok;i++){
                    if(pl->xCoordinates[i]-2 <0 ){
                        ok = false; 
                    }
                }
                if(ok){
                    for(int i=0; i<pl->numberOfComponents;i++){
                        pl->xCoordinates[i] = pl->xCoordinates[i]-2;
                    }
                }
            }else{
                if(command == 'r'){
                    for(int i=0; i<pl->numberOfComponents && ok;i++){
                        if(pl->xCoordinates[i]+2 >= MAPWIDTH){
                        ok = false; 
                        }
                    }
                    if(ok){
                        for(int i=0; i<pl->numberOfComponents;i++){
                            pl->xCoordinates[i] = pl->xCoordinates[i]+2;
                        }
                    }
                }else{
                    printw("Error: wrong command");
                }
            }
            
        }
    }
    

}

void GameManager::initializeMap(char mat[][MAPWIDTH],player*pl){
    for(int i=0; i<MAPHEIGHT; i++){
        for(int j=0; j<MAPWIDTH; j++){
            mat[i][j] = ' ';
        }
    }
    for(int i=0;i<pl->numberOfComponents;i++){
        int x = pl->xCoordinates[i];
        int y = pl->yCoordinates[i];
        mat[y][x] = pl->components[i];
    }

}

void GameManager::mapConstruction(int density, level*currentLevel, LevelManager run, int viewPosition){
    int numberOfBonus = 0;
    int numberOfMalus = 0;
    bool car = false;
    if(currentLevel->map.getLastConsideredZone() - viewPosition <= MAPHEIGHT){
        currentLevel->map.updateLastConsideredZone(); //+31
        if(currentLevel->levelNumber > 1){
            numberOfBonus = (int)(density / currentLevel->levelNumber)+(int)(density/5);
            if(currentLevel->levelNumber >= 10){
                int random = rand() % 3; 
                if(random == 0){ // 33% di possibilità di spawn
                    car = true;
                    numberOfMalus = density - numberOfBonus - 1;
                    //printw("bon:%d  mal:%d ",numberOfBonus, numberOfMalus) ;
                }
            }else numberOfMalus = density - numberOfBonus;
        }else numberOfBonus = density + 1;
        currentLevel->map.generateNewZone(numberOfBonus, numberOfMalus, car, currentLevel->levelNumber);    
    }
}

void GameManager::print(char mat[][MAPWIDTH], int viewPosition, LevelManager run, player*pl){
    //ad ogni chiamata della funzione, le matrici vengono shiftate verso il basso e questi
    //tre controlli si occupano dei nuovi collectible
    for(int i = MAPHEIGHT-1; i >= 0; i--){
       for(int j = MAPWIDTH-2; j > 0; j--){
           if(i==0) mat[i][j] = ' ';
           else mat[i][j] = mat[i-1][j];            
        }
    }
    for(int i=0;i<pl->numberOfComponents;i++){
        int x = pl->xCoordinates[i];
        int y = pl->yCoordinates[i];
        mat[y][x] = pl->components[i];
    }
    
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

    for(int i=0;i<pl->numberOfComponents;i++){
                    int x = pl->xCoordinates[i];
                    int y = pl->yCoordinates[i];
                    mat[y][x] = ' ';
                }

    bonus*bonusList = run.getBonusList();
    malus*malusList = run.getMalusList();
    car*carsList = run.getCarList();

    while(malusList!=NULL ){
        if(malusList->obstacle.getYFromStart() == viewPosition + (MAPHEIGHT-1)){
            mat[0][malusList->obstacle.getXFromStart()] = malusList->obstacle.getAppearance();
        }
        malusList = malusList->next;
    }
    while(bonusList!=NULL ){
        if(bonusList->ramp.getYFromStart() == viewPosition + (MAPHEIGHT-1)){
            mat[0][bonusList->ramp.getXFromStart()] = bonusList->ramp.getAppearance();
        }
        bonusList = bonusList->next;
    }
    while(carsList!=NULL){
        if(carsList->vehicle.getYFromStart() == viewPosition + (MAPHEIGHT-1)){
            mat[0][carsList->vehicle.getXFromStart()] = carsList->vehicle.getAppearance();
        }
        carsList = carsList->next;
    }

    run.updateCollectiblesLists( (viewPosition + (MAPHEIGHT-1)) );

}////// ATTENZIONE: IMPLEMENTARE MATRICE GEMELLA CON PUNTATORE A COLLECTIBLE PER OTTIMIZZARE

void GameManager::start(LevelManager run, level *currentLevel, player*pl){
    char command = -1;
    bool inGame = true;
    int collisionType;
    char mat[MAPHEIGHT][MAPWIDTH];
    int viewPosition;
    player*backupPlayer = pl;

    while(inGame){ 
        //START NEW LEVEL "animations"
        bool levelChanged = false;
        initializeMap(mat,backupPlayer);
        viewPosition = 0;
        int density = run.generateDensity();
        bool newLevel = true;

        while(!levelChanged && inGame){ // next level condition
            increasePointsBy(1);
            viewPosition++;
            collisionType = collisionControl();
            //collision stuff
            
            int levelContoller = levelControl(currentLevel->startingPoints);
            if(levelContoller==0) inGame = false;
            if(levelContoller==1) {levelChanged = true; currentLevel = run.nextLevel();} 
            if(levelContoller==2) {levelChanged = true; currentLevel = run.previousLevel();} 
            
            if(!levelChanged && inGame ){
                mapConstruction(density, currentLevel, run, viewPosition);
                if(newLevel==true ) run.initializeCollectiblesLists();
                newLevel = false;
                print(mat, viewPosition, run, pl);  
                command = getPlayerCommand();
                if(command == 0) inGame = false;
                else if(command!= -1) modifyPlayerPosition(command, pl);
                //if(command!='u' && command!='d')modifyPlayerPosition('d',pl);
            }
            int time = run.generateTime();
            usleep(time); 
        }
    }
    gameOver();
}

#include "GameManager.hpp"

void GameManager::cleanScreen() {
    system("clear");
}

void GameManager::mainMenu() {
    bool valid = false;
    while(!valid){
        cleanScreen();
        cout<<"********************************************************************"<<endl;
        cout<<"*                                                                  *"<<endl;
        cout<<"*                                                                  *"<<endl;
        cout<<"*                                                                  *"<<endl;
        cout<<"*             _____                    ______                      *"<<endl;
        cout<<"*            /  __ \\                   | ___ \\                     *"<<endl;
        cout<<"*            | /  \\/_ __ __ _ _____   _| |_/ /   _ _ __            *"<<endl;
        cout<<"*            | |   | '__/ _` |_  / | | |    / | | | '_ \\           *"<<endl;
        cout<<"*            | \\__/\\ | | (_| |/ /| |_| | |\\ \\ |_| | | | |          *"<<endl;
        cout<<"*             \\____/_|  \\__,_/___|\\__, \\_| \\_\\__,_|_| |_|          *"<<endl;
        cout<<"*                                  __/ |                           *"<<endl;
        cout<<"*                                 |___/                            *"<<endl;
        cout<<"*                                                                  *"<<endl;
        cout<<"*                                                                  *"<<endl;
        cout<<"*                             1. Start                             *"<<endl;
        cout<<"*                                                                  *"<<endl;
        cout<<"*                            2. Credits                            *"<<endl;
        cout<<"*                                                                  *"<<endl;
        cout<<"*                             3. Exit                              *"<<endl;
        cout<<"*                                                                  *"<<endl;
        cout<<"********************************************************************"<<endl;
        cout<<endl;
        cout<<"Select: ";
        int res;
        cin>>res;
        switch (res)
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
            kill();
            break;
        default: 
            cout<<" Error: wrong key pressed"<<endl;
            break;
        }
    }
}

void GameManager::information() {
    bool valid = false;
    while(!valid){
        cleanScreen();
        cout<<"********************************************************************"<<endl;
        cout<<"*                              CrazyRun                            *"<<endl;
        cout<<"*                                                                  *"<<endl;
        cout<<"*                              Credits:                            *"<<endl;
        cout<<"*                         Colamonaco Stefano                       *"<<endl;
        cout<<"*                         Di Pasquale Alessio                      *"<<endl;
        cout<<"*                                                                  *"<<endl;
        cout<<"*                                                                  *"<<endl;
        cout<<"*                                                                  *"<<endl;
        cout<<"*                           1. Back to menu'                       *"<<endl;
        cout<<"*                             2. Exit                              *"<<endl;
        cout<<"*                                                                  *"<<endl;
        cout<<"********************************************************************"<<endl;
        cout<<endl;
        cout<<"Select: ";
        int res;
        cin>>res;
        switch (res)
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
            cout<<" Error: wrong key pressed"<<endl;
            break;
        }
    }
} 
void GameManager::playerSelection(){
    int response;
    player*pl = new player;
    do{
        cleanScreen();
        cout<<endl;
        cout<<"|*******************************************************************|"<<endl;
        cout<<"|*|                   |*|                   |*|                   |*|"<<endl;
        cout<<"|*|                   |*|                   |*|                   |*|"<<endl;
        cout<<"|*|                   |*|                   |*|                   |*|"<<endl;
        cout<<"|*|                   |*|                   |*|                   |*|"<<endl;
        cout<<"|*|                   |*|                   |*|                   |*|"<<endl;
        cout<<"|*|         ^         |*|        O-O        |*|        /-\\        |*|"<<endl;
        cout<<"|*|        O-O        |*|        O-O        |*|        O-O        |*|"<<endl;
        cout<<"|*|                   |*|                   |*|                   |*|"<<endl;
        cout<<"|*|                   |*|                   |*|                   |*|"<<endl;
        cout<<"|*|                   |*|                   |*|                   |*|"<<endl;
        cout<<"|*|                   |*|                   |*|                   |*|"<<endl;
        cout<<"|*|         1         |*|         2         |*|         3         |*|"<<endl;
        cout<<" *******************************************************************"<<endl;
        cout<<endl;
        cout<<" Select a skin: ";
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

void GameManager::initializePlayer(player*pl, player*backupPlayer){
    pl->numberOfComponents = backupPlayer->numberOfComponents;
    for(int i=0;i<backupPlayer->numberOfComponents;i++){
        pl->components[i] = backupPlayer->components[i];
        pl->xCoordinates[i] = backupPlayer->xCoordinates[i];
        pl->yCoordinates[i] = backupPlayer->yCoordinates[i];
    }
}

void GameManager::newLevelAnimations(bool upOrDown){
    if(this->lv == 1) printw("\n\n\n\n\n\n\n\n\n\n                              Level: 1 ");
    else {
        if(upOrDown){
            for(int i=0;i<10;i++){
                clear();
                printw("\n\n\n\n\n\n\n\n\n\n                              Level:");
                for(int k=i;k<10;k++) printw("\n");
                printw("                                      %d", this->lv); 
                refresh();
                usleep(100000);
            }
            clear();
            printw("\n\n\n\n\n\n\n\n\n\n                              Level:  %d",this->lv);
        }else{
            for(int i=0;i<10;i++){
                clear();
                for(int k=i; k>0;k--) printw("\n");
                printw("                                      %d", this->lv);
                for(int j=i;j<10;j++) printw("\n");
                printw("                              Level:");
                refresh();
                usleep(100000);
            }
            clear();
            printw("\n\n\n\n\n\n\n\n\n\n                              Level:  %d",this->lv);
        }
    }
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
    curs_set(0);
    start(run, currentLevel,pl); 
    kill();
}

void GameManager::gameOver(){
    while(getch()!=-1);
    endwin();
    cout<<"\n\n\n\n"<<endl;
    cout<<"     ██████╗  █████╗ ███╗   ███╗███████╗     ██████╗ ██╗   ██╗███████╗██████╗    "<<endl;
    cout<<"    ██╔════╝ ██╔══██╗████╗ ████║██╔════╝    ██╔═══██╗██║   ██║██╔════╝██╔══██╗   "<<endl;
    cout<<"    ██║  ███╗███████║██╔████╔██║█████╗      ██║   ██║██║   ██║█████╗  ██████╔╝   "<<endl;
    cout<<"    ██║   ██║██╔══██║██║╚██╔╝██║██╔══╝      ██║   ██║╚██╗ ██╔╝██╔══╝  ██╔══██╗   "<<endl;
    cout<<"    ╚██████╔╝██║  ██║██║ ╚═╝ ██║███████╗    ╚██████╔╝ ╚████╔╝ ███████╗██║  ██║   "<<endl;
    cout<<"     ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝     ╚═════╝   ╚═══╝  ╚══════╝╚═╝  ╚═╝   "<<endl;                                                                                                                      
    cout<<"\n"<<endl;
    cout<<"                           Best score of the run: "<<this->bestScore<<endl;
    cout<<"\n\n\n"<<endl;
}

int GameManager::levelControl(int startingPoints){ // 0: gameOver, 1 nextLevel, 2 previousLevel
    if(this->lv == 1 && this->points < 0 ) return 0;
    if(this->points >= startingPoints + LEVELUPRANGE) return 1;
    if(this->points <= startingPoints - LEVELDOWNRANGE) return 2;
    return -1;
}

void GameManager::resetScore(){
    this->points = 0;
    this->bestScore = 0;
}

void GameManager::resetLv(){
    this->lv = 1;
}

int GameManager::kill(){
    return 0;
}

void GameManager::modifyPointsBy(int value){
    this->points = this->points + value;
};

int GameManager::collisionControl(player*pl, Collectible*collectiblesMap[][MAPWIDTH]){
    bool wall = false;
    for(int i=0;i<pl->numberOfComponents;i++){
        if( (pl->xCoordinates[i] == 0 || pl->xCoordinates[i] == MAPWIDTH-1) && !wall ){
            modifyPointsBy(WALLPENALITY);
            wall = true;
        }
        if(collectiblesMap[pl->yCoordinates[i]][pl->xCoordinates[i]]) {
            modifyPointsBy(collectiblesMap[pl->yCoordinates[i]][pl->xCoordinates[i]]->getPower());
            collectiblesMap[pl->yCoordinates[i]][pl->xCoordinates[i]] = NULL;
        }    
    }
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
                break;   
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
                        curs_set(0);
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

void GameManager::initializeMap(char mat[][MAPWIDTH],player*pl, Collectible* collectibleMap[][MAPWIDTH]){
    for(int i=0; i<MAPHEIGHT; i++){
        for(int j=0; j<MAPWIDTH; j++){
            mat[i][j] = ' ';
            collectibleMap[i][j] = NULL;
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
                    numberOfMalus = density - (numberOfBonus + 1);
                    //printw("bon:%d  mal:%d ",numberOfBonus, numberOfMalus) ;
                }else numberOfMalus = density - numberOfBonus;
            }else numberOfMalus = density - numberOfBonus;
        }else numberOfBonus = density + 1;
        currentLevel->map.generateNewZone(numberOfBonus, numberOfMalus, car, currentLevel->levelNumber);    
    }
}

void GameManager::print(char mat[][MAPWIDTH], int viewPosition, LevelManager run, player*pl, Collectible*collectiblesMap[][MAPWIDTH]){
    //ad ogni chiamata della funzione, le matrici vengono shiftate verso il basso e questi
    //tre controlli si occupano dei nuovi collectible
    for(int i = MAPHEIGHT-1; i >= 0; i--){
       for(int j = MAPWIDTH-2; j > 0; j--){
           if(i==0) {
               mat[i][j] = ' ';
               collectiblesMap[i][j] = NULL; 
           }else {
                if( collectiblesMap[i-1][j] && collectiblesMap[i-1][j]->getMovement() && i+1 < MAPHEIGHT){
                    mat[i+1][j] = mat[i-1][j];
                    collectiblesMap[i+1][j] = collectiblesMap[i-1][j];  
                }else{
                    mat[i][j] = mat[i-1][j];
                    collectiblesMap[i][j] = collectiblesMap[i-1][j];
                }
           }          
        }
    }
    for(int i=0;i<pl->numberOfComponents;i++){
        int x = pl->xCoordinates[i];
        int y = pl->yCoordinates[i];
        mat[y][x] = pl->components[i];
    }
    clear();
    printw("-----------------------------------------------------------------------\n|");
    for(int i = 0; i < MAPHEIGHT; i++){
       for(int j = 0; j < MAPWIDTH; j++){
           if(j==0 || j == MAPWIDTH-1){
               printw("#");
           }else{
               addch(mat[i][j]);
           }
        }
        printw("|");
        if(i==3){ 
            for(int k=0;k<MAPTHRESHOLD-MAPWIDTH;k++) printw(" ");
            printw("score: %d", this->points);
            int tmp = this->points;
            int count = 0; 
            while(tmp>=10){
                tmp = tmp/10;
                count++;
            }
            for(int k=0;k<SCREENWIDTH-(MAPTHRESHOLD+11)-count;k++) printw(" ");
            printw("|");

        }else{
            if(i==5) {
                for(int k=0;k<MAPTHRESHOLD-MAPWIDTH;k++)printw(" ");
                printw("level: %d", this->lv);
                int tmp = this->lv;
                int count = 0; 
                while(tmp>=10){
                    tmp = tmp/10;
                    count++;
                }
                for(int k=0;k<SCREENWIDTH-(MAPTHRESHOLD+11)-count;k++) printw(" ");
                printw("|");
        
            }else{
                if(i==19){
                    for(int k=0;k<MAPTHRESHOLD-MAPWIDTH;k++) printw(" ");
                    printw("Press arrow keys to move");
                    for(int k=0;k<SCREENWIDTH-(MAPTHRESHOLD+27);k++) printw(" ");
                    printw("|");
                }else{
                    if(i==21){
                        for(int k=0;k<MAPTHRESHOLD-MAPWIDTH;k++) printw(" ");
                        printw("Press 'q' to quit");
                        for(int k=0;k<SCREENWIDTH-(MAPTHRESHOLD+20);k++) printw(" ");
                        printw("|");
                    }else{
                        printw("                                     |");
                    }
                }    
            }
        }
        printw("\n|");
    }
    printw("-------------------------------|-------------------------------------|");
    refresh();

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
            collectiblesMap[0][malusList->obstacle.getXFromStart()] = &(malusList->obstacle);
        }
        malusList = malusList->next;
    }
    while(bonusList!=NULL ){
        if(bonusList->ramp.getYFromStart() == viewPosition + (MAPHEIGHT-1)){
            mat[0][bonusList->ramp.getXFromStart()] = bonusList->ramp.getAppearance();
            collectiblesMap[0][bonusList->ramp.getXFromStart()] = &(bonusList->ramp);

        }
        bonusList = bonusList->next;
    }
    while(carsList!=NULL){
        if(carsList->vehicle.getYFromStart() == viewPosition + (MAPHEIGHT-1)){
            mat[0][carsList->vehicle.getXFromStart()] = carsList->vehicle.getAppearance();
            collectiblesMap[0][carsList->vehicle.getXFromStart()] = &(carsList->vehicle);
        }
        carsList = carsList->next;
    }

    run.updateCollectiblesLists( (viewPosition + (MAPHEIGHT-1)) );
}

void GameManager::start(LevelManager run, level *currentLevel, player*backupPlayer){
    char command = -1;
    bool inGame = true;
    int collisionType;
    char mat[MAPHEIGHT][MAPWIDTH];
    Collectible *collectiblesMap[MAPHEIGHT][MAPWIDTH];
    int viewPosition;
    player*pl = new player;
    bool upOrDown;

    while(inGame){      
        this->lv = currentLevel->levelNumber;
        this->points = currentLevel->startingPoints;
        clear();
        newLevelAnimations(upOrDown);
        refresh();
        usleep(2500000);  
        initializePlayer(pl, backupPlayer);
        bool levelChanged = false;
        initializeMap(mat,backupPlayer, collectiblesMap);
        initializePlayer(pl, backupPlayer);
        viewPosition = 0;
        int density = run.generateDensity();
        bool newLevel = true;

        while(!levelChanged && inGame){
            modifyPointsBy(BONUSPOINTS);
            if(this->points > this->bestScore) this->bestScore = this->points;
            viewPosition++;
            collisionType = collisionControl(pl, collectiblesMap);
            
            int levelContoller = levelControl(currentLevel->startingPoints);
            if(levelContoller==0) inGame = false;
            if(levelContoller==1) {levelChanged = true; upOrDown=true; currentLevel = run.nextLevel();} 
            if(levelContoller==2) {
                levelChanged = true;  upOrDown=false; currentLevel = run.previousLevel(); 
                if(currentLevel==NULL) {inGame=false; kill();} //controllo necessario solo se si vuole modificare il livello corrente a mano
            } 
            
            if(!levelChanged && inGame ){
                mapConstruction(density, currentLevel, run, viewPosition);
                if(newLevel==true ) run.initializeCollectiblesLists();
                newLevel = false;
                print(mat, viewPosition, run, pl, collectiblesMap);
                int time = run.generateTime();
                usleep(time); 
                command = getPlayerCommand();
                if(command == 0) inGame = false;
                else if(command!= -1) modifyPlayerPosition(command, pl);
            }
        }
        while(getch()!=-1);
    }
    gameOver();
}

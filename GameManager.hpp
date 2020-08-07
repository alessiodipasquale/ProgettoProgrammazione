#include "includes.hpp"


class GameManager {
    public:
        int currentLevel = 0;
        int points = 0;
        int playerPosition;
        int mapHeight;
        int mapWidth;

        void cleanScreen() {
            system("clear");
        }       

        void mainMenu() {
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

        void information() {
            bool valid = false;
            while(!valid){
                cleanScreen();
                cout<<"********************************************************************"<<endl;
                cout<<"*                        Progetto programmazione                   *"<<endl;
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

        void prepare(){
            cleanScreen();
            cout<<"Preparo il gioco...";
        }

        void start(){

        } 

        int kill() {
            return 0;
        }

        void nextLevel(){
            currentLevel = currentLevel + 1;
        }
};
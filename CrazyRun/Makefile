crazy-run: main.o GameManager.o LevelManager.o Map.o Collectible.o Collectibles.o
	g++ -o CrazyRun main.o GameManager.o LevelManager.o Map.o Collectible.o Collectibles.o -lncurses

main.o: main.cpp
	g++ -c main.cpp 

GameManager.o: Game/GameManager.cpp
	g++ -c Game/GameManager.cpp

LevelManager.o: Game/LevelManager.cpp
	g++ -c Game/LevelManager.cpp

Map.o: Scenes/Map.cpp
	g++ -c Scenes/Map.cpp

Collectible.o: Scenes/Collectible.cpp
	g++ -c Scenes/Collectible.cpp

Collectibles.o: Scenes/Collectibles.cpp
	g++ -c Scenes/Collectibles.cpp

run:
	make crazy-run && ./CrazyRun

clean:
	rm -rf *.o
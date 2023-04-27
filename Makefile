all:
	g++ -o prog main.cpp Game.cpp Entity.cpp Player.cpp Enemy.cpp EntityList.cpp -lsfml-graphics -lsfml-window -lsfml-system
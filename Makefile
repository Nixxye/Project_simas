all:
	g++ -o prog entities/Enemy.cpp entities/Entity.cpp entities/Obstacle.cpp entities/Player.cpp lists/EntityList.cpp main/Game.cpp main/main.cpp -IC:/SFML-2.5.1/include -LC:/SFML-2.5.1/lib -lsfml-graphics -lsfml-window -lsfml-system
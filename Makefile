all:
	g++ -o prog main.cpp Game.cpp Entity.cpp Player.cpp Personagem.cpp -lsfml-graphics -lsfml-window -lsfml-system
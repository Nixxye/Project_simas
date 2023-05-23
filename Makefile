all:
	g++ stages/*.cpp entities/*.cpp lists/*.cpp main/*.cpp managers/*.cpp observers/*.cpp -o prog -IC:/SFML-2.5.1/include -LC:/SFML-2.5.1/lib -lsfml-graphics -lsfml-window -lsfml-system
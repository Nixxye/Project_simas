all:
	g++ entities/*.cpp lists/*.cpp main/*.cpp managers/*.cpp -o prog -IC:/SFML-2.5.1/include -LC:/SFML-2.5.1/lib -lsfml-graphics -lsfml-window -lsfml-system
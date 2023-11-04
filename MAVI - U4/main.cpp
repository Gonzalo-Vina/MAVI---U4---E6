#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "GameController.h"

#define FONT_PATH "C:\\Windows\\Fonts\\arial.ttf"

using namespace sf;

int main()
{
	GameController gameController;

	

	std::vector<Sprite> enemys;

	

	gameController.MainLoop();

	

	return 0;
}


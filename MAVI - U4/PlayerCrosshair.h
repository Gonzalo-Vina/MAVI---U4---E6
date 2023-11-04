#pragma once

#include <stdio.h>
#include <tchar.h>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

using namespace sf;

class PlayerCrosshair {
	Texture textureCrosshair;
	Sprite spriteCrosshair;

public:
	PlayerCrosshair() {
		textureCrosshair.loadFromFile("assets/crosshair.png");
		spriteCrosshair.setTexture(textureCrosshair);
		spriteCrosshair.setOrigin(64, 64);
	}

	void Dibujar(RenderWindow *wnd) {
		wnd->draw(spriteCrosshair);
	}

	void Posicionar(Vector2i mousePosition) {
		spriteCrosshair.setPosition(mousePosition.x, mousePosition.y);
	}

	Vector2f GetPosition() {
		return spriteCrosshair.getPosition();
	}
};
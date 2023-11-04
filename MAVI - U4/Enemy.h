#pragma once

#include <stdio.h>
#include <tchar.h>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

using namespace sf;

class Enemy {
	Texture textureEnemy;
	Sprite spriteEnemy;

	bool _estaVivo;
	bool _estaVisible;

	sf::Clock _clock;
	float _tiempoVisible;
	float _tiempoApagado;

	Vector2f RandomPos(Vector2u maxPos) {
		Vector2f random((float)(rand() % maxPos.x), (rand() % maxPos.y));
		return random;
	}

public:
	Enemy() {
		textureEnemy.loadFromFile("assets/et.png");
		spriteEnemy.setTexture(textureEnemy);
		spriteEnemy.setScale(0.1, 0.1);
		_estaVivo = true;
		_estaVisible = true;
		_tiempoVisible = 0.5f;
		_tiempoApagado = 0.5f;
	}

	bool EstaVivo() {
		return _estaVivo;
	}

	bool EstaActivo() {
		return _estaVivo && _estaVisible;
	}

	bool CheckCollision(float x, float y) {
		FloatRect bounds = spriteEnemy.getGlobalBounds();
		return bounds.contains(x, y);
	}

	void Dibujar(RenderWindow* wnd) {
		wnd->draw(spriteEnemy);
	}

	void Death() {
		_estaVivo = false;
	}

	void Actualizar(RenderWindow *wnd) {
		if (!_estaVivo)
			return;

		if (!_estaVisible) {
			if (_clock.getElapsedTime().asSeconds() > _tiempoApagado) {
				_clock.restart();
				if (rand() % 100 < 25) {
					_estaVisible = true;
					spriteEnemy.setPosition(RandomPos(wnd->getSize()));
				}					
			}
		}
		else {
			if (_clock.getElapsedTime().asSeconds() > _tiempoVisible) {
				_estaVisible = false;
				_clock.restart();
			}
		}
	}
};
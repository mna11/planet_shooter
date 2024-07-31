#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

class NPC{
private:
	float x, y;
	float speed;
	float size;
	Texture &t;
	Texture test;
	CircleShape npc;
	float offset_x;
	int texture_number;
public:
	NPC(float _x, float _y, float _speed, float _size, Texture &_t, int _texture_number);
	void update();
	void draw(RenderWindow& _window);
	void setPos(Vector2f pos);
	bool destroyed;
	FloatRect getArea();
	bool checkTexture(int _texture_number);
};
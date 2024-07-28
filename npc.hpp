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

NPC::NPC (float _x, float _y, float _speed, float _size, Texture &_t, int _texture_number) 
	: x(_x), y(_y), speed(_speed), size(_size), t(_t), offset_x(_speed), texture_number(_texture_number), destroyed(false)
{
	t.setRepeated(true);
	npc = CircleShape(size);
	npc.setTexture(&t);
	npc.setPosition(x, y);
}

void NPC::update(){
  if (destroyed == true)
    return;
  
	Vector2f pos = npc.getPosition();
	if (pos.x > 540.f)
	{
		offset_x = -speed;
	}
	else if (pos.x < 70.0f)
	{
		offset_x = speed;
	}
	npc.move(offset_x, 0.f);
}

void NPC::draw(RenderWindow& _window){
  if (destroyed == true)
    return;
	_window.draw(npc);
}

void NPC::setPos(Vector2f pos){
	npc.setPosition(pos);
	offset_x = speed;
}

FloatRect NPC::getArea()
{
    return npc.getGlobalBounds();
}

bool NPC::checkTexture(int _texture_number){
  return (texture_number == _texture_number);
}
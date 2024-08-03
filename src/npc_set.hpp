#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "npc.hpp"
#include "timer.hpp"
#include "point.hpp"

using namespace std;
using namespace sf;

class NPC_SET{
protected:
	Timer& timer;
	Point& point;
	vector<NPC> npcs;
	vector<bool> remain_texture;
	int num;
	bool AllDestroyed();
public:
	NPC_SET(int _num, int size, Texture (&_textures)[3], Timer &_timer, Point &_point);
	void update();
	void draw(RenderWindow&  _window);
	bool checkHit(FloatRect _rect, int texture_number);
	void destroyed();
	vector<bool> remainTexture();
	void AgainPlay();
};
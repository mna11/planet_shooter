#pragma once

#include <SFML/Graphics.hpp>
#include <iostream> 
#define GAME_START 1
#define MANUAL_SELECT 2

using namespace sf;
using namespace std;

class StartScene{
private:
	Text game_title;
	Text game_start;
	Text game_manual;
	RectangleShape select_point;
	int select; // 1 - game_start_select , 2 - manual_select
public:
	StartScene(Font& _font, RenderWindow& window);
	void setText(Text& text, Font& _font, int size, Color in_color, Color out_color, int out_thick, RenderWindow& _window);
	void setPointBlock(RectangleShape &rect, int size, Color in_color, Color out_color, int out_thick, RenderWindow& _window);
	int KeyInput(Event &_event);
	void draw(RenderWindow& _window);
};
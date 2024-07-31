#pragma once

#include <SFML/Graphics.hpp>

#include "timer.hpp"
#include "point.hpp"

#define PLAY_AGAIN 0
#define END_Scene 3
#define QUIT_GAME 4

using namespace sf;
using namespace std;

class EndScene{
private:
	Text result;
	Text result_point_info;
	Text result_time_info;
	Text game_play_again;
	Text quit_the_game;
	RectangleShape select_point;

    Timer& timer;
    Point& point;
    Font& font;

	int select;
	int p;
	int score_t;
	int real_t;
public:
	EndScene(Font& _font, Timer& _timer, Point& _point, RenderWindow& window);
	void setText(Text& text, Font& _font, int size, Color in_color, Color out_color, int out_thick, RenderWindow& _window);
	void setPointBlock(RectangleShape &rect, int size, Color in_color, Color out_color, int out_thick);
	int keyInput(Event& _event);
    void setting(RenderWindow& _window);
	void draw(RenderWindow& _window);
};
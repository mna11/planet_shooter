#pragma once

#include <SFML/Graphics.hpp>

#include "timer.hpp"
#include "point.hpp"

#define PLAY_AGAIN 1
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

EndScene::EndScene(Font& _font, Timer& _timer, Point& _point, RenderWindow& _window)
: timer(_timer), point(_point), font(_font), p(-1), score_t(-1), real_t(-1), select(PLAY_AGAIN) {
	game_play_again.setString("PLAY AGAIN?");
	quit_the_game.setString("QUIT GAME?");
	setText(game_play_again, font, 50, Color::White, Color(102,102,204), 5, _window);
	setText(quit_the_game, font, 50, Color::White, Color(204,102,102), 5, _window);
	game_play_again.move(- game_play_again.getLocalBounds().width + game_play_again.getLocalBounds().width/3.f, 150);
	quit_the_game.move(quit_the_game.getLocalBounds().width - quit_the_game.getLocalBounds().width/3.f, 150);
	
	setPointBlock(select_point, 20, Color::White, Color(102, 102, 204), 5);
}

void EndScene::setText(Text& text, Font& _font, int size, Color in_color, Color out_color, int out_thick, RenderWindow& _window)
{
	text.setFont(_font); 
	text.setCharacterSize(size);
	text.setFillColor(in_color); 
	text.setOutlineColor(out_color);  
	text.setOutlineThickness(out_thick);
	
	text.setOrigin(text.getLocalBounds().left, text.getLocalBounds().top);
	text.setPosition(_window.getSize().x/2.f - text.getLocalBounds().width/2.f , 
	                                _window.getSize().y/2.f - text.getLocalBounds().height/2.f);
}

void EndScene::setPointBlock(RectangleShape &rect, int size, Color in_color, Color out_color, int out_thick)
{
	rect.setSize(Vector2f(size,size));
	rect.setFillColor(in_color);
	rect.setOutlineColor(out_color);
	rect.setOutlineThickness(out_thick);
	rect.setOrigin(rect.getLocalBounds().left, rect.getLocalBounds().top);
	rect.setPosition(game_play_again.getPosition().x + game_play_again.getLocalBounds().width/2.f - rect.getLocalBounds().width/2.f,
					game_play_again.getPosition().y + game_play_again.getLocalBounds().height + rect.getLocalBounds().height * 2.f/3.f);
	
}


int EndScene::keyInput(Event &_event)
{
	if (_event.key.code == Keyboard::Enter)
	{
		if (select == PLAY_AGAIN) return PLAY_AGAIN;
		if (select == QUIT_GAME) return QUIT_GAME;
	}
	else if (_event.key.code == Keyboard::Left)
	{
		if (select == QUIT_GAME) {
			select = PLAY_AGAIN;
			select_point.move(game_play_again.getGlobalBounds().left + game_play_again.getGlobalBounds().width /2.f
							- (quit_the_game.getGlobalBounds().left + quit_the_game.getGlobalBounds().width /2.f), 0);
			select_point.setOutlineColor(game_play_again.getOutlineColor());
		}
	}
	else if (_event.key.code == Keyboard::Right)
	{
		if (select == PLAY_AGAIN) {
			select = QUIT_GAME;
			select_point.move(-(game_play_again.getGlobalBounds().left + game_play_again.getGlobalBounds().width /2.f)
							+ quit_the_game.getGlobalBounds().left + quit_the_game.getGlobalBounds().width /2.f, 0);
			select_point.setOutlineColor(quit_the_game.getOutlineColor());
		}
	}
	return END_Scene;
}




void EndScene::setting(RenderWindow& _window){
    p = point.getPoint();
    score_t = timer.getTime();
	real_t = timer.getRealTime();

    if (p == 100) result.setString("You WIN!!!");
    else result.setString("You Lose...");
	result_point_info.setString("you destroyed planet: " + to_string(p));
	result_time_info.setString("Take score time: " + to_string(score_t) + "\nTake real time: " + to_string(real_t));

	setText(result, font, 100, Color::White, Color(102,204,102), 5, _window);
	setText(result_point_info, font, 50, Color::White, Color(102,204,102), 5, _window);
	setText(result_time_info, font, 50, Color::White, Color(102,204,102), 5, _window);

	result.move(0, -100);
	result_time_info.move(0, 75);
}



void EndScene::draw(RenderWindow& _window)
{
	_window.draw(result);
	_window.draw(result_point_info);
	_window.draw(result_time_info);
	_window.draw(game_play_again);
	_window.draw(quit_the_game);
	_window.draw(select_point);
}
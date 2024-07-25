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

StartScene::StartScene(Font& _font, RenderWindow& _window)
{
	select = GAME_START;
	game_title.setString("Planet Shooter");
	game_start.setString("Press to Start Game");
	game_manual.setString("Press to Reading Manual");
	setText(game_title, _font, 50, Color::White, Color(102,204,102), 5, _window);
	setText(game_start, _font, 25, Color::White, Color(102,204,102), 5, _window);
	setText(game_manual, _font, 25, Color::White, Color(102,204,102), 5, _window);
	game_title.move(0, -50);
	game_start.move(0, 25);
	game_manual.move(0, 50);
	
	setPointBlock(select_point, 5, Color::White, Color(102, 204, 102), 2, _window);
}

void StartScene::setText(Text& text, Font& _font, int size, Color in_color, Color out_color, int out_thick, RenderWindow& _window)
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

void  StartScene::setPointBlock(RectangleShape &rect, int size, Color in_color, Color out_color, int out_thick, RenderWindow& _window)
{
	rect.setSize(Vector2f(size,size));
	rect.setFillColor(in_color);
	rect.setOutlineColor(out_color);
	rect.setOutlineThickness(out_thick);
	rect.setOrigin(rect.getLocalBounds().left, rect.getLocalBounds().top);
	rect.setPosition(game_start.getPosition().x - 30,
									game_start.getPosition().y + game_start.getLocalBounds().height/2.f - rect.getLocalBounds().height/2.f);
	
}

int StartScene::KeyInput(Event &_event)
{
	if (_event.key.code == Keyboard::Enter)
	{
		if (select == GAME_START) return 1;
		if (select == MANUAL_SELECT) return 2;
	}
	else if (_event.key.code == Keyboard::Down)
	{
		if (select == GAME_START) {
			select = MANUAL_SELECT;
			select_point.move(0, 25);
		}
	}
	else if (_event.key.code == Keyboard::Up)
	{
		if (select == MANUAL_SELECT) {
			select = GAME_START;
			select_point.move(0, -25);
		}
	}
	
	return 0;
}

void StartScene::draw(RenderWindow& _window)
{
	_window.draw(game_title);
	_window.draw(game_start);
	_window.draw(game_manual);
	_window.draw(select_point);
}
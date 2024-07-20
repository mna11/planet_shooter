#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

using namespace sf;
using namespace std;

class Timer{
private:
  Clock clock;
  Time timer;
  Text text;
  RectangleShape back;
  Vector2f position;
  int inc_time;
public:
  Timer(Font& _font);
  void setText(Font& _font, int size, Color in_color, Color out_color, int out_thick,Vector2f pos);
  void setBackground(Color color, Vector2f pos);
  void clockRestart();
  void timeToString(int inc);
  void draw(RenderWindow& _window, bool _game_start);
};

Timer::Timer(Font& _font)
: inc_time(0)
{
	Vector2f pos = Vector2<float>(585, -20);
	
	setText(_font, 75, Color::White, Color::Black, 5, pos);
	setBackground(Color::Black, pos);
}

void Timer::setText(Font& _font, int size, Color in_color, Color out_color, int out_thick, Vector2f pos)
{
	text.setFont(_font);
	text.setCharacterSize(size);
	text.setFillColor(in_color);
	text.setOutlineColor(out_color);
	text.setOutlineThickness(out_thick);
	text.setPosition(pos);
}

void Timer::setBackground(Color color, Vector2f pos)
{
	pos.x -= 10;
	pos.y += 25;
	
	back.setSize(Vector2f(60, 60));
	back.setFillColor(color);
	back.setOutlineThickness(5);
	back.setOutlineColor(Color::White);
	back.setPosition(pos);
}

void Timer::clockRestart()
{
  timer = clock.restart();  
}

void Timer::timeToString(int inc = 0)
{
	int seconds;
	inc_time += inc;
	timer = clock.getElapsedTime();
	seconds = timer.asSeconds();
	seconds += inc_time;
	
	if (seconds < 0) 
	{
		clockRestart();
		inc_time = 0;
	}
	
	if (seconds < 10)
		text.setString("0" + to_string(seconds));
	else
		text.setString(to_string(seconds));
}

void Timer::draw(RenderWindow& _window, bool _game_playing)
{  
  _window.draw(back);
  
  if (_game_playing == false) 
  {
  	text.setString("00");
  	_window.draw(text);
  	return;
  }
  
  timeToString();
   _window.draw(text);
}


#pragma once

#include <SFML/Graphics.hpp>

#define TIMER_TEXT_X 585 
#define TIMER_TEXT_Y -20
#define TIMER_BOX_X 575
#define TIMER_BOX_Y 5

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
  int real_time;
  int last_time;
public:
  Timer(Font& _font);
  void setText(Font& _font, int size, Color in_color, Color out_color, int out_thick,Vector2f pos);
  void setBackground(Color color, Vector2f pos);
  void clockRestart();
  void timeToString(int inc);
  int getTime();
  int getRealTime();
  void draw(RenderWindow& _window, bool _game_start);
};

Timer::Timer(Font& _font)
: inc_time(0), real_time(0), last_time(0)
{
	Vector2f pos = Vector2<float>(TIMER_TEXT_X, TIMER_TEXT_Y);
	
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
	pos.x = TIMER_BOX_X;
	pos.y = TIMER_BOX_Y;
	
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

	if (last_time != (int)timer.asSeconds()){
		real_time++;
		last_time = timer.asSeconds();
	}

	if (seconds < 0) 
	{
		clockRestart();
		inc_time = 0;
	}
	
	text.setString(to_string(seconds));
	if (seconds < 10) text.setPosition(TIMER_TEXT_X + 10, TIMER_TEXT_Y);
	else text.setPosition(TIMER_TEXT_X, TIMER_TEXT_Y);
}

int Timer::getTime(){
	int seconds;
	timer = clock.getElapsedTime();
	seconds = timer.asSeconds();
	seconds += inc_time;
	return seconds;
}

int Timer::getRealTime()
{
	return real_time;
}

void Timer::draw(RenderWindow& _window, bool _game_playing)
{  
  _window.draw(back);
  
  if (_game_playing == false) 
  {
  	_window.draw(text);
  	return;
  }
  
  timeToString();
   _window.draw(text);
}


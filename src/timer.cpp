#include "timer.hpp"

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
  inc_time = 0;
  real_time = 0;
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
		timer = clock.restart();  
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


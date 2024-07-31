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
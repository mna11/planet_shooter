#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

#define POINT_BOX_X 5
#define POINT_BOX_Y 5
#define POINT_TEXT_X 15
#define POINT_TEXT_Y -20

using namespace sf;
using namespace std;

class Point{
private:
    int point;
    Text point_text;
    Font font;
    RectangleShape point_text_box;
public:
    Point(Font& _font);
    void setText(Font& _font, int size, Color in_color, Color out_color, int out_think, Vector2f pos);
    void setBackground(Color color, Vector2f pos);
    void pointToString(int inc);
    int getPoint();
    void resetPoint();
    void draw(RenderWindow& _window, bool _game_playing);
};

Point::Point(Font& _font) : font(_font), point(0){
    Vector2f pos(POINT_TEXT_X, POINT_TEXT_Y);
	setText(_font, 75, Color::White, Color::Black, 5, pos);
	setBackground(Color::Black, pos);
}

void Point::setText(Font& _font, int size, Color in_color, Color out_color, int out_think, Vector2f pos){
    point_text.setFont(_font);
    point_text.setCharacterSize(size);
    point_text.setFillColor(in_color);
    point_text.setOutlineColor(out_color);
    point_text.setOutlineThickness(out_think);
    point_text.setPosition(pos);
}

void Point::setBackground(Color color, Vector2f pos)
{
	pos.x = POINT_BOX_X;
	pos.y = POINT_BOX_Y;  
	
	point_text_box.setSize(Vector2f(60, 60));
	point_text_box.setFillColor(color);
	point_text_box.setOutlineThickness(5);
	point_text_box.setOutlineColor(Color::White);
	point_text_box.setPosition(pos);
}

void Point::pointToString(int inc = 0){
    point += inc;
    if (point < 10) point_text.setPosition(POINT_TEXT_X + 10, POINT_TEXT_Y);
    else if (point < 100) point_text.setPosition(POINT_TEXT_X, POINT_TEXT_Y);
    else point_text.setPosition(POINT_TEXT_X - 10, POINT_TEXT_Y);

    point_text.setString(to_string(point));
}

int Point::getPoint(){
    return point;
}

void Point::resetPoint(){
    point = 0;
}
void Point::draw(RenderWindow& _window, bool _game_playing)
{  
  _window.draw(point_text_box);
  if (_game_playing == false) 
  {
  	point_text.setString("0");
  	_window.draw(point_text);
  	return;
  }
  
  pointToString();
  _window.draw(point_text);
}
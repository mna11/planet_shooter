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
#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

class Background{
private:
  Texture space_bar, space_center;
  Sprite left_back, right_back, center_back;
public:
  Background();
  void draw(RenderWindow& _window);
};

Background::Background(){
  space_bar.loadFromFile("asset/Space/space_bar.jpg", IntRect(0, 0, 60, 480));
  space_center.loadFromFile("asset/Space/space_center.jpg", IntRect(0, 0, 520, 480));

  left_back.setTexture(space_bar);
  right_back.setTexture(space_bar);
  center_back.setTexture(space_center);
  left_back.setPosition(0, 0);
  right_back.setPosition(580, 0);
  center_back.setPosition(60, 0);
}

void Background::draw(RenderWindow& _window)
{
    _window.draw(left_back);
    _window.draw(right_back);
    _window.draw(center_back);
}
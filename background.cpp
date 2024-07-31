#include "background.hpp"

Background::Background(){
  // Texture load -> Sprite set Texture -> Sprite set Position -> draw
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
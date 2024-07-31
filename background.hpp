#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

class Background{ // game play scene 배경 
private:
  Texture space_bar, space_center;
  Sprite left_back, right_back, center_back;
public:
  Background();
  void draw(RenderWindow& _window);
};
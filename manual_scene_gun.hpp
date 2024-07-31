#pragma once

#include <SFML/Graphics.hpp>
#include "gun.hpp"
#include "manual_scene_npc_set.hpp"

using namespace sf;
using namespace std;

class MANUAL_SCENE_GUN : public GUN{
public:
  MANUAL_SCENE_GUN(Texture (&texture)[3]): GUN(texture){}
  void moveLeft();
  void moveRight();
  void update(MANUAL_SCENE_NPC_SET& _npcs);
  void draw(RenderWindow& _window);
};
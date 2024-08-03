#pragma once

#include <SFML/Graphics.hpp>

#include "npc_set.hpp"

using namespace sf;

class MANUAL_SCENE_NPC_SET : public NPC_SET {
private:
    Vector2f base_pos;
public:
    MANUAL_SCENE_NPC_SET(int n, int size, Texture (&_textures)[3], Timer& timer, Point& point);
    void setManualNpc(Vector2f pos);
    void AgainPlay();
    void update();
};
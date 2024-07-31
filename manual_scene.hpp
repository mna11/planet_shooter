#pragma once

#include <SFML/Graphics.hpp>

#include "gun.hpp"
#include "manual_scene_gun.hpp"
#include "manual_scene_npc_set.hpp"

#define START_Scene 0
#define MANUAL_Scene 2

using namespace sf;

class ManualScene{
private:
    MANUAL_SCENE_GUN& player;
    MANUAL_SCENE_NPC_SET& npcCon;

    Texture textures[3];
    Text manual_title;
    Text game_goal;
    Text game_control;
    Text game_clear;
    Text return_start_scene;

public:
    ManualScene(MANUAL_SCENE_GUN& _player, MANUAL_SCENE_NPC_SET& _npcCon, Font& _font, Texture (&_textures)[3], RenderWindow& _window);
    void setText(Text& text, Font& font, int size, Color in_color, Color out_color, int out_think, RenderWindow& window);
    int keyInput(Event &_event);
    void update();
    void draw(RenderWindow& _window);
};
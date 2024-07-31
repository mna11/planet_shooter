#include "manual_scene.hpp"

ManualScene::ManualScene(MANUAL_SCENE_GUN& _player, MANUAL_SCENE_NPC_SET& _npcCon, Font& _font, Texture (&_textures)[3], RenderWindow& _window)
: player(_player), npcCon(_npcCon){
    copy_n(_textures, 3, textures);
    manual_title.setString("MANUAL");
    game_goal.setString("GOAL: Destroy planets by hitting the same\n planet you are firing at!");
    game_control.setString("CONTROL: you can move, LEFT, RIGHT ARROW. \n And fire, SPACE BAR.");
    game_clear.setString("CLEAR: Destroy 50 planet\n before the timer runs out of 60s\n (destroy same: -10s, contact different: +5s)");
    return_start_scene.setString("[ Press ESC to return Start Scene ]");

    setText(manual_title, _font, 100, Color::White, Color(102, 204, 102), 5, _window);
    setText(game_goal, _font, 40, Color::White, Color(102, 204, 102), 5, _window);
    setText(game_control, _font, 40, Color::White, Color(102, 204, 102), 5, _window);
    setText(game_clear, _font, 40, Color::White, Color(102, 204, 102), 5, _window);
    setText(return_start_scene, _font, 40, Color::White, Color(102, 204, 102), 5, _window);

    game_goal.move(0, 70);
    game_control.move(0, 170);
    game_clear.move(0, 270);
    return_start_scene.move(-10 + _window.getSize().x / 2 - return_start_scene.getLocalBounds().width / 2, 400);
    
    Vector2f npc_pos;
    npc_pos.x = manual_title.getGlobalBounds().left + manual_title.getGlobalBounds().width + 30;
    npc_pos.y = manual_title.getGlobalBounds().top;
    npcCon.setManualNpc(npc_pos);
}

void ManualScene::setText(Text& text, Font& font, int size, Color in_color, Color out_color, int out_think, RenderWindow& window){
    text.setFont(font);
    text.setCharacterSize(size);
    text.setFillColor(in_color);
    text.setOutlineColor(out_color);
    text.setOutlineThickness(out_think);

    text.setOrigin(text.getLocalBounds().left, text.getLocalBounds().top);
    text.setPosition(10, 10);
}

int ManualScene::keyInput(Event& _event){
    if (_event.key.code == Keyboard::Left) 
		player.moveLeft();
	else if (_event.key.code == Keyboard::Right)
		player.moveRight();
	else if (_event.key.code == Keyboard::Space){
		player.fireBullet();
    }
    else if (_event.key.code == Keyboard::Escape)
        return START_Scene;
    return MANUAL_Scene;
}

void ManualScene::update(){
    player.update(npcCon);
    npcCon.update();
}

void ManualScene::draw(RenderWindow& _window)
{
    _window.draw(manual_title);
    _window.draw(game_goal);
    _window.draw(game_control);
    _window.draw(game_clear);
    _window.draw(return_start_scene);
    npcCon.draw(_window);
    player.draw(_window);
}



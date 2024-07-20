#pragma once

#include <SFML/Graphics.hpp>

//header file
#include "npc.hpp"
#include "npc_set.hpp"
#include "gun.hpp"
#include "background.hpp"
#include "Timer.hpp"

using namespace sf;

class GameScene{
private:
	Timer& timer;
	GUN& player;
	NPC_SET& npcCon;
	Background& bg;
	
	bool game_start;
public:
	GameScene(Timer& _timer, GUN& _player, NPC_SET& npcCon, Background& _bg);
	void keyInput(Event& _event);
	void update(bool _game_start);
	void draw(RenderWindow& _window);
};

GameScene::GameScene(Timer& _timer, GUN& _player, NPC_SET& _npcCon, Background& _bg)
: timer(_timer), player(_player), npcCon(_npcCon), bg(_bg)
{ }

void GameScene::keyInput(Event& _event)
{
	if (_event.key.code == Keyboard::A)
		player.moveLeft();
	else if (_event.key.code == Keyboard::D)
		player.moveRight();
	else if (_event.key.code == Keyboard::Space)
		player.fireBullet();
}

void GameScene::update(bool _game_start)
{
	game_start = _game_start;
	npcCon.update();
	player.update(npcCon);
}

void GameScene::draw(RenderWindow& _window)
{
	bg.draw(_window);
	timer.draw(_window, game_start);
	npcCon.draw(_window);
	player.draw(_window);
}
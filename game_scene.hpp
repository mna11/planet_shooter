#pragma once

#include <SFML/Graphics.hpp>

//header file
#include "npc.hpp"
#include "npc_set.hpp"
#include "gun.hpp"
#include "background.hpp"
#include "Timer.hpp"

using namespace sf;

class GameScene{ // gameplay scene
private:
	Timer& timer;
	GUN& player;
	NPC_SET& npcCon;
	Background& bg;
	
	bool game_start;
public:
	GameScene(Timer& _timer, GUN& _player, NPC_SET& npcCon, Background& _bg);
	void keyInput(Event& _event); // key 입력 처리 
	void update(bool _game_start); // 화면 정보 업데이트
	void draw(RenderWindow& _window); // window에 화면 그리기
};

GameScene::GameScene(Timer& _timer, GUN& _player, NPC_SET& _npcCon, Background& _bg)
: timer(_timer), player(_player), npcCon(_npcCon), bg(_bg)
{ }

void GameScene::keyInput(Event& _event) // 좌우 이동 및 발사 기능
{	
	if (_event.key.code == Keyboard::Left) 
		player.moveLeft();
	else if (_event.key.code == Keyboard::Right)
		player.moveRight();
	else if (_event.key.code == Keyboard::Space)
		player.fireBullet();
	else if (_event.key.code == Keyboard::K) // test code
		npcCon.destroyed();
}

void GameScene::update(bool _game_start) // game_start했을 경우에 npcCon, player의 정보값을 업데이트 해줌 
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
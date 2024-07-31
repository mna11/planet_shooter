#pragma once

#include <SFML/Graphics.hpp>

//header file
#include "npc.hpp"
#include "npc_set.hpp"
#include "gun.hpp"
#include "background.hpp"
#include "timer.hpp"
#include "point.hpp"

using namespace sf;

class GameScene{ // gameplay scene
private:
	Timer& timer;
	Point& point;
	GUN& player;
	NPC_SET& npcCon;
	Background& bg;
	
	bool game_start;
public:
	GameScene(Timer& _timer, Point& _point, GUN& _player, NPC_SET& npcCon, Background& _bg);
	void keyInput(Event& _event); // key 입력 처리 
	void update(bool _game_start); // 화면 정보 업데이트
	bool gameEndCheck(); // 게임이 종료되었는지 체크 (100개의 행성을 부셨거나, 60초가 넘었거나)
	void gamePlayAgain(); 
	void draw(RenderWindow& _window); // window에 화면 그리기
};
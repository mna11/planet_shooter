#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "npc.hpp"
#include "Timer.hpp"

using namespace std;
using namespace sf;

class NPC_SET{
private:
	vector<NPC> npcs;
	Timer& timer;
public:
	NPC_SET(int num, Texture (&_textures)[3], Timer &_timer);
	void update();
	void draw(RenderWindow&  _window);
	bool checkHit(FloatRect _rect, int texture_number);
};

NPC_SET::NPC_SET(int num, Texture (&_textures)[3], Timer &_timer)
: timer(_timer)
{
	int inc = 0;
	for (int i = 0; i < num; i++){
		NPC npc(50.f+inc, 50.f+inc, i+1, _textures[i%3], i%3);
		npcs.push_back(npc);
		inc+=20;	
	}
}

void NPC_SET::update(){
	for (auto& _e : npcs){
		_e.update();
	}
}

void NPC_SET::draw(RenderWindow& _window){
	for (auto& _e : npcs){
		_e.draw(_window);
	}
}

bool NPC_SET::checkHit(FloatRect _rect, int _texture_number)
{
  for (auto& _e: npcs)
  {
    if (_rect.intersects(_e.getArea()) && _e.checkTexture(_texture_number)) // 맞았고, Texture도 동일할 경우
    {
      if (_e.destroyed == true) continue; // 이미 부셔저서 그리지는 않지만 그곳에 존재하는 상태이기에
      _e.destroyed = true;
      timer.timeToString(-10); // -10초를 빼줌
      return true;
    }
    else if (_rect.intersects(_e.getArea())){ // 맞았지만, Texture는 동일하지 않은 경우
      if (_e.destroyed == true) continue;
      timer.timeToString(5); // 5초를 더 해줌
  
      return true;
    }
  }
  return false;
}
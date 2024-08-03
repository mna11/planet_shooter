#include "npc_set.hpp"

void NPC_SET::destroyed(){
	for (auto& _e : npcs) _e.destroyed = true;
}

NPC_SET::NPC_SET(int _num, int size, Texture (&_textures)[3], Timer &_timer, Point &_point)
: num(_num), timer(_timer), point(_point)
{
	int inc = 0;
	for (int i = 0; i < num; i++){
		NPC npc(50.f+inc, 50.f+inc, i+2, size, _textures[i%3], i%3);
		npcs.push_back(npc);
		inc+=35;
	}
}

bool NPC_SET::AllDestroyed(){
	bool all_destroyed = true;
	for (auto& _e : npcs){
		all_destroyed = _e.destroyed;
		if (!all_destroyed) break;
	}
	return all_destroyed;
}

void NPC_SET::AgainPlay(){
	if (AllDestroyed()){
		int inc = 0;
		for (auto& _e : npcs) {
			_e.destroyed = false;
			Vector2f pos(50.f + inc, 50.f + inc);
			_e.setPos(pos);
			inc+=35;
		}
	}
}

void NPC_SET::update(){
	AgainPlay();
	for (auto& _e : npcs){
		_e.update();
	}
}

void NPC_SET::draw(RenderWindow& _window){
	for (auto& _e : npcs){
		_e.draw(_window);
	}
}

vector<bool> NPC_SET::remainTexture(){
	remain_texture.clear();
	if (AllDestroyed()) {
		remain_texture.resize(3, true);
		return remain_texture;
	}
	else remain_texture.resize(3, false);

	for (int i = 0; i < 10; i++){
		if (npcs[i].destroyed == false){
			remain_texture[i%3] = true;
		}
	}

	return remain_texture;
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
	  point.pointToString(1); // 1점을 올림
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
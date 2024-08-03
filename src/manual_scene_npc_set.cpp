#include "manual_scene_npc_set.hpp"

MANUAL_SCENE_NPC_SET::MANUAL_SCENE_NPC_SET(int n, int size, Texture (&_textures)[3], Timer& timer, Point& point)
: NPC_SET(n, size,_textures, timer, point) { }

 void MANUAL_SCENE_NPC_SET::setManualNpc(Vector2f _pos){
    int inc = 0;
    base_pos = _pos;
    for (auto& _e : npcs){
        Vector2f pos(base_pos.x + inc, base_pos.y);
        _e.setPos(pos);
        inc += num * 10;
    }
}

void MANUAL_SCENE_NPC_SET::AgainPlay(){
	if (AllDestroyed()){
		int inc = 0;
		for (auto& _e : npcs) {
			_e.destroyed = false;
            Vector2f pos(base_pos.x + inc, base_pos.y);
			_e.setPos(pos);
			inc += num * 10;
		}
	}
}

void MANUAL_SCENE_NPC_SET::update(){
    AgainPlay();
}
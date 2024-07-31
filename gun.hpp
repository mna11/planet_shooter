#pragma once

#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
#include "npc_set.hpp"

using namespace sf;
using namespace std;

class GUN
{
protected:
  CircleShape gun; // Player
  CircleShape bullet; 
  Texture textures[3]; // 행성 3가지 Texture
  int texture_number[10]; // 탄창에 있는 총알의 Texture을 숫자로 저장함 -> npc에서 texture_number로 같은 texture인지를 검증하기에 만듬
  Texture current_texture; 
  
  CircleShape bullet_texture_shape[10]; // 좌측에 그릴 탄창
  int bullet_now; // 탄창에 있는 10개의 총알에서 몇번째 총알을 쓰는지
  bool showBullet; // true -> 총알이 발사되어 날라가는 중 / false -> 총알이 없어진 상황 (총알이 npc와 맞아서 사라지거나, pos.y <= 0이 됨)

public:
  GUN(Texture (&_Textures)[3]);
  void randomBulletTexture(); // 총알 10개를 세팅
  void changeTexture(); // 다음 총알의 Texture로 변경
  void moveLeft(); // 좌측으로 이동
  void moveRight(); // 우측으로 이동
  void fireBullet(); // 총알 발사
  void update(NPC_SET& _npcs); 
  void draw(RenderWindow& _window);
  void ammoDraw(RenderWindow& _window);
};
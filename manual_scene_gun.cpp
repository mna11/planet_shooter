#include "manual_scene_gun.hpp"

void MANUAL_SCENE_GUN::moveLeft()
{
  if (gun.getPosition().x > 0)
    gun.move(-10.f, 0.f);
}

void MANUAL_SCENE_GUN::moveRight()
{
  if (gun.getPosition().x < 540)
    gun.move(10.f, 0.f);
}

void MANUAL_SCENE_GUN::update(MANUAL_SCENE_NPC_SET& _npcs)
{
  if (showBullet == true) // 총알이 발사되는 중
	{
		bullet.move(0.f, -8.f); // 위로 이동
		if (bullet.getPosition().y < 0.f){ // 총알이 아무것도 안맞고 화면을 넘어감
				showBullet = false;
			  changeTexture(_npcs); // 다음 총알로 변경
		}
		else {// 아직 화면을 안넘어감
			showBullet = !_npcs.checkHit(bullet.getGlobalBounds(), texture_number[bullet_now-1]); // 알맞은 npc를 맞으면 showBullet = false;
			if (showBullet == false) changeTexture(_npcs); // 다음 총알로 변경
		}
	}
}

void MANUAL_SCENE_GUN::draw(RenderWindow& _window)
{
  _window.draw(gun);
  if (showBullet == true)
    _window.draw(bullet);
}
#include "gun.hpp"

GUN::GUN(Texture (&_textures)[3])
{
  srand(time(NULL));
  copy_n(_textures, 3, textures);
  randomBulletTexture();
  gun = CircleShape(50.f);
  gun.setTexture(&current_texture);
  gun.setPosition(320.f - 50.f, 480.f - 50.f);
  
  showBullet = false;
  bullet = CircleShape(5.f);
  bullet.setTexture(&current_texture);
}

void GUN::randomBulletTexture() // 총알 10개를 세팅해준다. 
{
  bullet_now = 0;
  for(int i = 0; i < 10; i++){
    bullet_texture_shape[i] = CircleShape(19.f); // Textures의 크기를 정한다 -> 왼쪽에 띄워줄 탄창에 든 행성의 크기. 
    bullet_texture_shape[i].setTexture(&textures[texture_number[i] = rand() % 3]); // Textures를 정한다. -> 3개의 Textures 중 랜덤으로 
    bullet_texture_shape[i].setPosition(10, 40 + 42.f * i); // 옆에 탄창을 띄워준다. 
  }
  current_texture = *(bullet_texture_shape[bullet_now++].getTexture());
}

void GUN::changeTexture()
{
  current_texture = *(bullet_texture_shape[bullet_now++].getTexture());
  gun.setTexture(&current_texture);
  bullet.setTexture(&current_texture);
  if (bullet_now == 10) randomBulletTexture(); // 10개를 다 쓴 경우, 다시 리로드를 위해 randomBulletTexture()을 부른다. 
}

void GUN::moveLeft()
{
  if (gun.getPosition().x > 60)
    gun.move(-10.f, 0.f);
}

void GUN::moveRight()
{
  if (gun.getPosition().x < 480)
    gun.move(10.f, 0.f);
}

void GUN::fireBullet()
{
  if (showBullet == false)
		{
			Vector2f pos = gun.getPosition();
			pos.x += 50.f - 5.f;
			bullet.setPosition(pos);
			showBullet = true;
		}
}

void GUN::update(NPC_SET& _npcs)
{
  if (showBullet == true) // 총알이 발사되는 중
		{
			bullet.move(0.f, -8.f); // 위로 이동
			if (bullet.getPosition().y < 0.f){ // 총알이 아무것도 안맞고 화면을 넘어감
				showBullet = false;
			  changeTexture(); // 다음 총알로 변경
			}
			else // 아직 화면을 안넘어감
			{
			  showBullet = !_npcs.checkHit(bullet.getGlobalBounds(), texture_number[bullet_now-1]); // 알맞은 npc를 맞으면 showBullet = false;
			  if (showBullet == false) changeTexture(); // 다음 총알로 변경
			}
		}
}

void GUN::draw(RenderWindow& _window)
{
  _window.draw(gun);
  ammoDraw(_window);
  if (showBullet == true)
    _window.draw(bullet);
}

void GUN::ammoDraw(RenderWindow& _window)
{
  for (int i = bullet_now; i < 10; i++){
    _window.draw(bullet_texture_shape[i]);
  }
}
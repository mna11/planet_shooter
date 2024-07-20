#pragma once

#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>

using namespace sf;
using namespace std;

class GUN
{
private:
  CircleShape gun;
  CircleShape bullet;
  Texture textures[3];
  int texture_number[10];
  Texture current_texture;
  
  CircleShape bullet_texture_shape[10];
  int bullet_now;
  bool showBullet;
public:
  GUN(Texture (&_Textures)[3]);
  void randomBulletTexture();
  void changeTexture();
  void moveLeft();
  void moveRight();
  void fireBullet();
  void update(NPC_SET& _npcs);
  void draw(RenderWindow& _window);
  void ammoDraw(RenderWindow& _window);
};

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

void GUN::randomBulletTexture()
{
  bullet_now = 0;
  
  for(int i = 0; i < 10; i++){
    bullet_texture_shape[i] = CircleShape(20.f);
    bullet_texture_shape[i].setTexture(&textures[texture_number[i] = rand() % 3]);
    bullet_texture_shape[i].setPosition(10, 0 + 45.f * i);
  }
  current_texture = *(bullet_texture_shape[bullet_now++].getTexture());
}

void GUN::changeTexture()
{
  current_texture = *(bullet_texture_shape[bullet_now++].getTexture());
  gun.setTexture(&current_texture);
  bullet.setTexture(&current_texture);
  if (bullet_now == 10) randomBulletTexture();
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
  if (showBullet == true)
		{
			bullet.move(0.f, -8.f);
			if (bullet.getPosition().y < 0.f){
				showBullet = false;
			  changeTexture();
			}
			else
			{
			  showBullet = !_npcs.checkHit(bullet.getGlobalBounds(), texture_number[bullet_now-1]);
			  if (showBullet == false) changeTexture();
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
#include <SFML/Graphics.hpp>

//header file
#include "npc.hpp"
#include "npc_set.hpp"
#include "gun.hpp"
#include "background.hpp"
#include "Timer.hpp"
#include "game_scene.hpp"
#include "start_scene.hpp"
 
using namespace sf;

int main(void)
{  
	RenderWindow window(VideoMode(640, 480), "Texture Shooting Game");
	window.setFramerateLimit(30);
	
	//Texture loading
	Texture Terran, Lava, Ice;
	Terran.loadFromFile("asset/Planets/Terran.png");
	Lava.loadFromFile("asset/Planets/Lava.png");
	Ice.loadFromFile("asset/Planets/Ice.png");
	Texture textures[3] = {Terran, Lava, Ice};
	
	//Fonts loading
	Font m3x6_font;
	m3x6_font.loadFromFile("./asset/Fonts/Silver.ttf");
	
	bool game_playing  = false;
	
	Timer timer(m3x6_font);
	GUN Player(textures);
	NPC_SET npcCon(15, textures, timer);
	Background bg;
	
	GameScene gameScene(timer, Player, npcCon, bg);
	StartScene startScene(m3x6_font, window);
	
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case Event::Closed:
				window.close();
				break;
			case Event::KeyPressed:
				if (game_playing == false)
				{
					game_playing = startScene.KeyInput(event);
					timer.clockRestart();
				}
				else if (game_playing == true)
				{
					gameScene.keyInput(event);
				}
				break;
			 default:
			 	break;
			}
		}
		
		if(game_playing == true) gameScene.update(game_playing);
		
		window.clear();
		
		if (game_playing == true) gameScene.draw(window);
		else if (game_playing == false) startScene.draw(window);
		
		window.display();
	}
}
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
	// create main window
	// first argument -> videomode (the size of window, / the innersize without title bar & border size)
	// videomode 
	// 1. getDesktopMode() - Get the current desktop video mode
	// 2. VideMode(width, height) - 가로 세로 정의 
	// second argument -> the title of window
	// third argument -> a style! 
	// sf::Style::None, Titlebar, Resize(can resized, has maximize button), Close(has close button), Fullscreen(requires a video mode), Default - shortcut(Titlebar, Resize, Close)
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
	
	// Bringing thr window to life
	while (window.isOpen()) // run the program as long as the window is open
	{
		// check all the window's events that were triggered since the last iteration of the loop
		Event event;
		while (window.pollEvent(event)) // Pop the event on top of the event queue
		{
			switch (event.type) // 어떤 이벤트가 들어왔을까
			{
			case Event::Closed: // push closed button
				window.close(); // window를 종료 
				break;          // event loop를 빠져나감
			case Event::KeyPressed: // KeyBoard input
				if (game_playing == false) // game_playing이 아님 -> startScene임
				{
					game_playing = startScene.KeyInput(event); // startScene에서 input 값을 처리함.
					timer.clockRestart(); 
				}
				else if (game_playing == true) // game_playing임 -> gameScene임 
				{
					gameScene.keyInput(event); // gameScene에서 input 값을 처리함
				}
				break;
			 default:
			 	break;
			}
		}
		

		// scene update() -> clear() -> scene draw() -> display() 순으로 보여지는 화면 업데이트가 이뤄진다. 
		if(game_playing == true) gameScene.update(game_playing);
		
		window.clear();
		
		if (game_playing == true) gameScene.draw(window);
		else if (game_playing == false) startScene.draw(window);
		
		window.display();
	}
}
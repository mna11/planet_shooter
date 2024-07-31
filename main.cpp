#include <SFML/Graphics.hpp>

//header file
#include "npc.hpp"
#include "npc_set.hpp"
#include "manual_scene_npc_set.hpp"
#include "gun.hpp"
#include "manual_scene_gun.hpp"
#include "background.hpp"
#include "timer.hpp"
#include "point.hpp"
#include "game_scene.hpp"
#include "start_scene.hpp"
#include "manual_scene.hpp"
#include "end_scene.hpp"
 
#define START_Scene 0
#define GAME_Scene 1
#define MANUAL_Scene 2
#define END_Scene 3
#define Quit_Game 4

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
	Font silver_font;
	silver_font.loadFromFile("./asset/Fonts/Silver.ttf");
	
	int game_playing  = 0; // 0 - start _scene , 1 - game_scene , 2 - manual_scene, 4 - end_scene
	
	Timer timer(silver_font);
	Point point(silver_font);
	GUN Player(textures);
	MANUAL_SCENE_GUN Mplayer(textures);
	NPC_SET npcCon(10, 20.f, textures, timer, point);
	MANUAL_SCENE_NPC_SET MnpcCon(6, 30.f, textures, timer, point);
	Background bg;
	
	GameScene gameScene(timer, point, Player, npcCon, bg);
	StartScene startScene(silver_font, window);
	ManualScene manualScene(Mplayer, MnpcCon, silver_font, textures, window);
	EndScene endScene(silver_font, timer, point, window);
	
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
				if (game_playing == START_Scene) // startScene임
				{
					game_playing = startScene.KeyInput(event); // startScene에서 input 값을 처리함.
					timer.clockRestart(); 
					point.resetPoint();
				}
				else if (game_playing == GAME_Scene) // gameScene임 
				{
					gameScene.keyInput(event); // gameScene에서 input 값을 처리함
				}
				else if (game_playing == MANUAL_Scene) // manualScene임
				{
					game_playing = manualScene.keyInput(event);
				}
				else if (game_playing == END_Scene)// endScene임 
				{
					game_playing = endScene.keyInput(event);
					if (game_playing == START_Scene){
						gameScene.gamePlayAgain(); 
					}
					else if (game_playing == Quit_Game){
						window.close();
						break;
					}
				}
				break;
			 default:
			 	break;
			}
		}
		

		// scene update() -> clear() -> scene draw() -> display() 순으로 보여지는 화면 업데이트가 이뤄진다. 
		if(game_playing == GAME_Scene) {
			gameScene.update(game_playing);

			if (gameScene.gameEndCheck()) {
				game_playing = END_Scene;
				endScene.setting(window);
			}
		}
		else if (game_playing == MANUAL_Scene) manualScene.update();
		

		window.clear();
		if (game_playing == GAME_Scene) gameScene.draw(window);
		else if (game_playing == START_Scene) startScene.draw(window);
		else if (game_playing == MANUAL_Scene) manualScene.draw(window);
		else if (game_playing == END_Scene) endScene.draw(window);
		
		window.display();
	}
}
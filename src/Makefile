planet_shooter : main.o background.o end_scene.o game_scene.o gun.o manual_scene_gun.o manual_scene_npc_set.o manual_scene.o npc_set.o npc.o point.o start_scene.o timer.o 
	g++ main.o background.o end_scene.o game_scene.o gun.o manual_scene_gun.o manual_scene_npc_set.o manual_scene.o npc_set.o npc.o point.o start_scene.o timer.o -o planet_shooter -lsfml-graphics -lsfml-window -lsfml-system

main.o : main.cpp
	g++ -c main.cpp

background.o : background.cpp
	g++ -c background.cpp

end_scene.o : end_scene.cpp
	g++ -c end_scene.cpp

game_scene.o : game_scene.cpp
	g++ -c game_scene.cpp

gun.o : gun.cpp
	g++ -c gun.cpp

manual_scene_gun.o : manual_scene_gun.cpp
	g++ -c manual_scene_gun.cpp

manual_scene_npc_set.o : manual_scene_npc_set.cpp
	g++ -c manual_scene_npc_set.cpp

manual_scene.o : manual_scene.cpp
	g++ -c manual_scene.cpp

npc_set.o : npc_set.cpp
	g++ -c npc_set.cpp

npc.o : npc.cpp
	g++ -c npc.cpp

point.o : point.cpp
	g++ -c point.cpp

start_scene.o : start_scene.cpp
	g++ -c start_scene.cpp

timer.o : timer.cpp
	g++ -c timer.cpp

clean :
	rm main.o background.o end_scene.o game_scene.o gun.o manual_scene_gun.o manual_scene_npc_set.o manual_scene.o npc_set.o npc.o point.o start_scene.o timer.o planet_shooter
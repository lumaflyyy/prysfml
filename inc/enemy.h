#pragma once
#include "../inc/player.h"

class enemy : public player {
public: 
	//TODO: IA de enemy
	void impairedmovements(float vinc);
	void playerProxing(Vector2f playerpos);
	float dist_player(Vector2f playerpos);
	bool dist(Vector2f playerpos, int agro);

	//constructor de enemy con 0 armor, heredando player en el cpp
	enemy(unsigned int hp, float x, float y, string fileimage);
	//no hace falta llamar al destructor de player
	//porque el compilador ya lo hace por herencia

};

#include "../inc/enemy.h"
#include <math.h>


void enemy::impairedmovements(float vinc) {
	int direction = rand() % 4;
	if (direction == 0) move(1*vinc, 0);
	else if (direction == 1) move(-1*vinc, 0);
	else if (direction == 2) move(0, 1 * vinc);
	else move(0, -1 * vinc);
}

bool enemy::dist(Vector2f playerpos, int agro) {
	return((sqrt(pow(getPos().x - playerpos.x, 2) + pow(getPos().y - playerpos.y, 2))) <= agro); //radAgro
}
float enemy::dist_player(Vector2f playerpos) {
	return (sqrt(pow(getPos().x - playerpos.x, 2) + pow(getPos().y - playerpos.y, 2)));
}
void enemy::playerProxing(Vector2f playerpos) {
	if (dist(playerpos, 140)) {
		float relativeX = (playerpos.x - getPos().x);
		float relativeY = (playerpos.y - getPos().y);
		float cosine = relativeX / dist_player(playerpos);
		float sine = relativeY / dist_player(playerpos);
		move(-0.04 * cosine, -0.04 * sine); 
	}
}

enemy::enemy(unsigned int hp, float x, float y, string fileimage) :player(hp, 0, x, y, fileimage) {
	
}




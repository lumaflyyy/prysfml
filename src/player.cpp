#include "../inc/player.h"
//implementacion de la clase player.
unsigned int player::getHealth() {
	return health;
}
void player::incHealth(int hp) {
	if(health != 0) health += hp;
}
unsigned int player::getArmor() {
	return armor;
}
unsigned int player::getCoins() {
	return coins;
}
void player::incCoins(int coin) {
	coins += coin;
	cout << "actual coins: " << coins << endl;
}
void player::setArmor(int pAr) {
	if (armor != 0) armor += pAr;
}
Vector2f player::getPos() {
	return position;
}
void player::setPos(float x, float y) {
	position.x = x;
	position.y = y;
	sP.setPosition(getPos());
}
void player::move(float dx, float dy) {
	setPos(getPos().x + dx, getPos().y + dy);
}
bool player::isDead() {
	return (health == 0);
}
void player::fixborder() {
	if (position.x > 600 || position.y > 600
		|| position.x < 0 || position.y < 0) setPos(1, 1);
}
Sprite player::getSprite() {
	return sP;
}
player::player(unsigned int hp, unsigned int ar, float x, float y, string fileimage) {
	//SFML: the sprite doesn't store its own copy of the texture, 
	//but rather keeps a pointer to the one that you passed to this function
	texture = new Texture; 
	texture->loadFromFile(fileimage); 
	sP.setTexture(*texture); 
	health = hp;
	armor = ar;
	coins = 0;
	position.x = x;
	position.y = y; 
	sP.setPosition(getPos());
	sP.setScale(0.5, 0.5);
}

player::~player() {
	delete texture;
	texture = nullptr;
}
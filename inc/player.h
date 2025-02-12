#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
class player
{
private:
	unsigned int health;
	unsigned int armor;
	unsigned int coins;
	Texture* texture;
	Sprite sP;
	Vector2f position;
	
public:
	unsigned int getHealth();
	void incHealth(int hp); 
	unsigned int getArmor();
	unsigned int getCoins();
	void incCoins(int coin);
	void setArmor(int pAr); 
	Vector2f getPos();
	void setPos(float x, float y); 
	void move(float dx, float dy);
	bool isDead();
	void fixborder();
	Sprite getSprite();
	player(unsigned int hp, unsigned int ar, float x, float y, string fileimage);
	~player();
};

//recordar hacer:
//shoot, projectile
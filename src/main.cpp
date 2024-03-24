#include <iostream>
#include <SFML/Graphics.hpp>
#include <math.h>
#include <deque>

#include "../inc/player.h" 
#include "../inc/enemy.h"
#include "../inc/scoreboardSystems.h" //no utilizado aun

using namespace sf;
//TODO: scoreboard
int main()
{
	RenderWindow window(VideoMode(600, 600), "test1");
	//header para las constantes? DEFINITIVAMENTE SI
	const float radAgro = 150;
	const float danger = 250;
	const float dx = 0.1;
	const float dy = 0.1;
	//textura y sprite cargadas desde player.
	

	String p_texture =
		"C:/Users/Valentin/Desktop/dev/prysfml/prysfml/images/particle.png";
	player* p = new player(100, 50, 1, 1, p_texture);
	player* p2 = new player(100, 50, 580, 580, p_texture);
	std::cout << "player hp: " << p->getHealth() << endl;
	String e_texture =
		"C:/Users/Valentin/Desktop/dev/prysfml/prysfml/images/particleB.png";

	//la imagen, texture
	Texture particle;
	particle.loadFromFile(e_texture);

	//lo que puedo hacer con la imagen, transformaciones etc: sprite.
	Sprite sparticle(particle);
	Vector2f particlePos(580, 580);
	sparticle.setPosition(particlePos);
	sparticle.setScale(0.5, 0.5);
	Clock clock;
	int time = 0;
	int timed = 10;
	CircleShape agro;
	
	std::deque<std::shared_ptr<enemy>> eQ; //vector de punteros a enemigos
	//nuevo concepto: PUNTERO INTELIGENTE.
	int MAX_ENEMY;
	std::cout << "inserte el numero maximo de enemigos: ";
	std::cin >> MAX_ENEMY;
	for (int i = 1; i <= MAX_ENEMY; i++) {
		int random = rand() % 400;
		//inserto nuevos punteros por make_shared, que genera shared_ptr.
		eQ.push_back(std::make_shared<enemy>(10, 100 + random, 100 + random, e_texture));
	}
	std::cout << "enemigos restantes: "<< eQ.size() << endl;
	float vinc = 0.2;
	while (window.isOpen()) {
		Event e;
		while (window.pollEvent(e)) {
			if (e.type == Event::Closed) window.close();
			if (Keyboard::isKeyPressed(Keyboard::Escape)) window.close();
		}
		p->fixborder();
		p2->fixborder();
		
		//box particle movement

		if (Keyboard::isKeyPressed(Keyboard::W)) p->move(0, -dy);
		if (Keyboard::isKeyPressed(Keyboard::A)) p->move(-dx, 0);
		if (Keyboard::isKeyPressed(Keyboard::S)) p->move(0, dy);
		if (Keyboard::isKeyPressed(Keyboard::D)) p->move(dx, 0);

		if (Keyboard::isKeyPressed(Keyboard::I)) p2->move(0, -dy);
		if (Keyboard::isKeyPressed(Keyboard::J)) p2->move(-dx, 0);
		if (Keyboard::isKeyPressed(Keyboard::K)) p2->move(0, dy);
		if (Keyboard::isKeyPressed(Keyboard::L)) p2->move(dx, 0);
		
		agro.setRadius(30);
		//el centro no debe ser la esquina del objeto 
		agro.setOrigin(-10 + 30, -10 + 30);
		agro.setPosition(p->getPos());
		agro.setOutlineColor(Color::Black);
		agro.setOutlineThickness(1.5);
		
		window.clear(Color::Cyan);

		//generacion y borrado de enemy si dist es true usando vector
		//incrementa velocidad conforme mas lo pickeo
		
		if (!eQ.empty()) {
			//x->impairedmovements(vinc);
			eQ.front()->playerProxing(p->getPos());
			eQ.front()->playerProxing(p2->getPos());
			eQ.front()->fixborder();
			window.draw(eQ.front()->getSprite());
			if (eQ.front()->dist(p->getPos(), 30) || eQ.front()->dist(p2->getPos(), 30)) {
				//todos los metodos pop de la STL se encargan
				//de llamar a los destructors.
				eQ.pop_front(); //orden 1
				cout << "enemigos restantes: " << eQ.size() << endl;
			}
		}
		else std::cout << "game over " << std::cin.get();

		window.draw(agro);
		window.draw(p->getSprite());
		window.draw(p2->getSprite());
		window.display();
	}
	std::cin.get();
	delete p;
	return 0;
}
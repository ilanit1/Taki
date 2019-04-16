/* Ilanit Dadon 208950667 */
#pragma once
#define GAME_H
#include "Player.h"
#include "Card.h"
#include <list>
using namespace std;

class Game {

private:

	Card current_card;
	list<Player*> players;
	string direction;
	
	Game(const Game& game){};
	Game & operator= (const Game & game) {
		return *this;
	};

public:

	Game();
	~Game();

	void start();
};



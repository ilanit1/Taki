/* Ilanit Dadon 208950667 */
#define PLAYER_H
#pragma once
#include <vector>
#include "Card.h"
#pragma once
using namespace std;


class Player {

private:

	string name;
	int num_of_cards;
	vector<Card> cards;

public:

    Player();
	Player(string name, int num_of_cards);
	Player(const Player& player);
	Player & operator = (const Player& player);

	void print_cards() const{
		for (size_t i = 0; i < cards.size(); i++) {
		cout << "(" << i + 1 << ")" << cards[i] << " ";
		}
	}
	
	string get_name() const {
		return name;
	}
	
	int get_num_of_cards() const { 
		return num_of_cards;
	}
	
	vector<Card> get_cards() const {
		return cards; 
	}

	bool play(Card&);
};



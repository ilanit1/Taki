/* Ilanit Dadon 208950667 */
#include "Player.h"

Player::Player(string name, int num_of_cards){
	
	this->name = name;
	this->num_of_cards = num_of_cards;
	vector<Card> temp(0);
	cards = temp;
	for (int i = 0; i < num_of_cards; i++) {
		cards.push_back(Card::generate_card());
	}
}

Player::Player(const Player& player) {
	name = player.name;
	num_of_cards = player.num_of_cards;
	cards.clear();
	for (int i = 0; i < num_of_cards; i++) {
		cards.push_back(player.cards[i]);
	}
}

Player & Player::operator =(const Player& player) {
	
	name = player.name;
	num_of_cards = player.num_of_cards;
	vector<Card> temp(num_of_cards);
	cards = temp;
	for (int i = 0; i < num_of_cards; ++i) {
		cards[i] = player.cards[i];
	}
	return *this;
}


bool Player::play(Card & current_card) {
	
	cout << "current: " << current_card << endl;
	cout << get_name() << ", your turn - " << endl;
	cout << "Your cards: ";
	print_cards();
	cout << endl;

	int choice;
	cin >> choice;
	
	if (choice > int(get_cards().size()) || choice <= 0) { //take card from the kupa
		Card c = c.generate_card();
		cards.push_back(c);
		num_of_cards++;
		return false;
	}

	while (current_card.is_legal(get_cards()[choice - 1]) == false) {
		
		cout << "You can't put " << get_cards()[choice - 1] << " on " << current_card << endl;
		cin >> choice;
		
		if (choice > int(get_cards().size()) || choice <= 0) {//take card from the kupa
			Card c = c.generate_card();
			cards.push_back(c);
			num_of_cards++;
			return false;
		}
	}
	
	if (current_card.is_legal(get_cards()[choice - 1]) == true) {
		
		current_card = get_cards()[choice - 1];
		cards.erase(cards.begin() + choice - 1);
		num_of_cards--;
		return true;
	}
	return false;
}


/* Ilanit Dadon 208950667 */
#include "Game.h"

Game::Game() {
	
	direction = "right";
	list<Player*> players(0);
}

Game::~Game() {
	
	players.clear();
	int len = players.size();
	for (int i = 0; i < len; i++) {
		delete[] players.back();
	}
}

void Game::start() {
	
	int num_of_players=0;
	int num_of_cards=0;
	int win=0;

	cout << "How many players?" << endl;
	cin >> num_of_players;
	
	if (num_of_players <= 0){
		cout << "Not valid number" << endl; 
		return; 
	}
		
	cout << "How many cards?" << endl;
	cin >> num_of_cards;
	
	if (num_of_cards <= 0){
		cout << "Not valid number" << endl;
		return; 
	}

	for (int i = 0; i < num_of_players; i++) {
		string name = "";
		cout << "player number " << (i + 1) << " name?" << endl;
		cin >> name;
		players.push_back(new Player(name, num_of_cards));
	}

	current_card = Card::generate_card();
	list<Player*>::iterator it= players.begin();

	while (win == 0) { //no one has won yet
	
		bool played = (*it)->play(current_card);
		
		if ((*it)->get_cards().size() == 0) {//the player finish all his cards
			cout << (*it)->get_name() << " wins!" << endl;
			win = 1;
			break;
		}
		
		else {//he have cards
	
			if (current_card.get_sign() != sign::CD) {
		
	        	if (direction.compare("right") == 0) {
			
		        	if (current_card.get_sign() == sign::STOP && played == true) {
				
			        	if (*it == players.back()){
				        	it = players.begin();
				        	it++; 
			        	}
				
			        	else if (it == (++(++players.rbegin())).base())  
				        	it = players.begin(); 
					
			        	else {
				        	it++;
				        	it++;
				    	}
		        	}
		        	
			       else if (current_card.get_sign() != sign::PLUS || played == false) {
				
			         	if (*it == players.back()) 
				         	it = players.begin(); 
					
				        else 
				            ++it;
			        }
	        	}
	        	
	        	else {//left
		        	if (current_card.get_sign() == sign::STOP && played == true) {
				
			        	if (it == players.begin()) {
				        	*it = players.back();
				        	it--; 
			    	    }
				
				        else if (it == (++players.begin())) {
				        	*it = players.back();
			        	} 
				
			         	else {
				         	it--;
				        	it--;
			        	}
		        	}
		        	
			        else if (current_card.get_sign() != sign::PLUS || played == false) {
				
			        	if (it == players.begin()) 
				        	*it = players.back();
				
			         	else 
			            	--it;
		         	}
		         }
        	}

        	else { //direction changed
	
	         	if (players.size() != 2) {
			
		        	if (direction.compare("right") == 0) {
				
			        	if (played == true)
			           	   direction = "left";
				  
			        	if (it == players.begin()) 
				           *it = players.back(); 
					
				        else 
				           --it;
		        	}
			
			        else {
				
			        	if (played == true)
				           direction = "right";
				  
				        if (*it == players.back())
				        	it = players.begin();
					
				        else 
				          ++it;
		        	}
		        }
		
	         	else {
			
			       if (played == false) {
			        	if (*it == players.back()) 
			         		it = players.begin(); 
					
			        	else 
				          ++it;
		        	}
	        	}
        	}
		}
	}
}
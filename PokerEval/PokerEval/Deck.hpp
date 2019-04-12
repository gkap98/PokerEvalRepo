//
//  Deck.hpp
//  PokerEval
//
//  Created by Gavin Kaepernick on 4/12/19.
//  Copyright © 2019 Gavin Kaepernick. All rights reserved.
//

#ifndef Deck_hpp
#define Deck_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include "Card.h"

#endif /* Deck_hpp */

#pragma once
using namespace std;

class Deck {
	
public:
	Deck();
	
	vector<Card> dealCards(int numCards, vector<Card>& hand); //takes in the number of cards
	vector<Card> shuffleDeck();
	vector<Card> getDeck();
private:
	vector<Card> deck;
};

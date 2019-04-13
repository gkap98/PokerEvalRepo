//
//  PokerEvaluator.hpp
//  PokerEval
//
//  Created by Gavin Kaepernick on 4/12/19.
//  Copyright © 2019 Gavin Kaepernick. All rights reserved.
//

#ifndef PokerEvaluator_hpp
#define PokerEvaluator_hpp

#include <stdio.h>
#include <iostream>
#include <vector>

#endif /* PokerEvaluator_hpp */


#pragma once
using namespace std;

class PokerEvaluator {
	
public:
	PokerEvaluator(vector<Card> Hand);
	bool compareNumerica(Card c1, Card c2);
	vector<Card> getHand();
	bool isPair();
	bool isTwoPair();
	bool isThreeOfAKind();
	bool isStraight();
	bool isFlush();
	bool isFullHouse();
	bool isFourOfAKind();
	bool isStraightFlush();
	bool isRoyalFlush();
	string printScore();
	
	vector<Card> Hand;
	
};


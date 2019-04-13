//
//  PokerEvaluator.cpp
//  PokerEval
//
//  Created by Gavin Kaepernick on 4/12/19.
//  Copyright © 2019 Gavin Kaepernick. All rights reserved.
//

#include <iostream>
#include <vector>
#include "Deck.hpp"
#include "Card.h"
#include "PokerEvaluator.hpp"

using namespace std;

PokerEvaluator::PokerEvaluator(vector<Card> Hand) {
	
}

bool PokerEvaluator::compareNumerica(Card c1, Card c2) {
	return c1.getNumericValue() < c2.getNumericValue();
}

vector<Card> PokerEvaluator::getHand() {
	return Hand;
}

bool PokerEvaluator::isPair() {
	Deck d;
	d.dealCards(7, Hand);
	bool retVal = false;
	for (int i = 0; i < Hand.size(); i++) {
		if (Hand[i].getNumericValue() == Hand[i + 1].getNumericValue()) {
			retVal = true;
		}
	}
	return retVal;
}

bool PokerEvaluator::isTwoPair() {
	Deck d;
	d.dealCards(7, Hand);
	bool retVal = false;
	for (int i = 0; i < Hand.size(); i++) {
		//find the pair first
		if (Hand[i].getNumericValue() == Hand[i + 1].getNumericValue()) {
			Card c = Hand[i];
			for (int j = 0; j < Hand.size(); j++) {
				if (Hand[j].getNumericValue() == Hand[j + 1].getNumericValue() && Hand[j].getNumericValue() != c.getNumericValue()) {
					retVal = true;
					break;
				}
			}
		}
	}
	return retVal;
}

bool PokerEvaluator::isThreeOfAKind() {
	Deck d;
	d.dealCards(7, Hand);
	bool retVal = false;
	//Mark said three of a kind only needs to check up to the last two spots
	//- 2 for overflow
	for (int i = 0; i < Hand.size() - 2; i++) {
		if (Hand[i].getNumericValue() == Hand[i+1].getNumericValue() && Hand[i].getNumericValue() == Hand[i+2].getNumericValue()) {
			retVal = true;
			break;
		}
	}
	return retVal;
}

bool PokerEvaluator::isStraight() {
	bool retVal = false;
	int count = 0;
	Deck d;
	d.dealCards(7, Hand);
	vector<Card> temp = Hand;
	
	for (int i = 0; i < temp.size()-1; i++) {
		if (temp[i].getNumericValue() == temp[i+1].getNumericValue()) {
			temp.erase(temp.begin() + i, temp.begin() + (i+1));
			i--;
		}
	}
	
	if (temp.size() < 5) {
		retVal = false;
	}
	
	for (int i = 0; i < temp.size() -1; i++) {
		if ((temp[i].getNumericValue() - temp[i+1].getNumericValue()) == 1) {
			count++;
		}
	}
	
	if (count == 4) {
		retVal = true;
	}
	else {
		retVal = false;
	}
	return retVal;
}

bool PokerEvaluator::isFlush() {
	bool retVal = false;
	int count = 1;
	Deck d;
	d.dealCards(7, Hand);
	
	
	for (int i = 0; i < Hand.size() - 1; i++) {
		if (Hand[i].getSuit() == Hand[i+1].getSuit()) {
			count++;
			if (count == 5) {
				retVal = true;
				break;
			}
		}
	}
	return retVal;
}

bool PokerEvaluator::isFullHouse() {
	bool retVal = false;
	Deck d;
	d.dealCards(7, Hand);
	
	if (isTwoPair()) {
		if (isThreeOfAKind()) {
			retVal = true;
		}
	}
	return retVal;
}

bool PokerEvaluator::isFourOfAKind() {
	bool retVal = false;
	Deck d;
	d.dealCards(7, Hand);
	for (int i = 0; i < Hand.size()-3; i++) {
		if (Hand[i].getNumericValue() == Hand[i+1].getNumericValue()) {
			if (Hand[i].getNumericValue() == Hand[i+2].getNumericValue()) {
				if (Hand[i].getNumericValue() == Hand[i+3].getNumericValue()) {
					retVal = true;
				}
			}
		}
	}
	return retVal;
}

bool PokerEvaluator::isStraightFlush() {
	bool retVal = false;
	Deck d;
	d.dealCards(7, Hand);
	
	int count = 0;
	int clubs = 0;
	int diamonds = 0;
	int hearts = 0;
	int spades = 0;
	
	string suit;
	
	for (int i = 0; i < Hand.size(); i++) {
		if (Hand[i].getSuit() == "Clubs")
			clubs++;
		if (Hand[i].getSuit() == "Diamonds")
			diamonds++;
		if (Hand[i].getSuit() == "Hearts")
			hearts++;
		if (Hand[i].getSuit() == "Spades")
			spades++;
	}
	if (clubs >= 5) {
		suit = "Clubs";
	}
	else if (diamonds >= 5) {
		suit = "Diamonds";
	}
	else if (hearts >= 5) {
		suit = "Hearts";
	}
	else if (spades >= 5) {
		suit = "Spades";
	}
	else {
		retVal = false;
	}
	
	for (unsigned long i = Hand.size() - 1; i > 0; i--) {
		if ((Hand[i].getNumericValue() - Hand[i -1].getNumericValue()) == 1) {
			count++;
		}
	}
	
	if (count >= 4) {
		retVal = true;
	}
	else {
		retVal = false;
	}
	return retVal;
}

bool PokerEvaluator::isRoyalFlush() {
	bool retVal = false;
	Deck d;
	d.dealCards(7, Hand);
	
	string suit;
	int count = 0;
	int clubs = 0;
	int diamonds = 0;
	int hearts = 0;
	int spades = 0;
	
	for (int i = 0; i < Hand.size(); i++) {
		if (Hand[i].getSuit() == "Clubs")
			clubs++;
		if (Hand[i].getSuit() == "Diamonds")
			diamonds++;
		if (Hand[i].getSuit() == "Hearts")
			hearts++;
		if (Hand[i].getSuit() == "Spades")
			spades++;
	}
	
	if (clubs >= 4) {
		suit = "Clubs";
	}
	else if (diamonds >= 4) {
		suit = "Diamonds";
	}
	else if (hearts >= 4) {
		suit = "Hearts";
	}
	else if (spades >= 4) {
		suit = "Spades";
	}
	else {
		retVal = false;
	}
	
	for (int i = 0; i < Hand.size(); i++) {
		if (Hand[i].getNumericValue() > 9 && Hand[i].getSuit() == suit) {
			count++;
		}
	}
	if (count == 5) {
		retVal = true;
	}
	else {
		retVal = false;
	}
	
	return retVal;
}

string PokerEvaluator::printScore() {
	if (isPair()) {
		return "It's a Pair";
	}
	else if (isTwoPair()) {
		return "It's a Two Pair";
	}
	else if (isThreeOfAKind()) {
		return "It's a Three of a Kind";
	}
	else if(isStraight()) {
		return "It's a Straight";
	}
	else if(isFlush()) {
		return "It's a Flush";
	}
	else if (isFullHouse()) {
		return "It's a Full House";
	}
	else if (isFourOfAKind()) {
		return "It's Four of a Kind";
	}
	else if (isStraightFlush()) {
		return "It's a Straight Flush";
	}
	else if (isRoyalFlush()) {
		return "It's a Royal Flush";
	}
	else {
		return "you have a high card";
	}
}

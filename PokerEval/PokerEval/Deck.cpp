//
//  Deck.cpp
//  PokerEval
//
//  Created by Gavin Kaepernick on 4/12/19.
//  Copyright © 2019 Gavin Kaepernick. All rights reserved.
//

#include "Deck.hpp"
#include "Card.h"
#include <iostream>
#include <vector>
#include <ctime>
#include <random>

using namespace std;

Deck::Deck() {
	//create new Deck vector to hold the deck
	string suits[] = {"Clubs", "Diamonds", "Hearts", "Spades"};
	for (int i = 0; i < 4; i++)
	{
		for (int num = 2; num <= 14; num++)
		{
			Card c(num, suits[i]);
			deck.push_back(c);
		}
	}
}

vector<Card> Deck::shuffleDeck() {
	vector<Card> newDeck = deck;
	for(size_t i = 0; i < newDeck.size(); i++) {
		size_t position = rand() % 52;
		Card t = newDeck[i];
		newDeck[i] = newDeck[position];
		newDeck[position] = t;
	}
	deck = newDeck;
	return deck;
}

vector<Card> Deck::dealCards(int numCards, vector<Card>& hand) {
	//Catch system
	if(numCards <= 0 || numCards > 52) {
		cout << "Ask for cards between 0 and 52" << endl;
	}
	//Grabbing certain number of cards
	for(int i = 0; i < numCards; i++) {
		hand.push_back(deck[0]);
		deck.erase(deck.begin());
	}
	return hand;
}

vector<Card> Deck::getDeck() {
	return deck;
}

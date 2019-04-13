//
//  main.cpp
//  PokerEval
//
//  Created by Gavin Kaepernick on 4/12/19.
//  Copyright © 2019 Gavin Kaepernick. All rights reserved.
//

#include <iostream>
using namespace std;

#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include "Card.h"
#include "Deck.hpp"

int main()
{
	cout << "Hello World!!!" << endl;
	
	Catch::Session().run();
	
	return 0;
}

TEST_CASE("Test Cards")
{
	SECTION("Test create bad cards")
	{
		Card c1(-10, "Hearts");
		Card c2(10, "Fish");
		Card c3(-10, "Fish");
		
		REQUIRE(c1.getNumericValue() == 2);
		REQUIRE(c1.getSuit() == "Hearts");
		REQUIRE(c2.getNumericValue() == 10);
		REQUIRE(c2.getSuit() == "Clubs");
		REQUIRE(c3.getNumericValue() == 2);
		REQUIRE(c3.getSuit() == "Clubs");
	}
	
	SECTION("Test create 52 cards")
	{
		string suits[] = {"Clubs", "Diamonds", "Hearts", "Spades"};
		for (int i = 0; i < 4; i++)
		{
			for (int num = 2; num <= 14; num++)
			{
				Card c(num, suits[i]);
				REQUIRE(c.getNumericValue() == num);
				REQUIRE(c.getSuit() == suits[i]);
			}
		}
	}
	
	SECTION("Test toString()")
	{
		Card c1(3, "Diamonds");
		Card c2(10, "Hearts");
		Card c3(14, "Spades");
		
		REQUIRE(c1.toString() == "3 of Diamonds");
		REQUIRE(c2.toString() == "10 of Hearts");
		REQUIRE(c3.toString() == "Ace of Spades");
	}
}
TEST_CASE("Test Deck") {
	SECTION("Test Create Deck") {
		Deck d;
		int counter = 0;
		for(int i = 0; i < d.getDeck().size(); i++) {
			counter++;
		}
		REQUIRE(counter == 52);
	}
//	SECTION("Test Shuffle") {
//		Deck d;
//		Deck e;
//		e.shuffleDeck();
//		vector<Card> deck1 = d.getDeck();
//		vector<Card> deck2 = d.getDeck();
//
//		for(int i = 0; i < d.getDeck().size(); i++) {
//			for(int j = 0; j < e.getDeck().size(); j++) {
//				
//			}
//		}
//	}
	SECTION("Test Get Deck") {
		Deck d;
		REQUIRE(d.getDeck().size() == 52);
	}
	SECTION("Test Deal Cards") {
		Deck d;
		vector<Card> Hand;
		d.dealCards(7, Hand);
		REQUIRE(Hand.size() == 7);
	}
}

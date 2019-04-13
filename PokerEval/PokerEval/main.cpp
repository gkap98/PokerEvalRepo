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
#include "PokerEvaluator.hpp"

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
	SECTION("Test Shuffle") {
		Deck d;
		Deck e;
		e.shuffleDeck();
		
		vector<Card> deckD = d.getDeck();
		vector<Card> deckE = e.getDeck();
		
		REQUIRE(deckD[0].toString() != deckE[0].toString());
	}
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
TEST_CASE("Test Poker Evaluator") {
	SECTION("Test Pair") {
		Card c1(2, "Spades");
		Card c2(4, "Diamonds");
		Card c3(3, "Clubs");
		Card c4(3, "Hearts");
		Card c5(12, "Diamonds");
		Card c6(10, "Clubs");
		Card c7(9, "Hearts");
		
		vector<Card> Hand = {c1, c2, c3, c4, c5, c6, c7 };
		PokerEvaluator h = PokerEvaluator(Hand);
		REQUIRE(h.printScore() == "It's a Pair");
	}
	SECTION("Test Two Pair") {
		Card c1(2, "Spades");
		Card c2(4, "Diamonds");
		Card c3(3, "Clubs");
		Card c4(3, "Hearts");
		Card c5(4, "Diamonds");
		Card c6(10, "Clubs");
		Card c7(9, "Hearts");

		vector<Card> Hand = {c1, c2, c3, c4, c5, c6, c7 };
		PokerEvaluator h = PokerEvaluator(Hand);
		REQUIRE(h.printScore() == "It's a Two Pair");
	}
	SECTION("Test Three of a Kind") {
		Card c1(2, "Spades");
		Card c2(3, "Diamonds");
		Card c3(3, "Clubs");
		Card c4(3, "Hearts");
		Card c5(4, "Diamonds");
		Card c6(10, "Clubs");
		Card c7(9, "Hearts");
		
		vector<Card> Hand = {c1, c2, c3, c4, c5, c6, c7 };
		PokerEvaluator h = PokerEvaluator(Hand);
		REQUIRE(h.printScore() == "It's a Three of a Kind");
	}
	SECTION("Test Straight") {
		Card c1(7, "Clubs");
		Card c2(8, "Hearts");
		Card c3(9, "Diamonds");
		Card c4(10, "Hearts");
		Card c5(11, "Spades");
		Card c6(2, "Clubs");
		Card c7(9, "Hearts");
		
		vector<Card> Hand = {c1, c2, c3, c4, c5, c6, c7 };
		PokerEvaluator h = PokerEvaluator(Hand);
		REQUIRE(h.printScore() == "It's a Straight");
	}
	SECTION("Test Flush") {
		vector<Card> Hand;
		for (int i = 2; i < 5; i++)
		{
			Card c(i, "Hearts");
			Hand.push_back(c);
		}
		for (int i = 7; i < 11; i++)
		{
			Card c(i, "Hearts");
			Hand.push_back(c);
		}
		
		PokerEvaluator h = PokerEvaluator(Hand);
		REQUIRE(h.printScore() == "It's a Flush");
	}
	SECTION("Test Full House") {
		Card c1(8, "Clubs");
		Card c2(8, "Spades");
		Card c3(8, "Hearts");
		Card c4(10, "Clubs");
		Card c5(10, "Diamonds");
		Card c6(2, "Spades");
		Card c7(3, "Clubs");
		
		vector<Card> Hand = {c1, c2, c3, c4, c5, c6, c7 };
		PokerEvaluator h = PokerEvaluator(Hand);
		REQUIRE(h.printScore() == "It's a Full House");
	}
	SECTION("Test Four of a Kind") {
		Card c1(8, "Clubs");
		Card c2(8, "Spades");
		Card c3(8, "Hearts");
		Card c4(8, "Diamonds");
		Card c5(10, "Diamonds");
		Card c6(2, "Spades");
		Card c7(3, "Clubs");
		
		vector<Card> Hand = {c1, c2, c3, c4, c5, c6, c7 };
		PokerEvaluator h = PokerEvaluator(Hand);
		REQUIRE(h.printScore() == "It's a Four of a Kind");
	}
	SECTION("Test for Straight Flush") {
		Card c1(8, "Clubs");
		Card c2(6, "Clubs");
		Card c3(7, "Clubs");
		Card c4(8, "Clubs");
		Card c5(9, "Clubs");
		Card c6(2, "Clubs");
		Card c7(3, "Clubs");
		
		vector<Card> Hand = {c1, c2, c3, c4, c5, c6, c7 };
		PokerEvaluator h = PokerEvaluator(Hand);
		REQUIRE(h.printScore() == "It's a Straight Flush");
	}
	SECTION("Test for Royal Flush") {
		Card c1(11, "Clubs");
		Card c2(12, "Clubs");
		Card c3(13, "Clubs");
		Card c4(14, "Clubs");
		Card c5(10, "Diamonds");
		Card c6(2, "Spades");
		Card c7(3, "Clubs");
		
		vector<Card> Hand = {c1, c2, c3, c4, c5, c6, c7 };
		PokerEvaluator h = PokerEvaluator(Hand);
		REQUIRE(h.printScore() == "It's a Royal Flush");
	}
	SECTION("Test High Card") {
		Card c1(13, "Clubs");
		Card c2(1, "Hearts");
		Card c3(4, "Clubs");
		Card c4(10, "Clubs");
		Card c5(10, "Diamonds");
		Card c6(2, "Spades");
		Card c7(3, "Diamonds");
		
		vector<Card> Hand = {c1, c2, c3, c4, c5, c6, c7 };
		PokerEvaluator h = PokerEvaluator(Hand);
		REQUIRE(h.printScore() == "you have a high card");
	}
}

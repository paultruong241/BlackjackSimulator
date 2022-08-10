/********************************************************
 * @file Deck.h
 *
 * @brief This file displays the Deck class.
 *
 * @author Paul Truong
 * @date 08-08-2022
 *
 *******************************************************/
#pragma once

#include "Card.h"
#include <vector>

class Deck
{
public:
	const unsigned numOfCardsInADeck = 52;

	Deck(const unsigned numOfDecks);

	void SetDeck(const unsigned numOfDecks);
	void Shuffle();
	Card Draw();
	unsigned CheckDeckSize() const;
	unsigned CheckDeckUsage() const;

private:
	unsigned numOfDecks = 0;
	std::vector<Card> deck;
};


/********************************************************
 * @file Deck.cpp
 *
 * @brief This file displays the Deck class.
 *
 * @author Paul Truong
 * @date 08-08-2022
 *
 *******************************************************/
#include "Deck.h"
#include <random>
#include <algorithm>

/// <summary>
/// Constructor.
/// </summary>
/// <param name="numOfDecks">Number of decks in play.</param>
Deck::Deck(const unsigned numOfDecks) : numOfDecks(numOfDecks)
{
	SetDeck(numOfDecks);
}

/// <summary>
/// Set the deck.
/// </summary>
/// <param name="numOfDecks">Number of decks in play.</param>
void Deck::SetDeck(const unsigned numOfDecks)
{
	deck.clear();

	for (unsigned deckIdx = 0; deckIdx < numOfDecks; deckIdx++)
	{
		for (int valueIdx = Card::Value::Two; valueIdx <= Card::Value::Ace; valueIdx++)
		{
			for (int suitIdx = Card::Suit::Clover; suitIdx <= Card::Suit::Spade; suitIdx++)
			{
				deck.emplace_back(Card::Value(valueIdx), Card::Suit(suitIdx));
			}
		}
	}

	Shuffle();
}

/// <summary>
/// Shuffles the deck.
/// </summary>
void Deck::Shuffle()
{
	std::random_device rd;
	std::mt19937 g(rd());

	std::shuffle(deck.begin(), deck.end(), g);
}

/// <summary>
/// Draws a card from the back of the deck.
/// </summary>
/// <returns>Drawn card.</returns>
Card Deck::Draw()
{
	Card drawnCard = deck.back();
	deck.pop_back();

	return drawnCard;
}

/// <summary>
/// Checks the number of remaining cards in deck.
/// </summary>
/// <returns>Number of remaining cards.</returns>
unsigned Deck::CheckDeckSize() const
{
	return deck.size();
}

/// <summary>
/// Checks the deck usage.
/// </summary>
/// <returns>Percent of deck used.</returns>
unsigned Deck::CheckDeckUsage() const
{
	float originalDeckSize = static_cast<float>(numOfCardsInADeck) * static_cast<float>(numOfDecks);
	unsigned deckPercentLeft = (deck.size() / originalDeckSize) * 100;
	return 100 - deckPercentLeft;
}
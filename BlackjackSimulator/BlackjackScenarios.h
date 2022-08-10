/********************************************************
 * @file BlackjackScenarios.h
 *
 * @brief This file displays the Blackjack class.
 *
 * @author Paul Truong
 * @date 08-08-2022
 *
 *******************************************************/
#pragma once

#include "Deck.h"
#include "Hand.h"
#include "Strategies.h"

class BlackjackScenarios
{
public:
	enum class Results {
		Win, BigWin, Lose, Push, Surrender
	};

	BlackjackScenarios(unsigned numOfDecks, unsigned resetPercent, unsigned numOfGames);

	unsigned GetWins() const;
	unsigned GetBigWins() const;
	unsigned GetLosses() const;
	unsigned GetPushes() const;
	unsigned GetSurrenders() const;

	void Blackjacks();
	Results Blackjack(Deck& deck);
	void Drawing(Deck& deck, std::string person, Hand& Hand);
	void Dealing(Deck& deck, Hand& playerHand, Hand& dealerHand);
	void PlayerExecutes(Deck& deck, Strategies& playerStrategy, Hand& playerHand, Hand& dealerHand);
	void DealerExecutes(Deck& deck, Hand& dealerHand);
	Results Showdown(Strategies& playerStrategy, Hand& playerHand, Hand& dealerHand);
	void CountResults(BlackjackScenarios::Results result);

private:
	unsigned numOfDecks = 0;
	unsigned resetPercent = 0;
	unsigned numOfGames = 0;

	unsigned numOfWins = 0;
	unsigned numOfBigWins = 0;
	unsigned numOfLosses = 0;
	unsigned numOfPushes = 0;
	unsigned numOfSurrenders = 0;
};


/********************************************************
 * @file Strategies.h
 *
 * @brief This file displays all strategies for Blackjack.
 *
 * @author Paul Truong
 * @date 08-08-2022
 *
 * @note Add soft strategies.
 *       Add more split strategies.
 *
 *******************************************************/
#pragma once

#include "Deck.h"
#include "Hand.h"

class Strategies
{
public:
	enum class Actions {
		Split, Surrender, DoubleDown, Hit, Stand
	};

	Strategies(bool enableSurrender, bool enableSplit, bool enableDouble);

	Actions GetAction() const { return performedAction; }

	void ExecuteStrategies(Hand& playerHand, Hand& dealerHand);
	bool SurrenderStrategies(Hand& playerHand, Hand& dealerHand);
	bool SplitStrategies(Hand& playerHand, Hand& dealerHand);
	bool DoubleStrategies(Hand& playerHand, Hand& dealerHand);
	bool HitStrategies(Hand& playerHand, Hand& dealerHand);

private:
	Actions performedAction = Actions::Stand;

	bool enableSurrender = false;
	bool enableSplit = false;
	bool enableDouble = false;
};


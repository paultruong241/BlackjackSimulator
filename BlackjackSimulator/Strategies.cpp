/********************************************************
 * @file Strategies.cpp
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
#include "Strategies.h"
#include <iostream>

 /// <summary>
 /// Constructor.
 /// </summary>
 /// <param name="enableSurrender">Surrenders enables.</param>
 /// <param name="enableSplit">Splits enables.</param>
 /// <param name="enableDouble">Double-down enables. </param>
Strategies::Strategies(bool enableSurrender, bool enableSplit, bool enableDouble) :
	enableSurrender(enableSurrender), enableSplit(enableSplit), enableDouble(enableDouble)
{
}

/// <summary>
/// Execute all desired strategies.
/// </summary>
void Strategies::ExecuteStrategies(Hand& playerHand, Hand& dealerHand)
{
	if (enableSurrender && SurrenderStrategies(playerHand, dealerHand))
	{
		performedAction = Actions::Surrender;
		return;
	}

	if (enableSplit && SplitStrategies(playerHand, dealerHand))
	{
		performedAction = Actions::Split;
		return;
	}

	if (enableDouble && DoubleStrategies(playerHand, dealerHand))
	{
		performedAction = Actions::DoubleDown;
		return;
	}

	if (HitStrategies(playerHand, dealerHand))
	{
		performedAction = Actions::Hit;
	}
	else
	{
		performedAction = Actions::Stand;
	}
}

/// <summary>
/// Strategies for surrendering.
/// </summary>
/// <param name="playerHand">Player hand.</param>
/// <param name="dealerHand">Dealer hand.</param>
/// <returns>True if surrendering. False if not.</returns>
bool Strategies::SurrenderStrategies(Hand& playerHand, Hand& dealerHand)
{
	if (playerHand.getCards().size() != 2)
	{
		return false;
	}

	bool hasHighCard = false;

	if (dealerHand.getCards().front().getValue() >= Card::Value::Nine)
	{
		hasHighCard = true;
	}

	unsigned playerTotalCardValue = playerHand.getHardTotal();

	if ((playerTotalCardValue == 16 || playerTotalCardValue == 15) && hasHighCard)
	{
		return true;
	}

	return false;
}

/// <summary>
/// Strategies for splitting.
/// </summary>
/// <param name="playerHand">Player hand.</param>
/// <param name="dealerHand">Dealer hand.</param>
/// <returns>True if splitting. False if not.</returns>
bool Strategies::SplitStrategies(Hand& playerHand, Hand& dealerHand)
{
	std::vector<Card> playerCards = playerHand.getCards();

	if (playerCards[0].getValue() != playerCards[1].getValue() || playerCards.size() != 2)
	{
		return false;
	}

	if (playerCards[0].getValue() == Card::Eight || playerCards[0].getValue() == Card::Ace)
	{
		return true;
	}

	return false;
}

/// <summary>
/// Strategies for double downing.
/// </summary>
/// <param name="playerHand">Player hand.</param>
/// <param name="dealerHand">Dealer hand.</param>
/// <returns>True if double downing. False if not.</returns>
bool Strategies::DoubleStrategies(Hand& playerHand, Hand& dealerHand)
{
	if (playerHand.getCards().size() != 2)
	{
		return false;
	}

	unsigned playerTotal = playerHand.getSoftTotal();
	unsigned dealerTotal = dealerHand.getHardTotal();

	if ((playerTotal == 11) ||
		(playerTotal == 10 && dealerTotal >= 2 && dealerTotal <= 9) ||
		(playerTotal == 9 && dealerTotal >= 3 && dealerTotal <= 6))
	{
		return true;
	}

	return false;
}

/// <summary>
/// Strategies for hitting with a hard total.
/// </summary>
/// <param name="playerHand">Player hand.</param>
/// <param name="dealerHand">Dealer hand.</param>
/// <returns>True if hit. False if stand.</returns>
bool Strategies::HitStrategies(Hand& playerHand, Hand& dealerHand)
{
	unsigned playerSoftTotal = playerHand.getSoftTotal();
	unsigned playerHardTotal = playerHand.getHardTotal();
	unsigned dealerTotal = dealerHand.getSoftTotal();

	if ((playerSoftTotal >= 17 && playerSoftTotal <= 21) ||
		(playerHardTotal >= 17) ||
		(playerHardTotal == 16 && dealerTotal >= 2 && dealerTotal <= 6) ||
		(playerHardTotal == 15 && dealerTotal >= 2 && dealerTotal <= 6) ||
		(playerHardTotal == 14 && dealerTotal >= 2 && dealerTotal <= 6) ||
		(playerHardTotal == 13 && dealerTotal >= 2 && dealerTotal <= 6) ||
		(playerHardTotal == 12 && dealerTotal >= 4 && dealerTotal <= 6))
	{
		return false;
	}

	return true;
}
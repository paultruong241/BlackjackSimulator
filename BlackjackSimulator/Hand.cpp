/********************************************************
 * @file Hand.cpp
 *
 * @brief This file displays the Hand class.
 *
 * @author Paul Truong
 * @date 08-08-2022
 *
 *******************************************************/
#include "Hand.h"
#include <iostream>
#include <string>

 /// <summary>
 /// Constructor.
 /// </summary>
Hand::Hand()
{
}

/// <summary>
/// Gets the hand's cards.
/// </summary>
/// <returns>Hand's cards.</returns>
std::vector<Card> Hand::getCards() const
{
	return cards;
}

/// <summary>
/// Gets the hand's soft total.
/// </summary>
/// <returns>Hand's soft total.</returns>
unsigned Hand::getSoftTotal() const
{
	return softTotal;
}

/// <summary>
/// Gets the hand's hard total.
/// </summary>
/// <returns>Hand's hard total.</returns>
unsigned Hand::getHardTotal() const
{
	return hardTotal;
}

/// <summary>
/// Gets the hand's final total.
/// </summary>
/// <returns>Hand's final total.</returns>
unsigned Hand::getFinalTotal() const
{
	if (softTotal <= 21 && softTotal > hardTotal)
	{
		return softTotal;
	}
	else if (hardTotal <= 21 && hardTotal > softTotal)
	{
		return hardTotal;
	}

	return hardTotal;
}

/// <summary>
/// Add a new card to hand.
/// </summary>
/// <param name="card">Card added.</param>
void Hand::addCard(Card card)
{
	cards.push_back(card);

	unsigned cardValue = card.getValue();
	if (cardValue == 11) /* Ace */
	{
		hardTotal += 1;
		softTotal += 11;
		holdAces = true;
	}
	else
	{
		hardTotal += cardValue;
		softTotal += cardValue;
	}
}

/// <summary>
/// Reports whether the hand has an ace or not.
/// </summary>
/// <returns>True if hand has ace. False if not.</returns>
bool Hand::hasAce() const
{
	return holdAces;
}

/// <summary>
/// Reports whether the hand has busted or not.
/// </summary>
/// <returns>True if busted. False if not.</returns>
bool Hand::hasHandBusted() const
{
	if ((holdAces && softTotal > 21 && hardTotal > 21) ||
		(!holdAces && hardTotal > 21))
	{
		return true;
	}

	return false;
}

/// <summary>
/// Prints soft and hard totals.
/// </summary>
/// <param name="person">Person playing.</param>
void Hand::printTotals(const std::string person) const
{
	if (hasAce())
	{
		std::cout << person << " has a hard total of " << getHardTotal() <<
			" and a soft total of " << getSoftTotal() << std::endl;
	}
	else
	{
		std::cout << person << " has a hard total of " << getHardTotal() << std::endl;
	}
}
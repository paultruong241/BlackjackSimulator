/********************************************************
 * @file Hand.h
 *
 * @brief This file displays the Hand class.
 *
 * @author Paul Truong
 * @date 08-08-2022
 *
 *******************************************************/
#pragma once

#include <vector>
#include "Card.h"

class Hand
{
public:
	enum class Type {
		Soft, Hard
	};

	Hand();

	std::vector<Card> getCards() const;
	unsigned getSoftTotal() const;
	unsigned getHardTotal() const;
	unsigned getFinalTotal() const;

	void addCard(Card card);
	bool hasAce() const;
	bool hasHandBusted() const;
	void printTotals(const std::string person) const;

private:
	std::vector<Card> cards{};
	unsigned softTotal = 0;
	unsigned hardTotal = 0;
	unsigned finalTotal = 0;

	bool holdAces = false;
	bool isBusted = false;
};


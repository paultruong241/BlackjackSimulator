/********************************************************
 * @file Card.h
 *
 * @brief This file displays the Card class.
 *
 * @author Paul Truong
 * @date 08-08-2022
 *
 *******************************************************/
#pragma once

#include <string>

class Card
{
public:
	enum Value {
		Two = 2, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace
	};

	enum Suit {
		Clover, Diamond, Heart, Spade
	};

	Card(const Value valueEnum, const Suit suitEnum);

	void setValue(const Value valueEnum);
	unsigned getValue() const;
	void setSuit(const Suit suitEnum);
	std::string getSuit() const;

private:
	unsigned value;
	std::string suit;
};


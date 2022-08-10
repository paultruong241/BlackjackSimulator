/********************************************************
 * @file Card.cpp
 *
 * @brief This file displays the Card class.
 *
 * @author Paul Truong
 * @date 08-08-2022
 *
 *******************************************************/
#include "Card.h"

 /// <summary>
 /// Constructor.
 /// </summary>
 /// <param name="value">Card's value.</param>
 /// <param name="suit">Card's suit.</param>
Card::Card(const Value value, const Suit suit)
{
	setValue(value);
	setSuit(suit);
}

/// <summary>
/// Sets value based on value enumeration.
/// </summary>
/// <param name="valueEnum">Value enumeration.</param>
void Card::setValue(const Value valueEnum)
{
	switch (valueEnum)
	{
	case Card::Value::Jack:
	case Card::Value::Queen:
	case Card::Value::King:
		value = 10;
		break;
	case Card::Value::Ace:
		value = 11;
		break;
	default:
		value = valueEnum;
		break;
	}
}

/// <summary>
/// Gets the card's value.
/// </summary>
/// <returns>Card's value.</returns>
unsigned Card::getValue() const
{
	return value;
}

/// <summary>
/// Sets suit based on suit enumeration. 
/// </summary>
/// <param name="suitEnum">Suit enumeration.</param>
void Card::setSuit(const Suit suitEnum)
{
	switch (suitEnum)
	{
	case Card::Suit::Clover:
		suit = "Clover";
		break;
	case Card::Suit::Diamond:
		suit = "Diamond";
		break;
	case Card::Suit::Heart:
		suit = "Heart";
		break;
	case Card::Suit::Spade:
		suit = "Spade";
		break;
	default:
		break;
	}
}

/// <summary>
/// Gets the card's suit.
/// </summary>
/// <returns>Card's suit.</returns>
std::string Card::getSuit() const
{
	return suit;
}
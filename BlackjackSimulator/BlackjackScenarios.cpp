/********************************************************
 * @file BlackjackScenarios.cpp
 *
 * @brief This file displays the Blackjack class.
 *
 * @author Paul Truong
 * @date 08-08-2022
 *
 *******************************************************/
#include "BlackjackScenarios.h"
#include <iostream>

 /// <summary>
 /// Constructor.
 /// </summary>
 /// <param name="numOfDecks">Number of decks.</param>
 /// <param name="resetPercent">Percent of deck used before resetting deck.</param>
 /// <param name="numOfGames">Number of games.</param>
BlackjackScenarios::BlackjackScenarios(unsigned numOfDecks, unsigned resetPercent, unsigned numOfGames) :
	numOfDecks(numOfDecks), resetPercent(resetPercent), numOfGames(numOfGames)
{
	Blackjacks();
}

/// <summary>
/// Gets the number of wins.
/// </summary>
/// <param name="numOfWins">Number of wins.</param>
unsigned BlackjackScenarios::GetWins() const
{
	return numOfWins;
}

/// <summary>
/// Gets the number of big wins.
/// </summary>
/// <param name="numOfBigWins">Number of big wins.</param>
unsigned BlackjackScenarios::GetBigWins() const
{
	return numOfBigWins;
}

/// <summary>
/// Gets the number of losses.
/// </summary>
/// <param name="numOfLosses">Number of losses.</param>
unsigned BlackjackScenarios::GetLosses() const
{
	return numOfLosses;
}

/// <summary>
/// Gets the number of pushes.
/// </summary>
/// <param name="numOfPushes">Number of pushes.</param>
unsigned BlackjackScenarios::GetPushes() const
{
	return numOfPushes;
}

/// <summary>
/// Gets the number of surrenders.
/// </summary>
/// <param name="numOfSurrenders">Number of surrenders.</param>
unsigned BlackjackScenarios::GetSurrenders() const
{
	return numOfSurrenders;
}

/// <summary>
/// Execute all blackjack games.
/// </summary>
void BlackjackScenarios::Blackjacks()
{
	Deck deck(numOfDecks);
	unsigned currentGameCount = 0;

	while (currentGameCount++ != numOfGames)
	{
		Results result = Blackjack(deck);
		CountResults(result);

		unsigned deckUsage = deck.CheckDeckUsage();
		if (deckUsage >= resetPercent && deckUsage >= 90)
		{
			deck.SetDeck(numOfDecks);
			std::cout << "Resetting the deck." << std::endl;
		}

		std::cout << "========================" << std::endl;
	}
}

/// <summary>
/// Execute a blackjack game.
/// </summary>
/// <param name="deck">Deck.</param>
/// <returns>Result of the blackjack game.</returns>
BlackjackScenarios::Results BlackjackScenarios::Blackjack(Deck& deck)
{
	Hand playerHand, dealerHand;
	Strategies playerStrategy(false, false, true);

	Dealing(deck, playerHand, dealerHand);

	PlayerExecutes(deck, playerStrategy, playerHand, dealerHand);
	if (playerStrategy.GetAction() == Strategies::Actions::Surrender)
	{
		std::cout << "Player has surrendered! Dealer Wins!" << std::endl;
		return Results::Surrender;
	}
	else if (playerHand.hasHandBusted())
	{
		std::cout << "Player has busted! Dealer Wins!" << std::endl;
		return Results::Lose;
	}

	DealerExecutes(deck, dealerHand);
	if (dealerHand.hasHandBusted())
	{
		std::cout << "Dealer has busted! Player Wins!" << std::endl;
		return Results::Win;
	}

	return Showdown(playerStrategy, playerHand, dealerHand);
}

/// <summary>
/// Drawing a card from the deck.
/// </summary>
/// <param name="deck">Deck.</param>
/// <param name="person">Person playing.</param>
/// <param name="hand">Person's hand.</param>
void BlackjackScenarios::Drawing(Deck& deck, std::string person, Hand& hand)
{
	if (deck.CheckDeckSize() > 10)
	{
		Card cardDrawn = deck.Draw();
		hand.addCard(cardDrawn);
		std::cout << person << " drew a " << cardDrawn.getValue() << " " << cardDrawn.getSuit() << std::endl;
	}
	else
	{
		deck.SetDeck(numOfDecks);
		std::cout << "Resetting the deck." << std::endl;
	}
}

/// <summary>
/// Drawing sequence of blackjack game.
/// </summary>
/// <param name="deck">Deck.</param>
/// <param name="playerHand">Player's hand.</param>
/// <param name="dealerHand">Dealer's hand.</param>
void BlackjackScenarios::Dealing(Deck& deck, Hand& playerHand, Hand& dealerHand)
{
	Drawing(deck, "Player", playerHand);
	Drawing(deck, "Dealer", dealerHand);
	Drawing(deck, "Player", playerHand);

	playerHand.printTotals("Player");
	dealerHand.printTotals("Dealer");
}

/// <summary>
/// Player executes his/her strategies for his/her hand.
/// </summary>
/// <param name="deck">Deck.</param>
/// <param name="playerStrategy">Player's Strategies.</param>
/// <param name="playerHand">Player's hand.</param>
/// <param name="dealerHand">Dealer's hand.</param>
void BlackjackScenarios::PlayerExecutes(Deck& deck, Strategies& playerStrategy, Hand& playerHand, Hand& dealerHand)
{
	Strategies::Actions playerAction = playerStrategy.GetAction();

	do
	{
		playerStrategy.ExecuteStrategies(playerHand, dealerHand);
		playerAction = playerStrategy.GetAction();

		switch (playerAction)
		{
		case Strategies::Actions::Surrender:
			return;
			break;
		case Strategies::Actions::Split:
			/* TODO: Add split logic */
			break;
		case Strategies::Actions::DoubleDown:
			Drawing(deck, "Player", playerHand);
			playerHand.printTotals("Player");
			return;
			break;
		case Strategies::Actions::Hit:
			Drawing(deck, "Player", playerHand);
			playerHand.printTotals("Player");
			break;
		}
	} while (playerAction != Strategies::Actions::Stand);
}

/// <summary>
/// Dealer executes his/her strategies for his/her hand.
/// </summary>
/// <param name="deck">Deck.</param>
/// <param name="dealerHand">Dealer's hand.</param>
void BlackjackScenarios::DealerExecutes(Deck& deck, Hand& dealerHand)
{
	while (dealerHand.getSoftTotal() < 17)
	{
		Drawing(deck, "Dealer", dealerHand);
		dealerHand.printTotals("Dealer");
	}
}

/// <summary>
/// Compares the player's and dealer's hands.
/// </summary>
/// <param name="playerStrategy">Player's Strategies.</param>
/// <param name="playerHand">Player's hand.</param>
/// <param name="dealerHand">Dealer's hand.</param>
/// <returns>Result of the comparison.</returns>
BlackjackScenarios::Results BlackjackScenarios::Showdown(
	Strategies& playerStrategy, Hand& playerHand, Hand& dealerHand)
{
	unsigned playerTotal{ playerHand.getFinalTotal() }, dealerTotal{ dealerHand.getFinalTotal() };

	if (playerTotal == dealerTotal)
	{
		std::cout << "Player Pushes!" << std::endl;
		return Results::Push;
	}
	else if (playerTotal < dealerTotal)
	{
		std::cout << "Dealer Wins!" << std::endl;
		return Results::Lose;
	}
	else
	{
		std::cout << "Player Wins!" << std::endl;
		return playerStrategy.GetAction() == Strategies::Actions::DoubleDown ? Results::BigWin : Results::Win;
	}
}

/// <summary>
/// Add blackjack result to corresponding total.
/// </summary>
/// <param name="result">Result of blackjack game.</param>
void BlackjackScenarios::CountResults(BlackjackScenarios::Results result)
{
	switch (result)
	{
	case Results::Win:
		numOfWins++;
		break;
	case Results::BigWin:
		numOfBigWins++;
		break;
	case Results::Lose:
		numOfLosses++;
		break;
	case Results::Push:
		numOfPushes++;
		break;
	case Results::Surrender:
		numOfSurrenders++;
		break;
	default:
		break;
	}
}
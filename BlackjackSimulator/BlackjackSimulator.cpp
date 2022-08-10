/********************************************************
 * @file BlackjackSimulator.cpp
 *
 * @brief This file stimulates Blackjack.
 *
 * @author Paul Truong
 * @date 08-08-2022
 *
 * @purpose The purpose of this project was to develop a
 *          blackjack simulator that allowed me to apply
 *          different strategies. They increased my win-
 *          rate to approximate 45%.
 *
 *
 *******************************************************/
#include "BlackjackScenarios.h"
#include <iostream>

 /// <summary>
 /// Set the number of decks.
 /// </summary>
 /// <returns>Number of decks.</returns>
unsigned setNumOfDecks()
{
	unsigned numOfDecks = 0;
	bool validNumOfDecks = false;

	std::cout << "How many decks would you like to play with? 1? 2? 6? ";

	while (!validNumOfDecks)
	{
		std::cin >> numOfDecks;

		if (numOfDecks == 1 || numOfDecks == 2 || numOfDecks == 6)
		{
			validNumOfDecks = true;
		}
		else
		{
			std::cout << "Please make a valid selection. 1? 2? 6? ";
		}
	}

	return numOfDecks;
}

/// <summary>
/// Set the percentage of cards used before resetting deck.
/// </summary>
/// <returns>Percentage of cards used before resetting deck.</returns>
unsigned setResetPercent()
{
	unsigned resetPercent = 0;
	bool validResetPercent = false;

	std::cout << "What percent of deck do you want used before resetting? 1-90? ";

	while (!validResetPercent)
	{
		std::cin >> resetPercent;

		if (resetPercent >= 1 && resetPercent <= 90)
		{
			validResetPercent = true;
		}
		else
		{
			std::cout << "Please make a valid selection. 1-90? ";
		}
	}

	return resetPercent;
}

/// <summary>
/// Set the number of blackjack games.
/// </summary>
/// <returns>Number of blackjack games.</returns>
unsigned setNumOfGames()
{
	unsigned numOfGames = 0;
	bool validNumOfGames = false;

	std::cout << "How many games do you want to play? 0-10000? ";

	while (!validNumOfGames)
	{
		std::cin >> numOfGames;

		if (numOfGames >= 1 && numOfGames <= 10000)
		{
			validNumOfGames = true;
		}
		else
		{
			std::cout << "Please make a valid selection. 1-10000? ";
		}
	}

	return numOfGames;
}

/// <summary>
/// Main function.
/// </summary>
/// <returns>Success.</returns>
int main()
{
	constexpr auto blackjackTitle = R"(
    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    @@@                                                                                           @@@
    @@@   /@@@@@@@ /@@       /@@@@@@   /@@@@@@ /@@   /@@    /@@@@@  /@@@@@@   /@@@@@@ /@@   /@@   @@@
    @@@  | @@__  @| @@      /@@__  @@ /@@__  @| @@  /@@/   |__  @@ /@@__  @@ /@@__  @| @@  /@@/   @@@
    @@@  | @@  \ @| @@     | @@  \ @@| @@  \__| @@ /@@/       | @@| @@  \ @@| @@  \__| @@ /@@/    @@@
    @@@  | @@@@@@@| @@     | @@@@@@@@| @@     | @@@@@/        | @@| @@@@@@@@| @@     | @@@@@/     @@@
    @@@  | @@__  @| @@     | @@__  @@| @@     | @@  @@   /@@  | @@| @@__  @@| @@     | @@  @@     @@@
    @@@  | @@  \ @| @@     | @@  | @@| @@    @| @@\  @@ | @@  | @@| @@  | @@| @@    @| @@\  @@    @@@
    @@@  | @@@@@@@| @@@@@@@| @@  | @@|  @@@@@@| @@ \  @@|  @@@@@@/| @@  | @@|  @@@@@@| @@ \  @@   @@@
    @@@  |_______/|________|__/  |__/ \______/|__/  \__/ \______/ |__/  |__/\______/ |__/  \__/   @@@
    @@@                                                                                           @@@
    @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    )";

	std::cout << blackjackTitle << std::endl;

	unsigned numOfDecks{ setNumOfDecks() }, resetPercent{ setResetPercent() }, numOfGames{ setNumOfGames() };
	BlackjackScenarios bj(numOfDecks, resetPercent, numOfGames);

	std::cout << "Wins " << bj.GetWins() << " Big Wins " << bj.GetBigWins() << " Losses " << bj.GetLosses()
		<< " Pushes " << bj.GetPushes() << " Surrenders " << bj.GetSurrenders() << std::endl;

	return 0;
}
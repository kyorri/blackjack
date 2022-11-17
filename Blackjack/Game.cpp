#include <iostream>
#include <Windows.h>
#include "Card.h"
#include "Deck.h"
#include "Player.h"
#include "Game.h"

using namespace std;

Game::Game(int numberOfPlayers, int numberOfDecks)
{
	this->gameEnd = false;

	this->numberOfPlayers = numberOfPlayers;
	this->numberOfDecks = numberOfDecks;

	this->players = new Player[this->numberOfPlayers];
	this->decks = new Deck[this->numberOfDecks];
	srand(time(NULL));
}

void Game::GetPlayerNames()
{
	string name;
	for (int i = 0; i < this->numberOfPlayers; i++)
	{
		cout << "Please input the name of the ";
		switch (i)
		{
		case 0:
			cout << "first ";
			break;
		case 1:
			cout << "second ";
			break;
		case 2:
			cout << "third ";
			break;
		}
		cout << "player: ";
		cin >> name;
		this->players[i].SetName(name);
	}
}

void Game::GetRandomCard(Player& player)
{
	int numberOfCardsDeck = decks[0].GetNumberOfCards();
	int totalNumberOfCards = numberOfCardsDeck * numberOfDecks;
	Card* cardFound = new Card;
	int indexOfElementChosen;
	int deckNumber;
	int indexInDeck;
	Deck deckFound;
	do {
		indexOfElementChosen = rand() % totalNumberOfCards;
		deckNumber = floor(indexOfElementChosen / numberOfCardsDeck);
		indexInDeck = indexOfElementChosen - numberOfCardsDeck * deckNumber;
		decks[deckNumber].GetCard(indexInDeck).SetStatus(true);
		cardFound->CopyCard(decks[deckNumber].GetCard(indexInDeck));
	} while ((*cardFound).GetStatus());
	decks[deckNumber].GetCard(indexInDeck).SetStatus(true);
	cardFound->SetStatus(true);
	player.AddCard(*cardFound);
}

bool Game::CheckStand()
{
	for (int i = 0; i < numberOfPlayers; i++)
	{
		if (!players[i].GetPlayerStatus())
		{
			return false;
		}
	}
	return true;
}

bool Game::CheckWinner()
{
	int tempScore;
	int numberWinners = 0;
	int maxScore = -1;
	int k = 0;
	if (CheckStand())
	{
		for (int i = 0; i < numberOfPlayers; i++)
		{
			tempScore = players[i].GetScore();
			if (tempScore <= 21 && tempScore > maxScore)
			{
				maxScore = tempScore;
			}
		}
		for (int i = 0; i < numberOfPlayers; i++)
		{
			tempScore = players[i].GetScore();
			if (tempScore == maxScore)
			{
				numberWinners++;
			}
		}
		switch (numberWinners)
		{
			case 0:
				cout << "Nobody won!" << endl;
				return true;
				break;
			case 1:
				for (int i = 0; i < numberOfPlayers; i++)
				{
					tempScore = players[i].GetScore();
					if (tempScore == maxScore)
					{
						cout << players[i].GetName() << " has won with a score of " << maxScore << "!" << endl;
						return true;
					}
				}
				break;
			case 2:
				for (int i = 0; i < numberOfPlayers; i++)
				{
					tempScore = players[i].GetScore();
					if (tempScore == maxScore)
					{
						cout << players[i].GetName() << ", ";
					}
				}
				cout << "have won with a score of " << maxScore << "!" << endl;
				return true;
				break;
			case 3:
				cout << "Everybody won!" << endl;
				return true;
				break;
		}
	}
	return false;
}

void Game::NextTurn(int& turn)
{
	int maxTurn = numberOfPlayers;
	turn++;
	if (turn % maxTurn == 0)
	{
		turn = turn % maxTurn;
		Sleep(1000);
		system("cls");
	}
}

void Game::GameLoop()
{
	int turn = 0;
	char choice;

	GetPlayerNames();
	do
	{
		players[turn].PrintPlayer();

		if (!players[turn].GetPlayerStatus())
		{
			choice = GetPlayerChoice(players[turn]);
		}

		// DUCT TAPE FIX
		// DO NOT REMOVE :))
		else 
		{
			// RESET THE LAST CHOICE
			choice = ' ';
		}

		if (choice == 'y')
		{
			GetRandomCard(players[turn]);

			cout << players[turn].GetName() << " got a/an ";
			players[turn].GetCard(players[turn].GetNumberCardsDrawn() - 1).PrintCard();
			players[turn].UpdateScore();
			cout << "New score of " << players[turn].GetName() << ": " << players[turn].GetScore() << endl;

			if (players[turn].GetScore() >= 21)
			{
				players[turn].SetPlayerStatus(true);
			}
		}
		else if (choice == 'n')
		{
			players[turn].SetPlayerStatus(true);
		}

		
		if (CheckWinner())
		{
			gameEnd = true;
		}
		else
		{
			NextTurn(turn);
		}
	} while (!gameEnd);
}

void Game::PrintPlayers()
{
	for (int i = 0; i < this->numberOfPlayers; i++)
	{
		this->players[i].PrintPlayer();
	}
}

char Game::GetPlayerChoice(Player player)
{
	char choice;
	cout << "Do you want to take a hit " << player.GetName() << "? [(y)es/(n)o]: ";
	cin >> choice;
	return choice;
}
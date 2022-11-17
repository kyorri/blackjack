#pragma once

#include "Card.h"
#include "Deck.h"
#include "Player.h"

using namespace std;

class Game {
private:
	bool gameEnd;
	int numberOfPlayers;
	Player* players;
	int numberOfDecks;
	Deck* decks;
public:
	Game(int numberOfPlayers, int numberOfDecks);
	void GameLoop();

	void PrintPlayers();

	void GetPlayerNames();
	char GetPlayerChoice(Player player);
	void GetRandomCard(Player& player);

	bool CheckStand();
	bool CheckWinner();
	void NextTurn(int& turn);

	Deck* GetDecks() { return (this->decks); }
	Player* GetPlayers() { return (this->players); }
};
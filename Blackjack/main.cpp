#include <Windows.h>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Card.h"
#include "Deck.h"
#include "Player.h"
#include "Game.h"

int main()
{
	int numPlayers;
	int numDecks;
	cout << "Welcome to Blackjack" << endl;
	cout << "Please enter the number of players, then the number of decks to play with!" << endl;
	cin >> numPlayers >> numDecks;
	Game game(numPlayers, numDecks);
	game.GameLoop();
	system("pause");
	return 0;
}
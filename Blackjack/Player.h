#pragma once

#include "Card.h"

using namespace std;

class Player {
private:
	string name;
	int score;
	int numberOfCardsDrawn;
	bool status;
	int maxNumberOfCards;
	Card* cards;
public:
	Player();
	Player(string name);

	void AddCard(Card card);
	Card GetCard(int index)
	{
		return cards[index];
	}
	void PrintPlayer();

	void UpdateScore();

	int GetNumberCardsDrawn(){ return (this->numberOfCardsDrawn); }

	void SetScore(int score) { this->score = score; }
	int GetScore() {
		UpdateScore();
		return (this->score); }

	void SetName(string name) { this->name = name; }
	string GetName() { return (this->name); }

	void SetPlayerStatus(bool status) { this->status = status; };
	bool GetPlayerStatus() { return (this->status); }
};
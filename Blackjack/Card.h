#pragma once

#include <iostream>
#include <string>

using namespace std;

class Card
{
public:
	Card()
	{
		suit = "";
		value = "";
		status = false;
		score = 0;
		UpdateScore();
	}
	Card(string suit, string value)
	{
		this->suit = suit;
		this->value = value;
		status = false;
		UpdateScore();
	}
	~Card() {/* delete this; */ }

	void UpdateScore();

	void PrintCard();
	void CopyCard(Card newCard);

	void SetValue(string value) { this->value = value; }
	string GetValue() { return (this->value); }

	void SetSuit(string suit){ this->suit = suit; }
	string GetSuit() { return (this->suit); }

	void SetStatus(bool status) { this->status = status; }
	bool GetStatus() { return (this->status); }

	void SetScore(int score) { this->score = score; }
	int GetScore()
	{ 
		UpdateScore();
		return (this->score); 
	}

private:
	string suit;
	string value;
	bool status;
	int score;
};


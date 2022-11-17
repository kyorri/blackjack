#pragma once

#include <iostream>
#include "Card.h"

using namespace std;

class Deck {
private:
	int numberOfCards;
	int maxNumberOfCards;
	Card* cards;
public:
	Deck()
	{
		numberOfCards = 0;
		maxNumberOfCards = 52;
		cards = new Card[maxNumberOfCards]();
		GenerateCards();
	}
	~Deck() { delete[] cards; }

	void GenerateCards();

	void SetNumberOfCards(int newNumber) { this->numberOfCards = newNumber; }
	int GetNumberOfCards() { return (this->numberOfCards); }

	void SetMaxNumberOfCards(int newNumber) { this->maxNumberOfCards = newNumber; }
	int GetMaxNumberOfCards() { return (this->maxNumberOfCards); }

	void SetCard(Card card, int index) { cards[index].CopyCard(card); }
	Card GetCard(int index) {
		Card temp;
		temp.CopyCard(cards[index]);
		return temp;
	}

	void PrintCards()
	{
		for (int i = 0; i < this->numberOfCards; i++)
		{
			cards[i].PrintCard();
		}
	}
};
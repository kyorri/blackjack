#include "Card.h"

void Card::CopyCard(Card newCard)
{
	SetSuit(newCard.GetSuit());
	SetValue(newCard.GetValue());
	SetScore(newCard.GetScore());
	SetStatus(newCard.GetStatus());
}

void Card::PrintCard()
{
	cout << GetValue() << " of " << GetSuit() << "." << " (" << GetStatus() << ", " << GetScore() << ")" << std::endl;
}

void Card::UpdateScore()
{
	if (value == "")
	{
		score = 0;
	}
	else if (value == "J" || value == "Q" || value == "K")
	{
		score = 10;
	}
	else if (value == "A")
	{
		score = 11;
	}
	else
	{
		score = stoi(value);
	}
}

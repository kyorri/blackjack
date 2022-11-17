#include "Card.h"
#include "Deck.h"

void Deck::GenerateCards()
{
	int suite;
	int value;
	for (int i = 0; i < maxNumberOfCards; i++)
	{
		suite = i % 4;
		value = i / 4;
		switch (suite)
		{
		case 0:
			cards[i].SetSuit("hearts");
			break;
		case 1:
			cards[i].SetSuit("spades");
			break;
		case 2:
			cards[i].SetSuit("diamonds");
			break;
		case 3:
			cards[i].SetSuit("clubs");
			break;
		}
		switch (value)
		{
		case 0:
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
			cards[i].SetValue(string(to_string(value + 2)));
			break;
		case 9:
			cards[i].SetValue("A");
			break;
		case 10:
			cards[i].SetValue("J");
			break;
		case 11:
			cards[i].SetValue("Q");
			break;
		case 12:
			cards[i].SetValue("K");
			break;
		}
		cards[i].SetStatus(false);
		cards[i].UpdateScore();
		numberOfCards++;
	}
}
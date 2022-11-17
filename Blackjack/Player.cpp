#include "Player.h"

Player::Player() 
{
	this->numberOfCardsDrawn = 0;
	this->score = 0;
	this->name = "";
	this->status = false;
	this->maxNumberOfCards = 10;
	this->cards = new Card[maxNumberOfCards];
}

Player::Player(string name)
{
	this->numberOfCardsDrawn = 0;
	this->score = 0;
	this->name = name;
	this->status = false;
	this->maxNumberOfCards = 10;
	this->cards = new Card[maxNumberOfCards];
}

void Player::AddCard(Card newCard)
{
	cards[numberOfCardsDrawn].CopyCard(newCard);
	cards[numberOfCardsDrawn].SetStatus(true);
	numberOfCardsDrawn++;
}

void Player::UpdateScore()
{
	score = 0;
	for (int i = 0; i < numberOfCardsDrawn; i++)
	{
		if (cards[i].GetValue() != "A")
		{
			score = score + cards[i].GetScore();
		}
	}
	for (int i = 0; i < numberOfCardsDrawn; i++)
	{
		if (cards[i].GetValue() == "A")
		{
			if (score + cards[i].GetScore() <= 21)
			{
				score += cards[i].GetScore();
			}
			else {
				score += 1;
			}
		}
	}
}

void Player::PrintPlayer()
{
	cout << name << "'s score: " << this->GetScore() << endl;
	if (numberOfCardsDrawn > 0)
	{
		if (numberOfCardsDrawn == 1)
		{
			cout << this->name << " has drawn a single card: " << endl;
		}
		else
		{
			cout << this->name << " has " << this->numberOfCardsDrawn << " cards: " << endl;
		}
		for (int i = 0; i < numberOfCardsDrawn; i++)
		{
			cout << " - " << this->cards[i].GetValue() << " of " << this->cards[i].GetSuit() << "; (" << this->cards[i].GetStatus() << ")" << endl;
		}
	}
	else if (numberOfCardsDrawn == 0)
	{
		cout << this->name << " does not have any cards drawn!" << endl;
	}
}
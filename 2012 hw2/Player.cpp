/*
 * Player.cpp
 *
 *  Created on: Jan 29, 2018
 *      Author: kevinw
 */

#include "Player.h"
#include<typeinfo>


ostream& operator<<(ostream& os, const Player& h) {
	os << h.name << ":";
	for (int i = 0; i < h.getSize(); i++) {
		os << *h.getCard(i) << " ";
	}
	return os;
}

Player::Player(string name, Player* previous):name(name){
	if(previous==nullptr){this->nextPlayer=this;}
	else
	{
		this->nextPlayer=previous->nextPlayer;
		previous->nextPlayer=this;
	}
}

void Player::drawCard(CardPile& drawPile, CardPile& discardPile, int number_of_cards)
{

//	bool finalplay=false;
//	if(this->getSize()==1){finalplay=true;}

	if(drawPile.getSize()<=0&&discardPile.getSize()>1)//add card to draw if drawsize=0
	{


			Card* temp=discardPile.removeTopCard();
			while(discardPile.getSize()!=0){drawPile+=discardPile.removeTopCard();}
			drawPile.shuffle();
			discardPile+=temp;

	}

	int count=drawPile.getSize()-number_of_cards;

	if(count>=0)//drawpile has enough
	{
		for(int i=1;i<=number_of_cards;i++)
		{
			Card* temp=drawPile.removeTopCard();
			*this+=temp;
		}

	}

else if(count<0)//not enough
	{

		while(drawPile.getSize()!=0)
		{
			*this+=drawPile.removeTopCard();
		}
		drawPile.shuffle();

		Card* temp=discardPile.removeTopCard();

		while(discardPile.getSize()!=0)
			{drawPile+=discardPile.removeTopCard();}

		drawPile.shuffle();
		discardPile+=temp;

		count*=-1;
		while(drawPile.getSize()!=0&&count>0)
		{
			*this+=drawPile.removeTopCard();
			count--;
		}




	 }
}

Card* Player::playCardAfter(const Card* topCard, int index)
{
	if(index>(this->getSize()-1)||index<0)
		{
			return nullptr;
		}
	if((*this->getCard(index)^(*topCard))==false)
	{
		return nullptr;
	}

if(typeid(*this->getCard(index))!=typeid(NumberCard)&&this->getSize()==1){return nullptr;}



Card* currentcard=this->removeCard(index);



	return currentcard;

}

int Player::getScore() const
{//count score, possible bug :is getscore only for winner or for all player??
	int score=0;
	for(int i=0;i<=this->getSize()-1;i++)
	{score+=this->getCard(i)->getPoint();}
	return score;

}



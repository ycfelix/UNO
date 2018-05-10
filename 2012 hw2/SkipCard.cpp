/*
 * SkipCard.cpp
 *
 *  Created on: Feb 2, 2018
 *      Author: kevinw
 */

#include "SkipCard.h"
#include "Player.h"

SkipCard::SkipCard(Color color):Card(color,POINT_SKIPCARD){}
void SkipCard::castEffect(Player*& currentPlayer, CardPile& drawPile, CardPile& discardPile)
{

	Player* now=currentPlayer;
	now=now->getNextPlayer();
	currentPlayer=now;
}
bool SkipCard::operator^(const Card& t) const//RTTI,not getpoint()
{
	if (this->Card::operator ^(t)==true)
		{return true;}
	if (typeid(t) == typeid(SkipCard))
				{return true;}
	return false;
}
void SkipCard::serialize(ostream& os) const{char symbol='\0';
switch(this->color)
{
case Color::blue:symbol='B';break;
case Color::green:symbol='G';break;
case Color::red:symbol='R';break;
case Color::yellow:symbol='Y';break;
default:break;
}
os<<symbol<<'s';}

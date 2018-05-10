/*
 * DrawTwoCard.cpp
 *
 *  Created on: Feb 5, 2018
 *      Author: kevinw
 */

#include "DrawTwoCard.h"
#include "Player.h"
DrawTwoCard::DrawTwoCard(Color color):SkipCard(color){}

bool DrawTwoCard::operator^(const Card& t) const
{
	if (this->Card::operator ^(t)==true)
				{return true;}
	if (typeid(t) == typeid(DrawTwoCard))
				{return true;}
	return false;
}


void DrawTwoCard::castEffect(Player*& currentPlayer, CardPile& drawPile, CardPile& discardPile)
{
	currentPlayer->getNextPlayer()->drawCard(drawPile,discardPile,2);
	SkipCard::castEffect(currentPlayer,drawPile,discardPile);
}

void DrawTwoCard::serialize(ostream& os) const
{
	char symbol='\0';
		switch(this->color)
		{
		case Color::blue:symbol='B';break;
		case Color::green:symbol='G';break;
		case Color::red:symbol='R';break;
		case Color::yellow:symbol='Y';break;
		default:break;
		}
	os<<symbol<<"+";
}

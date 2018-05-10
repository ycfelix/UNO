/*
 * NumberCard.cpp
 *
 *  Created on: Jan 29, 2018
 *      Author: kevinw
 */

#include "NumberCard.h"

NumberCard::NumberCard(int point, Color color):Card(color,point){}
void NumberCard::serialize(ostream& os) const
{char symbol='\0';
	switch(this->color)
	{
	case Color::blue:symbol='B';break;
	case Color::green:symbol='G';break;
	case Color::red:symbol='R';break;
	case Color::yellow:symbol='Y';break;
	default:break;
	}
os<<symbol<<this->getPoint();
}

bool NumberCard::operator^(const Card& t) const
{
	if (this->Card::operator ^(t)==true)//possible syntax error
			{return true;}

	if (t.getPoint() == this->getPoint())
			{return true;}
		return false;
}

void NumberCard::castEffect(Player*& currentPlayer, CardPile& drawPile, CardPile& discardPile)
{
return;
}

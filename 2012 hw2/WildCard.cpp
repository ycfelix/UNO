/*
 * WildCard.cpp
 *
 *  Created on: Feb 6, 2018
 *      Author: kevinw
 */

#include "WildCard.h"
#include "Player.h"




WildCard::WildCard():Card(Color::meta,POINT_WILDCARD){}
bool WildCard::operator^(const Card& t) const
{
	return true;
}


void WildCard::castEffect(Player*& currentPlayer, CardPile& drawPile, CardPile& discardPile)
{	this->color=currentPlayer->chooseColor();
	return;
}

void WildCard::serialize(ostream& os) const//bug here
{
	if(this->color!=Color::meta)
	{	char symbol='\0';
		switch(this->color)
				{
				case Color::blue:symbol='B';break;
				case Color::green:symbol='G';break;
				case Color::red:symbol='R';break;
				case Color::yellow:symbol='Y';break;
				default:break;
				}
		os<<symbol<<"w";
	}
	else
	{

	os<<"WC";
	}


}

void WildCard::init() {this->color=Color::meta;}

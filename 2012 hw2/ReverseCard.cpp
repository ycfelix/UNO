/*
 * ReverseCard.cpp
 *
 *  Created on: Feb 2, 2018
 *      Author: kevinw
 */

#include "ReverseCard.h"
#include "Player.h"

ReverseCard::ReverseCard(Color color):Card(color,POINT_REVERSECARD){}

bool ReverseCard::operator^(const Card& t) const
{

	if (this->Card::operator ^(t)==true)//possible syntax error
			{return true;}

	if (typeid(t) == typeid(ReverseCard))
		{return true;}
		return false;

}


void ReverseCard::castEffect(Player*& currentPlayer, CardPile& drawPile, CardPile& discardPile)
{
int counter=0;
Player* temp=currentPlayer;
while(temp->nextPlayer!=currentPlayer)
{	temp=temp->nextPlayer;

		counter++;}

Player** array=new Player*[counter];


temp=currentPlayer;

int i=0;


while(temp->nextPlayer!=currentPlayer)
{
	temp=temp->nextPlayer;
	array[i]=temp;
	i++;
}



temp=currentPlayer;
	for(int j=i;j>=0;j--)
	{

	if(j==0){temp->nextPlayer=currentPlayer;break;}
	temp->nextPlayer=array[j-1];
	temp=temp->nextPlayer;

	}


delete []array;





}
 void ReverseCard::serialize(ostream& os) const
 {char symbol='\0';
	switch(this->color)
	{
	case Color::blue:symbol='B';break;
	case Color::green:symbol='G';break;
	case Color::red:symbol='R';break;
	case Color::yellow:symbol='Y';break;
	default:break;
	}
os<<symbol<<'r';
}



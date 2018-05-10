#include "DrawFourCard.h"
#include "Player.h"
#include<typeinfo>

DrawFourCard::DrawFourCard():WildCard(){}

bool DrawFourCard::operator^(const Card& t) const{return true;}
void DrawFourCard::init() {
	this->color=Color::meta;
}

void DrawFourCard::castEffect(Player*& currentPlayer, CardPile& drawPile, CardPile& discardPile)
{

	this->color=currentPlayer->chooseColor();
	if(currentPlayer->nextPlayer->appealDrawFour()==true)
	{
		bool flag=false;
		for(int i=0;i<currentPlayer->getSize();i++)
		{
			if((*currentPlayer->getCard(i)^*discardPile.getTopCard())&&
					typeid(*currentPlayer->getCard(i))!=typeid(DrawFourCard))
			{	flag=true;
				currentPlayer->drawCard(drawPile,discardPile,4);
				break;
			}
		}
		if(flag==false)
		{
			currentPlayer->getNextPlayer()->drawCard(drawPile,discardPile,6);
			currentPlayer=currentPlayer->nextPlayer;
		}

	}
	else
	{
	currentPlayer->getNextPlayer()->drawCard(drawPile,discardPile,4);
	currentPlayer=currentPlayer->nextPlayer;
	}
}

void DrawFourCard::serialize(ostream& os) const
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
			os<<"4"<<symbol;
		}
		else
		{

		os<<"+4";
		}
}

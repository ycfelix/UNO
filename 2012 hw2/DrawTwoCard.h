/*
 * DrawTwoCard.h
 *
 *  Created on: Feb 5, 2018
 *      Author: kevinw
 */

#ifndef DRAWTWOCARD_H_
#define DRAWTWOCARD_H_
#include"SkipCard.h"
class DrawTwoCard:public SkipCard

{
public:
	DrawTwoCard(Color);

	virtual bool operator^(const Card& t) const;//done
		virtual void init() {}//done
		virtual ~DrawTwoCard()=default;

		virtual void castEffect(Player*& currentPlayer, CardPile& drawPile, CardPile& discardPile);
	protected:
		virtual void serialize(ostream& os) const override;//done, but dk if it works
};


#endif /* DRAWTWOCARD_H_ */

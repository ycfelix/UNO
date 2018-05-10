/*
 * NumberCard.h
 *
 *  Created on: Jan 29, 2018
 *      Author: kevinw
 */

#ifndef NUMBERCARD_H_
#define NUMBERCARD_H_
#include "Card.h"

class NumberCard:public Card{

public:
	NumberCard(int, Color);//done
	virtual bool operator^(const Card& t) const;//done
	virtual void init() {}//done
virtual ~NumberCard()=default;
	virtual void castEffect(Player*& currentPlayer, CardPile& drawPile, CardPile& discardPile);
protected:
	virtual void serialize(ostream& os) const override;//done, but dk if it works
};
#endif /* NUMBERCARD_H_ */

/*
 * SkipCard.h
 *
 *  Created on: Feb 2, 2018
 *      Author: kevinw
 */

#ifndef SKIPCARD_H_
#define SKIPCARD_H_

#include"Card.h"
#include<typeinfo>

class SkipCard:public Card
{
public:
	SkipCard(Color);
	virtual bool operator^(const Card& t) const;
	virtual void init() {}
virtual ~SkipCard()=default;
	virtual void castEffect(Player*& currentPlayer, CardPile& drawPile, CardPile& discardPile);
protected:
	virtual void serialize(ostream& os) const override;
};
#endif /* SKIPCARD_H_ */

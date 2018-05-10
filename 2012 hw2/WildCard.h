/*
 * WildCard.h
 *
 *  Created on: Feb 6, 2018
 *      Author: kevinw
 */

#ifndef WILDCARD_H_
#define WILDCARD_H_
#include"Card.h"
class WildCard:public Card{

public:
	WildCard();
	virtual bool operator^(const Card& t) const;
	virtual void init();

	virtual void castEffect(Player*& currentPlayer, CardPile& drawPile, CardPile& discardPile);
protected:
	virtual void serialize(ostream& os) const override;
};

#endif /* WILDCARD_H_ */

/*
 * ReverseCard.h
 *
 *  Created on: Feb 2, 2018
 *      Author: kevinw
 */

#ifndef REVERSECARD_H_
#define REVERSECARD_H_
#include"Card.h"
#include<typeinfo>
class ReverseCard:public Card{

public:
	ReverseCard(Color);//done

	virtual bool operator^(const Card& t) const;
	virtual void init() override{}
	virtual ~ReverseCard()=default;
	virtual void castEffect(Player*& currentPlayer, CardPile& drawPile, CardPile& discardPile);
protected:
	virtual void serialize(ostream& os) const override;

};



#endif /* REVERSECARD_H_ */

/*
 * plansza8x8.h
 *
 *  Created on: 15.05.2018
 *      Author: Mariusz
 */

#ifndef PLANSZA_8X8_PLANSZA8X8_H_
#define PLANSZA_8X8_PLANSZA8X8_H_

#include "../Plansza.h"
#include <vector>
class Plansza8x8
{
public:
	Plansza8x8(Plansza& _8x8)
	{
		//Plansza _8x8(8,8);

		for(int x=1; x<=8; x++)
		{
			_8x8.set_object(x, 2, Biale, Pionek);
			_8x8.set_object(x, 7, Czarne, Pionek);
		}

		_8x8.set_object(1, 1, Biale, Wieza);
		_8x8.set_object(2, 1, Biale, Skoczek);
		_8x8.set_object(3, 1, Biale, Goniec);
		_8x8.set_object(4, 1, Biale, Hetman);
		_8x8.set_object(5, 1, Biale, Krol);
		_8x8.set_object(6, 1, Biale, Goniec);
		_8x8.set_object(7, 1, Biale, Skoczek);
		_8x8.set_object(8, 1, Biale, Wieza);

		_8x8.set_object(1, 8, Czarne, Wieza);
		_8x8.set_object(2, 8, Czarne, Skoczek);
		_8x8.set_object(3, 8, Czarne, Goniec);
		_8x8.set_object(4, 8, Czarne, Hetman);
		_8x8.set_object(5, 8, Czarne, Krol);
		_8x8.set_object(6, 8, Czarne, Goniec);
		_8x8.set_object(7, 8, Czarne, Skoczek);
		_8x8.set_object(8, 8, Czarne, Wieza);


	}
};

#endif /* PLANSZA_8X8_PLANSZA8X8_H_ */

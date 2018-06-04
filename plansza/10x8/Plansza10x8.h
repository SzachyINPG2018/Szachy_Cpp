#ifndef PLANSZA_10X8_PLANSZA10X8_H_
#define PLANSZA_10X8_PLANSZA10X8_H_

#include "../Plansza.h"
#include <vector>
class Plansza10x8
{
public:
	Plansza10x8(Plansza& _10x8)
	{
		//Plansza _10x8(10,8);

		for(int x=1; x<=10; x++)
		{
			_10x8.set_object(x, 2, Biale, Pionek, x, 2);
			_10x8.set_object(x, 7, Czarne, Pionek, x, 7);
		}

		_10x8.set_object(1, 1, Biale, Wieza, 1, 1);
		_10x8.set_object(2, 1, Biale, Skoczek, 2, 1);
		_10x8.set_object(3, 1, Biale, Arcybiskup, 3, 1);
		_10x8.set_object(4, 1, Biale, Goniec, 4, 1);
		_10x8.set_object(5, 1, Biale, Hetman, 5, 1);
		_10x8.set_object(6, 1, Biale, Krol, 6, 1);
		_10x8.set_object(7, 1, Biale, Goniec, 7, 1);
		_10x8.set_object(8, 1, Biale, Kanclerz, 8, 1);
		_10x8.set_object(9, 1, Biale, Skoczek, 9, 1);
        _10x8.set_object(10, 1, Biale, Wieza, 10, 1);

		_10x8.set_object(1, 8, Czarne, Wieza, 1, 8);
		_10x8.set_object(2, 8, Czarne, Skoczek, 2, 8);
		_10x8.set_object(3, 8, Czarne, Arcybiskup, 3, 8);
		_10x8.set_object(4, 8, Czarne, Goniec, 4, 8);
		_10x8.set_object(5, 8, Czarne, Hetman, 5, 8);
		_10x8.set_object(6, 8, Czarne, Krol, 6, 8);
		_10x8.set_object(7, 8, Czarne, Goniec, 7, 8);
		_10x8.set_object(8, 8, Czarne, Kanclerz, 8, 8);
        _10x8.set_object(9, 8, Czarne, Skoczek, 8, 9);
        _10x8.set_object(10, 8, Czarne, Wieza, 8, 10);
	}
};

#endif /* PLANSZA_10X8_PLANSZA10X8_H_ */

#ifndef PLANSZA_10X10_PLANSZA10X10_H_
#define PLANSZA_10X10_PLANSZA10X10_H_

#include "../Plansza.h"
#include <vector>
class Plansza10x10
{
public:
	Plansza10x10(Plansza& _10x10)
	{
		//Plansza _10x10(10,10);

		for(int x=1; x<=10; x++)
		{
			_10x10.set_object(x, 2, Biale, Pionek, x, 2);
			_10x10.set_object(x, 9, Czarne, Pionek, x, 9);
		}

		_10x10.set_object(1, 1, Biale, Wieza, 1, 1);
		_10x10.set_object(2, 1, Biale, Skoczek, 2, 1);
		_10x10.set_object(3, 1, Biale, Arcybiskup, 3, 1);
		_10x10.set_object(4, 1, Biale, Goniec, 4, 1);
		_10x10.set_object(5, 1, Biale, Hetman, 5, 1);
		_10x10.set_object(6, 1, Biale, Krol, 6, 1);
		_10x10.set_object(7, 1, Biale, Goniec, 7, 1);
		_10x10.set_object(8, 1, Biale, Kanclerz, 8, 1);
		_10x10.set_object(9, 1, Biale, Skoczek, 9, 1);
        _10x10.set_object(10, 1, Biale, Wieza, 10, 1);

		_10x10.set_object(1, 10, Czarne, Wieza, 1, 10);
		_10x10.set_object(2, 10, Czarne, Skoczek, 2, 10);
		_10x10.set_object(3, 10, Czarne, Arcybiskup, 3, 10);
		_10x10.set_object(4, 10, Czarne, Goniec, 4, 10);
		_10x10.set_object(5, 10, Czarne, Hetman, 5, 10);
		_10x10.set_object(6, 10, Czarne, Krol, 6, 10);
		_10x10.set_object(7, 10, Czarne, Goniec, 7, 10);
		_10x10.set_object(8, 10, Czarne, Kanclerz, 8, 10);
        _10x10.set_object(9, 10, Czarne, Skoczek, 9, 10);
        _10x10.set_object(10, 10, Czarne, Wieza, 10, 10);
	}
};

#endif /* PLANSZA_10X8_PLANSZA10X10_H_ */

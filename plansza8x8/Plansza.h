/*
 * Plansza.h
 *
 *  Created on: 29.04.2018
 *      Author: Mariusz
 */


#ifndef PLANSZA8X8_PLANSZA_H_
#define PLANSZA8X8_PLANSZA_H_

#include "../Figury//Figury.h"

class Plansza
{
	Figury **_plansza;

public:
	Plansza()
	{
		_plansza = new Figury *[8];
		for(int i=0;i<8;i++) _plansza[i] = new Figury [8];
	}
	~Plansza()
	{
		for (int i=0; i<8; i++)	delete[] _plansza[i];
		delete[] _plansza;
	}

	Figury get_object(int x, int y)				{return _plansza[x][y];}
	void set_object(int x, int y, int team, int type)
	{
		_plansza[x][y] =	Figury(x, y, team, type);
	}
};

#endif /* PLANSZA8X8_PLANSZA_H_ */

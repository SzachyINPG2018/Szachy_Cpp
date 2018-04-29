/*
 * Plansza.h
 *
 *  Created on: 29.04.2018
 *      Author: Mariusz
 */

#ifndef PLANSZA8X8_PLANSZA_H_
#define PLANSZA8X8_PLANSZA_H_

#include "../Figury/Figury.h"

class Plansza
{
public:
	Plansza();

	void ustaw_standardowe();
	Figury get_object(int x, int y)				{return _figura[x][y];}
	void set_object(int x, int y, int team, int type)
	{
		_figura[x][y] =	Figury(x, y, team, type);
	}

private:
	Figury _figura[8][8];	//wskaünik na objekt figury
};

#endif /* PLANSZA8X8_PLANSZA_H_ */

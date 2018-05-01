/*
 * Plansza.h
 *
 *  Created on: 29.04.2018
 *      Author: Mariusz
 */


#ifndef PLANSZA8X8_PLANSZA_H_
#define PLANSZA8X8_PLANSZA_H_

#include "../Figury//Figury.h"
#include <vector>

using std::vector;

class Plansza
{

public:
	Plansza(int dimension)
		: _plansza(dimension, vector<Figury>(dimension)),
		  _dimension(dimension)
		{}
	~Plansza() {_plansza.clear();} //to nie zadzia³a bo tablica jest dwuwymiarowa

	Figury get_object(int x, int y)				{return _plansza[x][y];}
	void set_object(int x, int y, int team, int type)
	{
		_plansza[x][y] = Figury(x, y, team, type);
		for(int x=1; x <= _dimension; x++)
			for(int y=1; y <= _dimension; y++)
				_plansza[x][y].calc_possible_move(_plansza);
	}
private:
	vector<vector<Figury> > _plansza;
	int _dimension;
};

#endif /* PLANSZA8X8_PLANSZA_H_ */

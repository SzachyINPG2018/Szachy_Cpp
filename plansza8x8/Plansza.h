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
	Plansza(int dimension_x, int dimension_y)
		: _plansza(dimension_x, vector<Figury>(dimension_y)),
		  _dimension_x(dimension_x),
		  _dimension_y(dimension_y)
		{}
	//~Plansza() {_plansza.clear();} //to nie zadzia³a bo tablica jest dwuwymiarowa

	Figury get_object(int x, int y)				{return _plansza[x][y];}
	void set_object(int x, int y, int team, int type)
	{
		_plansza[x][y] = Figury(x, y, team, type);
		for(int i=1; i <= _dimension_x; i++)
			for(int j=1; j < _dimension_y; j++)
				_plansza[i-1][j-1].calc_possible_move(_plansza, _dimension_x, _dimension_y);
	}
private:
	vector<vector<Figury> > _plansza;
	int _dimension_x, _dimension_y;
};

#endif /* PLANSZA8X8_PLANSZA_H_ */

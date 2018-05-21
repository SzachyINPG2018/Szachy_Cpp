/*
 * Plansza.h
 *
 *  Created on: 29.04.2018
 *      Author: Mariusz
 */


#ifndef PLANSZA_PLANSZA_H_
#define PLANSZA_PLANSZA_H_

#include "../Figury/Figury.h"
#include <vector>
#include <math.h>

using std::vector;

class Plansza
{

public:
	Plansza(int dimension_x, int dimension_y)
		: _plansza(dimension_x+1, vector<Figury>(dimension_y+1)),
		  _dimension_x(dimension_x),
		  _dimension_y(dimension_y)
		{}
	//~Plansza() {_plansza.clear();} //to nie zadzia³a bo tablica jest dwuwymiarowa

	Figury get_object(int x, int y)				{return _plansza[x][y];}
	void set_object(int x, int y, int team, int type)
	{
		_plansza[x][y].set_xy(x, y);
		_plansza[x][y].set_team(team);
		_plansza[x][y].set_type(type);
		for(int i=1; i <= _dimension_x; i++)
			for(int j=1; j <= _dimension_y; j++)
				_plansza[i][j].calc_possible_move(_plansza, _dimension_x, _dimension_y);
	}

	void make_move(int x, int y, int xtarget, int ytarget)
	{
		if(x == xtarget)
			if(y < ytarget)
				if(abs(ytarget - y) <= _plansza[x][y].get_elongation_move(Gora))
				{
					_plansza[xtarget][ytarget].set_team(_plansza[x][y].get_team());
					_plansza[xtarget][ytarget].set_type(_plansza[x][y].get_type());
					_plansza[xtarget][ytarget].set_xy(x, y);
					_plansza[x][y].set_type(0);
				}
			if(y < ytarget)
				if(abs(ytarget - y) <= _plansza[x][y].get_elongation_move(Dol));
		//_plansza[x][y].
	}
private:
	vector<vector<Figury> > _plansza;
	int _dimension_x, _dimension_y;
};

#endif /* PLANSZA_PLANSZA_H_ */

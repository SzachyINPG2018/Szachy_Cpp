/*
 * Plansza.h
 *
 *  Created on: 29.04.2018
 *      Author: Mariusz
 */


#ifndef PLANSZA_PLANSZA_H_
#define PLANSZA_PLANSZA_H_

#include "../Figury/Figury.h"
#include "../kolorki/kolorki.h"
#include <vector>
#include <math.h>
#include <iostream>
#include <functional>
#include <cstdint>


using std::vector;
using std::cout;

enum figuryznaki
{
	Krolznak='K',
	Hetmanznak='H',
	Wiezaznak='W',
	Goniecznak='G',
	Skoczekznak='S',
	Pionekznak='P',
	Arcybiskupznak='A',
	Kanclerzznak='N'
};



class Plansza
{
public:
	Plansza(int dimension_x, int dimension_y)
		: _plansza(dimension_x+1, vector<Figury>(dimension_y+1)),
		  _dimension_x(dimension_x),
		  _dimension_y(dimension_y)
		{}
	//~Plansza() {_plansza.clear();} //to nie zadzia³a bo tablica jest dwuwymiarowa
	Figury get_object(int x, int y)	{return _plansza[x][y];}
	void set_object(int x, int y, int team, int type, int last_x, int last_y);
	int make_move(int x, int y, int xtarget, int ytarget);
	int capture(int x, int y, int xtarget, int ytarget);
	void draw(void);
private:
	vector<vector<Figury> > _plansza;
	int _dimension_x, _dimension_y;
	static int _newest_x;
    	static int _newest_y;
};

#endif /* PLANSZA_PLANSZA_H_ */


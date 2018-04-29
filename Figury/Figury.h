/*
 * Figury.h
 *
 *  Created on: 29.04.2018
 *      Author: Mariusz
 */

#ifndef FIGURY_H_
#define FIGURY_H_

class Figury {
public:
	Figury(int , int , int , int );

	//

	void set_xy(int x, int y) { _x = x; _y = y;}
	int get_team(void)	{return _team;}
	int get_x(void) {return _x;}
	int get_y(void) {return _y;}
private:
	int _x, _y;	//wspolrzedne
	int _team;	//biale = 0 czy czarne = 1
	int _type;
	int _possible_move;
};

#endif /* FIGURY_H_ */

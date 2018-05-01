/*
 * Figury.cpp
 *
 *  Created on: 29.04.2018
 *      Author: Mariusz
 */

#include "Figury.h"

Figury::Figury(int x, int y, int team, int type)
	: _x(x), _y(y), _team(team), _type(type), _elongation_move(8, 0)
{
	//--podstawowe ruchy
	switch(type)
	{
		case 1:	_probable_move = 0b11111111;	break;
		case 2:	_probable_move = 0b11111111;	break;
		case 3:	_probable_move = 0b1010101;		break;
		case 4:	_probable_move = 0b10101010;	break;
		case 5:	_probable_move = 0b111111111;	break;	//koñ
		case 6:	_probable_move = 0b00000001;	break;
	}
}

void Figury::calc_possible_move(vector<vector<Figury> > _plansza)
{
	if(_x==0 || _y==0) return;
	_possible_move = 0;

	if(_type == 5)
	{
		_possible_move = 256;
		//do przerobienia na uniwersalny wymiar planszy
		if(_x>1)	if(_y<7)	if(_plansza[_x-1][_y+2]._type == 0) _possible_move += 1;
		if(_x<8)	if(_y<7)	if(_plansza[_x+1][_y+2]._type == 0) _possible_move += 2;
		if(_x<7)	if(_y<8)	if(_plansza[_x+2][_y+1]._type == 0) _possible_move += 4;
		if(_x<7)	if(_y>1)	if(_plansza[_x+2][_y-1]._type == 0) _possible_move += 8;
		if(_x<8)	if(_y>2)	if(_plansza[_x+1][_y-2]._type == 0) _possible_move += 16;
		if(_x>1)	if(_y>2)	if(_plansza[_x-1][_y-2]._type == 0) _possible_move += 32;
		if(_x>2)	if(_y>1)	if(_plansza[_x-2][_y-1]._type == 0) _possible_move += 64;
		if(_x>2)	if(_y<8)	if(_plansza[_x-2][_y+1]._type == 0) _possible_move += 128;

	}


	return;
}

/*
 *
 * 100000000 	Skoczek
 *
 * 10000000		NW
 * 1000000		W
 * 100000		SW
 * 10000		S
 * 1000			SE
 * 100			E
 * 10 			NE
 * 1 			N
 *
 * 1 Krol
 * 2 Hetman
 * 3 Wieza
 * 4 Goniec
 * 5 Skoczek
 * 6 Pion
 *
 * \ | /
 * - F -
 * / | \
 *
 *  x|x
 * x | x
 * |-S-|
 * x | x
 *  x|x
 *
 */


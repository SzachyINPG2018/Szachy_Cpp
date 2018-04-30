/*
 * Figury.cpp
 *
 *  Created on: 29.04.2018
 *      Author: Mariusz
 */

#include "Figury.h"

Figury::Figury(int x, int y, int team, int type) : _x(x), _y(y), _team(team), _type(type)
{
	//--podstawowe ruchy
	if(type == 1)	_possible_move = 0b11111111;
	if(type == 2)	_possible_move = 0b11111111;
	if(type == 3)	_possible_move = 0b1010101;
	if(type == 4)	_possible_move = 0b10101010;
	if(type == 5)	_possible_move = 0b111111111;
	if(type == 6)	_possible_move = 0b00000001;

}

void set_possible_move(Figury figura, Figury plansza[][8])
{

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


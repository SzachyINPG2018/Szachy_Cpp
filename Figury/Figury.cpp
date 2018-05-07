/*
 * Figury.cpp
 *
 *  Created on: 29.04.2018
 *      Author: Mariusz
 */

#include "Figury.h"
#include <iostream>
#include <algorithm>
#include <vector>

Figury::Figury(int x, int y, int team, int type)
	: _x(x), _y(y), _team(team), _type(type), _elongation_move(8, 0)
{
	//--podstawowe ruchy
	switch(type)
	{
		case 1:	_probable_move = 0b11111111;	break; //krol
		case 2:	_probable_move = 0b11111111;	break;
		case 3:	_probable_move = 0b1010101;		break;
		case 4:	_probable_move = 0b10101010;	break;
		case 5:	_probable_move = 0b111111111;	break;	//koñ
		case 6:	_probable_move = 0b00000001;	break;
	}
	_possible_move = 0;
}

void Figury::calc_possible_move(vector<vector<Figury> > _plansza, int dimension_x, int dimension_y)
{
	if(_x==0 || _y==0) return;
	_possible_move = 0;

	if(_type == 6)		//sprawdza czy nie zachodzi promocja
	{
		if(_team == 0) if(_y == dimension_y) 	promote_pawn();
		if(_team == 1) if(_y == 1) 				promote_pawn();
	}

	if(_type == 1)	//krol
	{
		_possible_move = 0;

								if(_y < dimension_y)	if(_plansza[_x+0][_y+1]._type == 0) _possible_move += 1;
		if(_x < dimension_x)	if(_y < dimension_y)	if(_plansza[_x+1][_y+1]._type == 0) _possible_move += 2;
		if(_x < dimension_x)							if(_plansza[_x+1][_y+0]._type == 0) _possible_move += 4;
		if(_x < dimension_x)	if(_y > 1)				if(_plansza[_x+1][_y-1]._type == 0) _possible_move += 8;
								if(_y > 1)				if(_plansza[_x+0][_y-1]._type == 0) _possible_move += 16;
		if(_x > 1)				if(_y > 1)				if(_plansza[_x-1][_y-1]._type == 0) _possible_move += 32;
		if(_x > 1)										if(_plansza[_x-1][_y+0]._type == 0) _possible_move += 64;
		if(_x > 1)				if(_y < dimension_y) 	if(_plansza[_x-1][_y+1]._type == 0) _possible_move += 128;

		for(int i=0;i<8;i++) _elongation_move[i] = ((_possible_move & (1<<i))>>i);
	}

	if(_type == 2)	//hetman
	{
		_possible_move = 0;

		std::fill(_elongationbegin(), _elongationend(), 0);

		int x = _x , y = _y;

		while(y <= dimension_y)
		{
			y++;
			if(_plansza[x][y]._type == 0) _elongation_move[Gora]++;
		}

		x =_x; y = _y;

		while(x <= dimension_x && y <= dimension_y)
		{
			x++;	y++;
			if(_plansza[x][y]._type == 0) _elongation_move[GoraPrawo]++;
		}

		x =_x; y = _y;

		while(x <= dimension_x)
		{
			x++;
			if(_plansza[x][y]._type == 0) _elongation_move[Prawo]++;
		}

		x =_x; y = _y;


		while(x <= dimension_x && y>0)
		{
			x++; y--;
			if(_plansza[x][y]._type == 0) _elongation_move[DolPrawo]++;
		}

		x =_x; y = _y;

		while( y>0)
		{
			y--;
			if(_plansza[x][y]._type == 0) _elongation_move[Dol]++;
		}

		x =_x; y = _y;

		while( x>0 && y>0)
		{
			x--; y--;
			if(_plansza[x][y]._type == 0) _elongation_move[DolLewo]++;
		}

		x =_x; y = _y;

		while( x>0)
		{
			x--;
			if(_plansza[x][y]._type == 0) _elongation_move[Lewo]++;
		}

		x =_x; y = _y;


		while( x>0 && y <= dimension_y)
		{
			x--; y++;
			if(_plansza[x][y]._type == 0) _elongation_move[GoraLewo]++;
		}

		for(int i=1;i<8; i++)	if(_elongation_move[i]!=0) _possible_move += (1<<i);

	}

	if(_type == 5)	//konik
	{
		_possible_move = 256;

		if(_x> 1)				if(_y< (dimension_y-1))	if(_plansza[_x-1][_y+2]._type == 0) _possible_move += 1;
		if(_x< dimension_x)		if(_y< (dimension_y-1))	if(_plansza[_x+1][_y+2]._type == 0) _possible_move += 2;
		if(_x< (dimension_x-1))	if(_y< dimension_y)		if(_plansza[_x+2][_y+1]._type == 0) _possible_move += 4;
		if(_x< (dimension_x-1))	if(_y> 1)				if(_plansza[_x+2][_y-1]._type == 0) _possible_move += 8;
		if(_x< dimension_x)		if(_y> 2)				if(_plansza[_x+1][_y-2]._type == 0) _possible_move += 16;
		if(_x> 1)				if(_y> 2)				if(_plansza[_x-1][_y-2]._type == 0) _possible_move += 32;
		if(_x> 2)				if(_y> 1)				if(_plansza[_x-2][_y-1]._type == 0) _possible_move += 64;
		if(_x> 2)				if(_y< dimension_y)		if(_plansza[_x-2][_y+1]._type == 0) _possible_move += 128;

		for(int i=0;i<8;i++) _elongation_move[i] = ((_possible_move & (1<<i))>>i);
	}

	if(_type == 6)	//pion
	{

		if(_team == 0)
		{
			_elongation_move[Gora] = 0;
			_possible_move = (1<<Gora); //zak³ada ¿e bêdzie mo¿liwy ruch do góry
			if(_y == 2)	if(_plansza[_x][_y+2]._type == 0 && _plansza[_x][_y+1]._type == 0) _elongation_move[Gora] = 2;
			if(_y != 2)	if(_plansza[_x][_y+1]._type == 0) _elongation_move[Gora] = 1;
			if(_elongation_move[Gora] == 0) _possible_move = 0; //jednak nie ma ruchu
		}
		if(_team == 1)
		{
			_elongation_move[Dol] = 0;
			_possible_move = (1<<Dol); //zak³ada ¿e bêdzie mo¿liwy ruch w dó³
			if(_y == dimension_y-1)	if(_plansza[_x][_y-2]._type == 0 && _plansza[_x][_y-1]._type == 0) _elongation_move[Dol] = 2;
			if(_y != dimension_y-1)	if(_plansza[_x][_y-1]._type == 0) _elongation_move[Dol] = 1;
			if(_elongation_move[Dol] == 0) _possible_move = 0; //jednak nie ma ruchu
		}

	}
	return;
}

void Figury::promote_pawn(void)
{
	int i;
	powtorz:
	std::cout << "Wybierz typ:\n1.Hetman\n2.Wie¿a\n3.Goniec\n4.Skoczek\n";
	std::cin >> i;
	if(i==1) _type = Hetman;
	else if(i==2) _type = Wieza;
	else if(i==3) _type = Goniec;
	else if(i==4) _type = Skoczek;
	else if(i==5) _type = Krol; 		// tylko testowe
	else
	{
		std::cout << "\nError, error has³o nie prawid³owe\n";
		goto powtorz;
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


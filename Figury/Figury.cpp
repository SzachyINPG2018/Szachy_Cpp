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
	: _x(x), _y(y),
      _elongation_move(12 , 0), _possible_move(0),
	  _team(team), _type(type),
	  _last_x(0), _last_y(0),
	  _flag_move(0), _flag_castling(0)  {}

void Figury::calc_possible_move(vector<vector<Figury> > _plansza, int dimension_x, int dimension_y)
{
	if(_x==0 || _y==0) return;

	_possible_move = 0;

	std::fill(_elongationbegin(), _elongationend(), 0);

	if(_type == 6)		//sprawdza czy nie zachodzi promocja
	{
		if(_team == 0) if(_y == dimension_y) 	promote_pawn();
		if(_team == 1) if(_y == 1) 				promote_pawn();
	}

	if(_type == 1)	//krol
	{
								if(_y < dimension_y)	if(_plansza[_x+0][_y+1]._type == 0) _possible_move += 1;
		if(_x < dimension_x)	if(_y < dimension_y)	if(_plansza[_x+1][_y+1]._type == 0) _possible_move += 2;
		if(_x < dimension_x)							if(_plansza[_x+1][_y+0]._type == 0) _possible_move += 4;
		if(_x < dimension_x)	if(_y > 1)				if(_plansza[_x+1][_y-1]._type == 0) _possible_move += 8;
								if(_y > 1)				if(_plansza[_x+0][_y-1]._type == 0) _possible_move += 16;
		if(_x > 1)				if(_y > 1)				if(_plansza[_x-1][_y-1]._type == 0) _possible_move += 32;
		if(_x > 1)										if(_plansza[_x-1][_y+0]._type == 0) _possible_move += 64;
		if(_x > 1)				if(_y < dimension_y) 	if(_plansza[_x-1][_y+1]._type == 0) _possible_move += 128;


		_flag_castling = 0;
		if(dimension_x == 8) //roszada tylko dla 8x8
		if(_flag_move == 0)
		{
			if(_team == 0)
			{
				if(_plansza[1][1]._flag_move == 0)
					if(_plansza[2][1]._type == 0 &&
					   _plansza[3][1]._type == 0 &&
					   _plansza[4][1]._type == 0)		_flag_castling += 2; //roszada d�uga

				if(_plansza[1][1]._flag_move == 0)
					if(_plansza[6][1]._type == 0 &&
					   _plansza[7][1]._type == 0)		_flag_castling += 1; //roszada kr�tka
			}
			if(_team == 1)
			{
				if(_plansza[1][dimension_y]._flag_move == 0)
					if(_plansza[2][dimension_y]._type == 0 &&
					   _plansza[3][dimension_y]._type == 0 &&
					   _plansza[4][dimension_y]._type == 0)		_flag_castling += 2; //roszada d�uga

				if(_plansza[1][dimension_y]._flag_move == 0)
					if(_plansza[6][dimension_y]._type == 0 &&
					   _plansza[7][dimension_y]._type == 0)		_flag_castling += 1; //roszada kr�tka
			}

		}

		for(int i=0;i<8;i++) _elongation_move[i] = ((_possible_move & (1<<i))>>i);
	}

	if(_type >= 2 && _type <= 4)	//hetman 2, wieza 3, goniec 4
	{

		int x = _x , y = _y;


		if(_type == 2 || _type == 3)
		{

			while(y < dimension_y)
			{
				y++;
				if(_plansza[x][y]._type == 0) _elongation_move[Gora]++;
				else break;
			}
		}

		if(_type == 2 || _type == 4)
		{
			x =_x; y = _y;
			while(x < dimension_x && y < dimension_y)
			{
				x++;	y++;
				if(_plansza[x][y]._type == 0) _elongation_move[GoraPrawo]++;
				else break;
			}
		}

		if(_type == 2 || _type == 3)
		{
		x =_x; y = _y;
			while(x < dimension_x)
			{
				x++;
				if(_plansza[x][y]._type == 0) _elongation_move[Prawo]++;
				else break;
			}
		}

		if(_type == 2 || _type == 4)
		{
			x =_x; y = _y;
			while(x < dimension_x && y>1)
			{
				x++; y--;
				if(_plansza[x][y]._type == 0) _elongation_move[DolPrawo]++;
				else break;
			}
		}

		if(_type == 2 || _type == 3)
		{
			x =_x; y = _y;
			while( y>1)
			{
				y--;
				if(_plansza[x][y]._type == 0) _elongation_move[Dol]++;
				else break;
			}
		}

		if(_type == 2 || _type == 4)
		{
			x =_x; y = _y;
			while( x>1 && y>1)
			{
				x--; y--;
				if(_plansza[x][y]._type == 0) _elongation_move[DolLewo]++;
				else break;
			}
		}

		if(_type == 2 || _type == 3)
		{
			x =_x; y = _y;
			while( x>1)
			{
				x--;
				if(_plansza[x][y]._type == 0) _elongation_move[Lewo]++;
				else break;
			}
		}

		if(_type == 2 || _type == 4)
		{
			x =_x; y = _y;
			while( x>1 && y < dimension_y)
			{
				x--; y++;
				if(_plansza[x][y]._type == 0) _elongation_move[GoraLewo]++;
				else break;
			}
		}

		for(int i=0;i<8; i++)	if(_elongation_move[i]!=0) _possible_move += (1<<i);

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
			_possible_move = (1<<Gora); //zak�ada �e b�dzie mo�liwy ruch do g�ry
			if(_y == 2)	if(_plansza[_x][_y+2]._type == 0 && _plansza[_x][_y+1]._type == 0) _elongation_move[Gora] = 2;
			if(_y != 2)	if(_plansza[_x][_y+1]._type == 0) _elongation_move[Gora] = 1;
			if(_elongation_move[Gora] == 0) _possible_move = 0; //jednak nie ma ruchu
		}
		if(_team == 1)
		{
			_elongation_move[Dol] = 0;
			_possible_move = (1<<Dol); //zak�ada �e b�dzie mo�liwy ruch w d�
			if(_y == dimension_y-1)	if(_plansza[_x][_y-2]._type == 0 && _plansza[_x][_y-1]._type == 0) _elongation_move[Dol] = 2;
			if(_y != dimension_y-1)	if(_plansza[_x][_y-1]._type == 0) _elongation_move[Dol] = 1;
			if(_elongation_move[Dol] == 0) _possible_move = 0; //jednak nie ma ruchu
		}
	}


	if(_type == Arcybiskup || _type == Kanclerz)
	{
		_possible_move = (1<<8);	//ruch jak kon
		_possible_move = (1<<13);	//ruch dodatkowy jak goniec (A) lub wieza (K)

		if(_x> 1)				if(_y< (dimension_y-1))	if(_plansza[_x-1][_y+2]._type == 0) _possible_move += 1;
		if(_x< dimension_x)		if(_y< (dimension_y-1))	if(_plansza[_x+1][_y+2]._type == 0) _possible_move += 2;
		if(_x< (dimension_x-1))	if(_y< dimension_y)		if(_plansza[_x+2][_y+1]._type == 0) _possible_move += 4;
		if(_x< (dimension_x-1))	if(_y> 1)				if(_plansza[_x+2][_y-1]._type == 0) _possible_move += 8;
		if(_x< dimension_x)		if(_y> 2)				if(_plansza[_x+1][_y-2]._type == 0) _possible_move += 16;
		if(_x> 1)				if(_y> 2)				if(_plansza[_x-1][_y-2]._type == 0) _possible_move += 32;
		if(_x> 2)				if(_y> 1)				if(_plansza[_x-2][_y-1]._type == 0) _possible_move += 64;
		if(_x> 2)				if(_y< dimension_y)		if(_plansza[_x-2][_y+1]._type == 0) _possible_move += 128;

		for(int i=0;i<8;i++) _elongation_move[i] = ((_possible_move & (1<<i))>>i);

		int x = _x , y = _y;
		if(_type == Kanclerz)
		{
			while(y < dimension_y)
			{
				y++;
				if(_plansza[x][y]._type == 0) _elongation_move[GoraGoraPrawo]++;
				else break;
			}
		}

		x =_x; y = _y;
		if(_type == Arcybiskup)
		{
			while(x < dimension_x && y < dimension_y)
			{
				x++;	y++;
				if(_plansza[x][y]._type == 0) _elongation_move[GoraGoraPrawo]++;
				else break;
			}
		}

		x =_x; y = _y;
		if(_type == Kanclerz)
		{
			while(x < dimension_x)
			{
				x++;
				if(_plansza[x][y]._type == 0) _elongation_move[PrawoDolPrawo]++;
				else break;
			}
		}

		x =_x; y = _y;
		if(_type == Arcybiskup)
		{
			while(x < dimension_x && y>1)
			{
				x++; y--;
				if(_plansza[x][y]._type == 0) _elongation_move[PrawoDolPrawo]++;
				else break;
			}
		}

		x =_x; y = _y;
		if(_type == Kanclerz)
		{

			while( y>1)
			{
				y--;
				if(_plansza[x][y]._type == 0) _elongation_move[DolDolLewo]++;
				else break;
			}
		}

		if(_type == Arcybiskup)
		{
			x =_x; y = _y;
			while( x>1 && y>1)
			{
				x--; y--;
				if(_plansza[x][y]._type == 0) _elongation_move[DolDolLewo]++;
				else break;
			}
		}

		x =_x; y = _y;
		if(_type == Kanclerz)
		{
			while( x>1)
			{
				x--;
				if(_plansza[x][y]._type == 0) _elongation_move[LewoGoraLewo]++;
				else break;
			}
		}

		x =_x; y = _y;
		if(_type == Arcybiskup)
		{
			while( x>1 && y < dimension_y)
			{
				x--; y++;
				if(_plansza[x][y]._type == 0) _elongation_move[LewoGoraLewo]++;
				else break;
			}
		}

		for(int i=0;i<4; i++)	if(_elongation_move[i+8]!=0) _possible_move += (1<<i);
	}

	return;
}

void Figury::promote_pawn(void)
{
	int i;
	powtorz:
	std::cout << "Wybierz typ:\n1.Hetman\n2.Wie�a\n3.Goniec\n4.Skoczek\n";
	std::cin >> i;
	if(i==1) _type = Hetman;
	else if(i==2) _type = Wieza;
	else if(i==3) _type = Goniec;
	else if(i==4) _type = Skoczek;
	else if(i==5) _type = Krol; 		// tylko testowe
	else
	{
		std::cout << "\nError, error has�o nie prawid�owe\n";
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


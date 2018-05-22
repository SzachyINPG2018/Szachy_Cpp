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
#include <string>

using std::vector;


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


	//bez konia kanclerza i arcybiskupa
	int make_move(int x, int y, int xtarget, int ytarget)
	{
		int direction=0;
		if(x == xtarget && y == ytarget) return 0;


		if(_plansza[x][y].get_type() != Skoczek &&
			_plansza[x][y].get_type() != Arcybiskup &&
			_plansza[x][y].get_type() != Kanclerz)
		{
			if(x == xtarget)
			{
				if(y < ytarget) direction = Gora;
				if(y > ytarget)	direction = Dol;

				if(abs(ytarget - y) <= _plansza[x][y].get_elongation_move(direction))
				{
					set_object(xtarget, ytarget,
								_plansza[x][y].get_team(),
								_plansza[x][y].get_type());
					_plansza[x][y].set_type(0);
					return 1;
				}
			}

			if(abs(xtarget - x) == abs(ytarget - y))
			{
				if(x < xtarget && y < ytarget) direction = GoraPrawo;
				if(x < xtarget && y > ytarget) direction = DolPrawo;
				if(x > xtarget && y > ytarget) direction = DolLewo;
				if(x > xtarget && y < ytarget) direction = GoraLewo;

				if(abs(ytarget - y) <= _plansza[x][y].get_elongation_move(direction))
				{
					set_object(xtarget, ytarget,
								_plansza[x][y].get_team(),
								_plansza[x][y].get_type());
					_plansza[x][y].set_type(0);
					return 1;
				}
			}

			if(y == ytarget)
			{
				if(x < xtarget) direction = Prawo;
				if(x > xtarget)	direction = Lewo;

				if(abs(xtarget - x) <= _plansza[x][y].get_elongation_move(direction))
				{
					set_object(xtarget, ytarget,
								_plansza[x][y].get_team(),
								_plansza[x][y].get_type());
					_plansza[x][y].set_type(0);
					return 1;
				}
			}

		}
		if(_plansza[x][y].get_type()==Skoczek)
        {
			if (x-1==xtarget && y+2==ytarget && (_plansza[x][y].get_elongation_move(0)==1))
			{
				set_object(xtarget, ytarget,
							_plansza[x][y].get_team(),
							_plansza[x][y].get_type());
				_plansza[x][y].set_type(0);
				return 1;
			}
			if (x+1==xtarget && y+2==ytarget && (_plansza[x][y].get_elongation_move(1)==1))
			{
				set_object(xtarget, ytarget,
							_plansza[x][y].get_team(),
							_plansza[x][y].get_type());
				_plansza[x][y].set_type(0);
				return 1;
			}
			if (xtarget==x+2 && ytarget==y+1 && (_plansza[x][y].get_elongation_move(2)==1))
			{
				set_object(xtarget, ytarget,
							_plansza[x][y].get_team(),
							_plansza[x][y].get_type());
				_plansza[x][y].set_type(0);
				return 1;
			}
			if (xtarget==x+2 && ytarget==y-1 && (_plansza[x][y].get_elongation_move(3)==1))
			{
				set_object(xtarget, ytarget,
							_plansza[x][y].get_team(),
							_plansza[x][y].get_type());
				_plansza[x][y].set_type(0);
				return 1;
			}
			if (xtarget==x+1 && ytarget==y-2 && (_plansza[x][y].get_elongation_move(4)==1))
			{
				set_object(xtarget, ytarget,
							_plansza[x][y].get_team(),
							_plansza[x][y].get_type());
				_plansza[x][y].set_type(0);
				return 1;
			}
			if (xtarget==x-1 && ytarget==y-2 && (_plansza[x][y].get_elongation_move(5)==1))
			{
				set_object(xtarget, ytarget,
							_plansza[x][y].get_team(),
							_plansza[x][y].get_type());
				_plansza[x][y].set_type(0);
				return 1;
			}
			if (xtarget==x-2 && ytarget==y-1 && (_plansza[x][y].get_elongation_move(6)==1))
			{
				set_object(xtarget, ytarget,
							_plansza[x][y].get_team(),
							_plansza[x][y].get_type());
				_plansza[x][y].set_type(0);
				return 1;
			}
			if (xtarget==x-2 && ytarget==y+1 && (_plansza[x][y].get_elongation_move(7)==1))
			{
				set_object(xtarget, ytarget,
							_plansza[x][y].get_team(),
							_plansza[x][y].get_type());
				_plansza[x][y].set_type(0);
				return 1;
			}
        }
		return 0;
	}



	void draw(void)
	{
		std::string color;
		std::cout <<"     ";
		SetColor("D0");
		char znak;
		std::cout <<"CZARNE"<< "\n";
		SetColor("2D");
		std::cout << "--";
		for(int x=0; x < _dimension_x; x++) std::cout << "-" << char(x+'a');
		std::cout << "---\n";
		for(int x=0; x < _dimension_x; x++) std::cout << "--";
		std::cout << "-----\n";
		for(int y=_dimension_y-1; y >=0; y--)
		{
			SetColor("2D");
			std::cout << "--";
			for(int x=0; x < _dimension_x; x++)
			{
				SetColor("EE");
				std::cout << "-";

				if(_plansza[x+1][y+1].get_team()==1 )
				{
					if((x+y)%2)	SetColor("64");
					else SetColor("E4");
				}
				if(_plansza[x+1][y+1].get_team()==0)
				{
					if((x+y)%2)	SetColor("6A");
					else SetColor("EA");
				}


				znak = _plansza[x+1][y+1].get_type();
				//color;
				switch( znak )
				{
				case 0:
					znak = ' '; 		break;
				case Krol:
					znak = Krolznak;	break;
				case Hetman:
					znak = Hetmanznak;	break;
				case Wieza:
					znak = Wiezaznak;	break;
				case Goniec:
					znak = Goniecznak;	break;
				case Skoczek:
					znak = Skoczekznak;	break;
				case Pionek:
					znak = Pionekznak;	break;
				case Arcybiskup:
					znak = Arcybiskupznak;	break;
				case Kanclerz:
					znak = Kanclerzznak;	break;
				}
				std::cout << znak;
			}

			SetColor("2D");


			std::cout << "--" << y+1 << "\n";

		}
		for(int x=0; x < _dimension_x; x++) std::cout << "--";
		std::cout << "-----\n";
		SetColor("ED");
		std::cout <<"     "<<"BIALE"<< "\n";
	}



private:
	vector<vector<Figury> > _plansza;
	int _dimension_x, _dimension_y;
};

#endif /* PLANSZA_PLANSZA_H_ */

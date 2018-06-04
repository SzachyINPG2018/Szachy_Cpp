/*
 * Plansza.cpp
 *
 *  Created on: 29.04.2018
 *      Author: Mariusz
 */

#include "../plansza/Plansza.h"
int Plansza::_newest_x=0;
int Plansza::_newest_y=0;

void Plansza::set_object(int x, int y, int team, int type, int last_x, int last_y)
{
	_plansza[x][y].set_xy(x, y);
	_plansza[x][y].set_team(team);
	_plansza[x][y].set_type(type);
	_plansza[x][y].set_last_xy(last_x, last_y);
	for(int i=1; i <= _dimension_x; i++)
		for(int j=1; j <= _dimension_y; j++)
            _plansza[i][j].calc_possible_move(_plansza, _dimension_x, _dimension_y);
}

int Plansza::make_move(int x, int y, int xtarget, int ytarget)
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
				if (_plansza[x][y].get_type()==Pionek)
                {
                    if(_plansza[xtarget-1][ytarget].get_type()==Pionek &&
                            abs(_plansza[xtarget-1][ytarget].get_last_y()-ytarget)==2 &&
                            _newest_x==xtarget &&
                            _newest_y==ytarget)
                    {
						_plansza[xtarget-1][ytarget].set_type(0);
                    }
                    if((_plansza[xtarget+1][ytarget].get_type()==Pionek) &&
                            abs(_plansza[xtarget+1][ytarget].get_last_y()-ytarget)==2 &&
                            _newest_x==xtarget &&
                            _newest_y==ytarget)
                    {
                        _plansza[xtarget+1][ytarget].set_type(0);
                    }
                }
                set_object(xtarget, ytarget,
                            _plansza[x][y].get_team(),
                            _plansza[x][y].get_type(),
                            x, y);
                _plansza[x][y].set_type(0);
				_newest_x=xtarget;
				_newest_y=ytarget;
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
                            _plansza[x][y].get_type(),
                            x, y);
                _plansza[x][y].set_type(0);
                _newest_x=xtarget;
                _newest_y=ytarget;
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
							_plansza[x][y].get_type(),
                   			x, y);
				_plansza[x][y].set_type(0);
				_newest_x=xtarget;
				_newest_y=ytarget;
				return 1;
			}
		}
	}
	if(_plansza[x][y].get_type()==Skoczek ||
        _plansza[x][y].get_type()==Kanclerz ||
        _plansza[x][y].get_type()== Arcybiskup)
   	{
        if (x-1==xtarget && y+2==ytarget && (_plansza[x][y].get_elongation_move(0)==1))
		{
			set_object(xtarget, ytarget,
					_plansza[x][y].get_team(),
                    			_plansza[x][y].get_type(),
                    			x, y);
			_plansza[x][y].set_type(0);
			_newest_x=xtarget;
			_newest_y=ytarget;
			return 1;
		}
		if (x+1==xtarget && y+2==ytarget && (_plansza[x][y].get_elongation_move(1)==1))
		{
			set_object(xtarget, ytarget,
					_plansza[x][y].get_team(),
					_plansza[x][y].get_type(),
                   			x, y);
			_plansza[x][y].set_type(0);
			_newest_x=xtarget;
			_newest_y=ytarget;
			return 1;
		}
		if (xtarget==x+2 && ytarget==y+1 && (_plansza[x][y].get_elongation_move(2)==1))
		{
			set_object(xtarget, ytarget,
                        	_plansza[x][y].get_team(),
				_plansza[x][y].get_type(),
                        	x, y);
			_plansza[x][y].set_type(0);
			_newest_x=xtarget;
			_newest_y=ytarget;
			return 1;
		}
		if (xtarget==x+2 && ytarget==y-1 && (_plansza[x][y].get_elongation_move(3)==1))
		{
			set_object(xtarget, ytarget,
				_plansza[x][y].get_team(),
				_plansza[x][y].get_type(),
               			x, y);
			_plansza[x][y].set_type(0);
			_newest_x=xtarget;
			_newest_y=ytarget;
			return 1;
		}
		if (xtarget==x+1 && ytarget==y-2 && (_plansza[x][y].get_elongation_move(4)==1))
		{
			set_object(xtarget, ytarget,
				_plansza[x][y].get_team(),
				_plansza[x][y].get_type(),
                x, y);
			_plansza[x][y].set_type(0);
			_newest_x=xtarget;
			_newest_y=ytarget;
			return 1;
		}
		if (xtarget==x-1 && ytarget==y-2 && (_plansza[x][y].get_elongation_move(5)==1))
		{
			set_object(xtarget, ytarget,
                    _plansza[x][y].get_team(),
                    _plansza[x][y].get_type(),
                    x, y);
			_plansza[x][y].set_type(0);
			_newest_x=xtarget;
			_newest_y=ytarget;
			return 1;
		}
		if (xtarget==x-2 && ytarget==y-1 && (_plansza[x][y].get_elongation_move(6)==1))
		{
			set_object(xtarget, ytarget,
				_plansza[x][y].get_team(),
				_plansza[x][y].get_type(),
                   		x, y);
			_plansza[x][y].set_type(0);
			_newest_x=xtarget;
			_newest_y=ytarget;
			return 1;
		}
		if (xtarget==x-2 && ytarget==y+1 && (_plansza[x][y].get_elongation_move(7)==1))
		{
			set_object(xtarget, ytarget,
				_plansza[x][y].get_team(),
				_plansza[x][y].get_type(),
                   		x, y);
			_plansza[x][y].set_type(0);
			_newest_x=xtarget;
			_newest_y=ytarget;
			return 1;
		}
	}
	if(_plansza[x][y].get_type()== Arcybiskup &&
        abs(xtarget - x) == abs(ytarget - y))
    {
        if(x < xtarget && y < ytarget) direction = GoraGoraPrawo;
        if(x < xtarget && y > ytarget) direction = PrawoDolPrawo;
        if(x > xtarget && y > ytarget) direction = DolDolLewo;
        if(x > xtarget && y < ytarget) direction = LewoGoraLewo;
        if(abs(ytarget - y) <= _plansza[x][y].get_elongation_move(direction))
        {
            set_object(xtarget, ytarget,
                        _plansza[x][y].get_team(),
                        _plansza[x][y].get_type(),
                        x, y);
            _plansza[x][y].set_type(0);
            _newest_x=xtarget;
            _newest_y=ytarget;
            return 1;
        }
    }

    if(_plansza[x][y].get_type()==Kanclerz)
    {
        if(x == xtarget)
		{
			if(y < ytarget) direction = GoraGoraPrawo;
			if(y > ytarget)	direction = DolDolLewo;
            if(abs(ytarget - y) <= _plansza[x][y].get_elongation_move(direction))
			{
			    set_object(xtarget, ytarget,
                            _plansza[x][y].get_team(),
                            _plansza[x][y].get_type(),
                            x, y);
                _plansza[x][y].set_type(0);
				_newest_x=xtarget;
				_newest_y=ytarget;
				return 1;
            }
		}
		if(y == ytarget)
		{
			if(x < xtarget) direction = PrawoDolPrawo;
			if(x > xtarget)	direction = LewoGoraLewo;
            if(abs(xtarget - x) <= _plansza[x][y].get_elongation_move(direction))
			{
			    set_object(xtarget, ytarget,
                            _plansza[x][y].get_team(),
                            _plansza[x][y].get_type(),
                            x, y);
                _plansza[x][y].set_type(0);
				_newest_x=xtarget;
				_newest_y=ytarget;
				return 1;
            }
		}
    }

	return 0;
}

int Plansza::capture(int x, int y, int xtarget, int ytarget)
{
	int direction=0;
	if((x == xtarget && y == ytarget) ||
	   xtarget<1 || xtarget>_dimension_x ||
	   ytarget<1 || ytarget> _dimension_y ||
	  (_plansza[xtarget][ytarget].get_type()==0)) return 0;

	if((x==xtarget || y==ytarget) && ( _plansza[x][y].get_type()==Wieza ||
        _plansza[x][y].get_type()==Hetman ||
        _plansza[x][y].get_type()==Krol))
	{
        if(abs(y-ytarget)!=1 && _plansza[x][y].get_type()==Krol) return 0;
        if(y < ytarget) direction = Gora;
        if(y > ytarget)	direction = Dol;
        if(abs(ytarget - y) != _plansza[x][y].get_elongation_move(direction) + 1) return 0;

        if (_plansza[x][y].get_team() != _plansza[xtarget][ytarget].get_team())
		{
			_plansza[xtarget][ytarget].set_type(0);
			set_object(xtarget, ytarget,
				_plansza[x][y].get_team(),
				_plansza[x][y].get_type(),
          			x, y);
			_plansza[x][y].set_type(0);
			_newest_x=xtarget;
        		_newest_y=ytarget;
			return 1;
		}
	}

	if((abs(xtarget - x) == abs(ytarget - y)) &&
        (_plansza[x][y].get_type()==Goniec ||
            _plansza[x][y].get_type()==Hetman ||
            _plansza[x][y].get_type()==Krol ||
            _plansza[x][y].get_type()== Pionek))
	{
        if((_plansza[x][y].get_type()==Krol || _plansza[x][y].get_type()== Pionek) && abs(x-xtarget)!=1) return 0;
        if(x < xtarget && y > ytarget)
        {
            if (_plansza[x][y].get_type()== Pionek && _plansza[x][y].get_team()==0) return 0;
            direction = DolPrawo;
        }
        if(x > xtarget && y > ytarget)
        {
            if (_plansza[x][y].get_type()== Pionek && _plansza[x][y].get_team()==0) return 0;
            direction = DolLewo;
        }
        if(x < xtarget && y < ytarget)
        {
            if (_plansza[x][y].get_type()== Pionek && _plansza[x][y].get_team()==1) return 0;
            direction = GoraPrawo;
        }
        if(x > xtarget && y < ytarget && _plansza[x][y].get_type()!= Pionek )
        {
            if (_plansza[x][y].get_type()== Pionek && _plansza[x][y].get_team()==1) return 0;
            direction = GoraLewo;
        }

        if(abs(ytarget - y) != (_plansza[x][y].get_elongation_move(direction) + 1)) return 0;
        if (_plansza[x][y].get_team() != _plansza[xtarget][ytarget].get_team())
        {
            _plansza[xtarget][ytarget].set_type(0);
            set_object(xtarget, ytarget,
                    _plansza[x][y].get_team(),
                    _plansza[x][y].get_type(),
                x, y);
            _plansza[x][y].set_type(0);
            _newest_x=xtarget;
            _newest_y=ytarget;
            return 1;
        }
    }

    if(y == ytarget && (_plansza[x][y].get_type()==Wieza ||
        _plansza[x][y].get_type()==Hetman ||
        _plansza[x][y].get_type()==Krol))
    {
        if(abs(y-ytarget)!=1 && _plansza[x][y].get_type()==Krol) return 0;
        if(x < xtarget) direction = Prawo;
        if(x > xtarget)	direction = Lewo;

        if(abs(xtarget - x) != (_plansza[x][y].get_elongation_move(direction) + 1)) return 0;

        if (_plansza[x][y].get_team() != _plansza[xtarget][ytarget].get_team())
        {
            _plansza[xtarget][ytarget].set_type(0);
            set_object(xtarget, ytarget,
                    _plansza[x][y].get_team(),
                    _plansza[x][y].get_type(),
                    x, y);
            _plansza[x][y].set_type(0);
            _newest_x=xtarget;
            _newest_y=ytarget;
            return 1;
        }
    }


    if(_plansza[x][y].get_type()==Skoczek ||
        _plansza[x][y].get_type()==Kanclerz ||
        _plansza[x][y].get_type()==Arcybiskup)
    {
        if (x-1==xtarget && y+2==ytarget &&
            (_plansza[x][y].get_elongation_move(0)==0) &&
            (_plansza[x][y].get_team()!= _plansza[xtarget][ytarget].get_team()))
        {
            _plansza[xtarget][ytarget].set_type(0);
            set_object(xtarget, ytarget,
                    _plansza[x][y].get_team(),
                    _plansza[x][y].get_type(),
                    x, y);
                _plansza[x][y].set_type(0);
            _newest_x=xtarget;
            _newest_y=ytarget;
            return 1;
        }
        if (x+1==xtarget && y+2==ytarget &&
            (_plansza[x][y].get_elongation_move(1)==0) &&
            (_plansza[x][y].get_team() != _plansza[xtarget][ytarget].get_team()))
        {
            _plansza[xtarget][ytarget].set_type(0);
            set_object(xtarget, ytarget,
                _plansza[x][y].get_team(),
                _plansza[x][y].get_type(),
                x, y);
            _plansza[x][y].set_type(0);
            _newest_x=xtarget;
            _newest_y=ytarget;
            return 1;
        }
        if (xtarget==x+2 && ytarget==y+1 &&
            (_plansza[x][y].get_elongation_move(2)==0) &&
            (_plansza[x][y].get_team() != _plansza[xtarget][ytarget].get_team()))
        {
            _plansza[xtarget][ytarget].set_type(0);
            set_object(xtarget, ytarget,
                _plansza[x][y].get_team(),
                _plansza[x][y].get_type(),
                x, y);
                _plansza[x][y].set_type(0);
                _newest_x=xtarget;
                _newest_y=ytarget;
                return 1;
        }
        if (xtarget==x+2 && ytarget==y-1 &&
            (_plansza[x][y].get_elongation_move(3)==0) &&
            (_plansza[x][y].get_team() != _plansza[xtarget][ytarget].get_team()))
        {
            _plansza[xtarget][ytarget].set_type(0);
            set_object(xtarget, ytarget,
                _plansza[x][y].get_team(),
                _plansza[x][y].get_type(),
                x, y);
            _plansza[x][y].set_type(0);
            _newest_x=xtarget;
            _newest_y=ytarget;
            return 1;
        }
        if (xtarget==x+1 && ytarget==y-2 &&
            (_plansza[x][y].get_elongation_move(4)==0) &&
            (_plansza[x][y].get_team() != _plansza[xtarget][ytarget].get_team()))
        {
            _plansza[xtarget][ytarget].set_type(0);
            set_object(xtarget, ytarget,
                _plansza[x][y].get_team(),
                _plansza[x][y].get_type(),
                x, y);
            _plansza[x][y].set_type(0);
            _newest_x=xtarget;
            _newest_y=ytarget;
            return 1;
        }
        if (xtarget==x-1 && ytarget==y-2 &&
            (_plansza[x][y].get_elongation_move(5)==0) &&
            (_plansza[x][y].get_team() != _plansza[xtarget][ytarget].get_team()))
        {
            _plansza[xtarget][ytarget].set_type(0);
            set_object(xtarget, ytarget,
                _plansza[x][y].get_team(),
                _plansza[x][y].get_type(),
                x, y);
            _plansza[x][y].set_type(0);
            _newest_x=xtarget;
            _newest_y=ytarget;
            return 1;
        }
        if (xtarget==x-2 && ytarget==y-1 &&
            (_plansza[x][y].get_elongation_move(6)==0) &&
            (_plansza[x][y].get_team()!= _plansza[xtarget][ytarget].get_team()))
        {
            _plansza[xtarget][ytarget].set_type(0);
            set_object(xtarget, ytarget,
                _plansza[x][y].get_team(),
                _plansza[x][y].get_type(),
                x, y);
                _plansza[x][y].set_type(0);
                _newest_x=xtarget;
                _newest_y=ytarget;
                return 1;
        	}
        if (xtarget==x-2 && ytarget==y+1 &&
            (_plansza[x][y].get_elongation_move(7)==0) &&
            (_plansza[x][y].get_team() != _plansza[xtarget][ytarget].get_team()))
        {
            _plansza[xtarget][ytarget].set_type(0);
            set_object(xtarget, ytarget,
                _plansza[x][y].get_team(),
                _plansza[x][y].get_type(),
                x, y);
            _plansza[x][y].set_type(0);
            _newest_x=xtarget;
            _newest_y=ytarget;
            return 1;
        }
	}
	if (_plansza[x][y].get_type()==Arcybiskup && abs(x-xtarget)==abs(y-ytarget))
    {
        if(x < xtarget && y < ytarget) direction = GoraGoraPrawo;
        if(x < xtarget && y > ytarget) direction = PrawoDolPrawo;
        if(x > xtarget && y > ytarget) direction = DolDolLewo;
        if(x > xtarget && y < ytarget) direction = LewoGoraLewo;
        if(abs(ytarget - y) != _plansza[x][y].get_elongation_move(direction) + 1) return 0;
        set_object(xtarget, ytarget,
                            _plansza[x][y].get_team(),
                            _plansza[x][y].get_type(),
                            x, y);
        _plansza[x][y].set_type(0);
        _newest_x=xtarget;
        _newest_y=ytarget;
        return 1;
    }
    if (_plansza[x][y].get_type()==Kanclerz && (x==xtarget || y==ytarget))
    {
        if(x == xtarget && y < ytarget) direction = GoraGoraPrawo;
        if(x == xtarget && y > ytarget) direction = DolDolLewo;
        if(x > xtarget && y == ytarget) direction = PrawoDolPrawo;
        if(x < xtarget && y == ytarget) direction = LewoGoraLewo;
        if(abs(ytarget - y) != _plansza[x][y].get_elongation_move(direction) + 1) return 0;
        set_object(xtarget, ytarget,
                            _plansza[x][y].get_team(),
                            _plansza[x][y].get_type(),
                            x, y);
        _plansza[x][y].set_type(0);
        _newest_x=xtarget;
        _newest_y=ytarget;
        return 1;
    }
	return 0;
}

void Plansza::draw(void)
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


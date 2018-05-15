/*
 * Figury.h
 *
 *  Created on: 29.04.2018
 *      Author: Mariusz
 */

#ifndef FIGURY_H_
#define FIGURY_H_

#include <vector>

using std::vector;

class Figury
{
public:
	//Figury();
	Figury(int x=0, int y=0, int team=0, int type=0);

	void set_xy(int x, int y) { _x = x; _y = y;}
	int get_team(void)	{return _team;}
	int get_type(void)	{return _type;}
	int get_x(void) {return _x;}
	int get_y(void) {return _y;}

	int get_possible_move(void) {return _possible_move;}
	void calc_possible_move(vector<vector<Figury> > _plansza, int dimension_x, int dimension_y); //metoda obliczaj mo¿liwy ruch
	//void set_possible_move(int move)	{_possible_move = move;}

	int get_elongation_move(int direction)		{return _elongation_move[direction];}
	//void calc_elongation_move(vector<vector<Figury> > _plansza, int dimension_x, int dimension_y);

	void promote_pawn(void);	//metoda promocji pionu


	std::vector<int>::iterator _elongationbegin()
	{ return _elongation_move.begin(); }

	std::vector<int>::iterator _elongationend()
	{ return _elongation_move.end(); }



private:
	int _possible_move;
	int _x, _y;	//wspolrzedne
	int _team;	//biale = 0 czy czarne = 1
	int _type;
	vector<int> _elongation_move;
	//ruch jest mo¿liwy tylko w 8 kierunkach (skoczek te¿ tylko inaczej)
	//wiêc zmienna przechowuje o ile dana figura mo¿e siê poruszyc

};

/*
* 1 Krol
* 2 Hetman
* 3 Wieza
* 4 Goniec
* 5 Skoczek
* 6 Pionek
*/

enum figury
{
	Krol=1,
	Hetman,
	Wieza,
	Goniec,
	Skoczek,
	Pionek,
};

enum kierunek_ruchu
{
	Gora=0,
	GoraPrawo,
	Prawo,
	DolPrawo,
	Dol,
	DolLewo,
	Lewo,
	GoraLewo,
};

enum team
{
	Biale=0,
	Czarne,
	Czerwone,
};

#endif /* FIGURY_H_ */

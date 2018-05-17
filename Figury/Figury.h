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
	void set_team(int team)	{_team = team;}
	void set_type(int type)	{_type = type;}
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

	int get_castling(void)		{return _flag_castling;}


	std::vector<int>::iterator _elongationbegin()
	{ return _elongation_move.begin(); }

	std::vector<int>::iterator _elongationend()
	{ return _elongation_move.end(); }



private:
	int _possible_move;
	int _x, _y;	//wspolrzedne
	int _team;	//biale = 0 czy czarne = 1
	int _type;
	int _flag_move;
	int _flag_castling; //flaga zezwalaj¹ca na roszade 0 - nie 1- krótka 2- dluga 3- obie

	vector<int> _elongation_move;
	//ruch jest mo¿liwy tylko w 12 kierunkach (skoczek te¿ tylko inaczej)
	//wiêc zmienna przechowuje o ile dana figura mo¿e siê poruszyc
	//arcybiskup i kanclerz s¹ upoœledzone

};

/*
* 1 Krol
* 2 Hetman
* 3 Wieza
* 4 Goniec
* 5 Skoczek
* 6 Pionek
* 7 Arcybiskup
* 8 Kanclerz
*/

enum figury
{
	Krol=1,
	Hetman,
	Wieza,
	Goniec,
	Skoczek,
	Pionek,
	Arcybiskup,
	Kanclerz
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
	GoraGoraPrawo=8,
	PrawoDolPrawo,
	DolDolLewo,
	LewoGoraLewo
};

enum team
{
	Biale=0,
	Czarne,
	Czerwone,
};

#endif /* FIGURY_H_ */

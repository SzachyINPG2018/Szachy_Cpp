/*
 * Figury.h
 *
 *  Created on: 29.04.2018
 *      Author: Mariusz
 */

#ifndef FIGURY_H_
#define FIGURY_H_

class Figury
{
public:
	//Figury();
	Figury(int x=0, int y=0, int team=0, int type=0);

	void set_xy(int x, int y) { _x = x; _y = y;}
	int get_team(void)	{return _team;}
	int get_x(void) {return _x;}
	int get_y(void) {return _y;}
	int get_possible_move(void) {return _possible_move;}
	void set_possible_move(Figury _figura, Figury **plansza);

private:
	int _x, _y;	//wspolrzedne
	int _team;	//biale = 0 czy czarne = 1
	int _type;
	int _possible_move;
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


//Zamiast tego typ wyliczeniowy enum
//-----------------------------------------------------------
//class Krol : public Figury
//{
//public:
//	Krol(int x, int y, int team) : Figury(x, y, team, 1) {}
//};
//
//class Hetman : public Figury
//{
//public:
//	Hetman(int x, int y, int team) : Figury(x, y, team, 2) {}
//};
//
//class Wieza : public Figury
//{
//public:
//	Wieza(int x, int y, int team) : Figury(x, y, team, 3) {}
//};
//
//class Goniec : public Figury
//{
//public:
//	Goniec(int x, int y, int team) : Figury(x, y, team, 4) {}
//};
//
//class Skoczek : public Figury
//{
//public:
//	Skoczek(int x, int y, int team) : Figury(x, y, team, 5) {}
//};
//
//class Pionek : public Figury
//{
//public:
//	Pionek(int x, int y, int team) : Figury(x, y, team, 6) {}
//};


#endif /* FIGURY_H_ */

#include <iostream>
#include <vector>
#include "Figury/Figury.h"
#include "plansza8x8/Plansza.h"

//makrodef testowe
#define XX 5
#define YY 8
#define TEAM 0


using std::cout;
using std::endl;

int main()
{
	Plansza plansza1(8, 8);
	int i, j;
	plansza1.set_object(XX,YY,TEAM,Pionek);
	i = plansza1.get_object(XX,YY).get_possible_move();
	j = plansza1.get_object(XX,YY).get_elongation_move(Gora);
	cout << endl << "Ruch: "<< i << "\nMax d³. ruchu: "<< j << endl;
	return 0;
}
//ok


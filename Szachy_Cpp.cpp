#include <iostream>
#include <vector>
#include "Figury/Figury.h"
#include "plansza/Plansza.h"
#include "plansza/8x8/Plansza8x8.h"

//makrodef testowe
#define XX 5
#define YY 1
#define TEAM 0


using std::cout;
using std::endl;

int main()
{
	Plansza plansza1(8, 8);
	Plansza8x8 init(plansza1);		//te dwie linie to utworzenie planszy 8x8 i ustawienie figur


	int i, n;
	cout << endl << "Roszada 1: "<< plansza1.get_object(XX, YY).get_castling() << endl;
	plansza1.set_object(2,1,TEAM,0);
	plansza1.set_object(3,1,TEAM,0);
	plansza1.set_object(4,1,TEAM,0);
	cout << endl << "Roszada dluga: "<< plansza1.get_object(XX, YY).get_castling() << endl;
	plansza1.set_object(7,1,TEAM,0);
	plansza1.set_object(6,1,TEAM,0);
	plansza1.set_object(2,1,TEAM,2);
	cout << endl << "Roszada krotka: "<< plansza1.get_object(XX, YY).get_castling() << endl;
	plansza1.set_object(2,1,TEAM,0);
	cout << endl << "Roszady obie: "<< plansza1.get_object(XX, YY).get_castling() << endl;

	i = plansza1.get_object(XX,YY).get_possible_move();
	cout << endl << "Ruch: "<< i << endl;

	if(plansza1.get_object(XX,YY).get_type()!=Skoczek)
	{
		n = plansza1.get_object(XX,YY).get_elongation_move(7);
		cout<< n << " ";
		n = plansza1.get_object(XX,YY).get_elongation_move(0);
		cout<< n << " ";
		n = plansza1.get_object(XX,YY).get_elongation_move(1);
		cout<< n << "\n";

		n = plansza1.get_object(XX,YY).get_elongation_move(6);
		cout<< n << " ";
		cout<< " " << " ";
		n = plansza1.get_object(XX,YY).get_elongation_move(2);
		cout<< n << "\n";

		n = plansza1.get_object(XX,YY).get_elongation_move(5);
		cout<< n << " ";
		n = plansza1.get_object(XX,YY).get_elongation_move(4);
		cout<< n << " ";
		n = plansza1.get_object(XX,YY).get_elongation_move(3);
		cout<< n << "\n";
	}
	else
	{
		n = plansza1.get_object(XX,YY).get_elongation_move(0);
		cout<< " " << n << " ";
		n = plansza1.get_object(XX,YY).get_elongation_move(1);
		cout<< n << "\n";
		n = plansza1.get_object(XX,YY).get_elongation_move(7);
		cout<< n << "   ";
		n = plansza1.get_object(XX,YY).get_elongation_move(2);
		cout<< n << "\n";
		n = plansza1.get_object(XX,YY).get_elongation_move(6);
		cout<< n << "   ";
		n = plansza1.get_object(XX,YY).get_elongation_move(3);
		cout<< n << "\n";
		n = plansza1.get_object(XX,YY).get_elongation_move(5);
		cout<< " " << n << " ";
		n = plansza1.get_object(XX,YY).get_elongation_move(4);
		cout<< n << "\n";
	}



	return 0;
}
//ok


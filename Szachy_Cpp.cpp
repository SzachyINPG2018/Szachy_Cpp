#include <iostream>
#include <vector>

#include <windows.h>

#include "Figury/Figury.h"
#include "plansza/Plansza.h"
#include "plansza/8x8/Plansza8x8.h"

//makrodef testowe
#define XX 5
#define YY 1
#define TEAM 0


using std::cout;
using std::cin;
using std::endl;

int main()
{
	Plansza plansza1(8, 8);
	Plansza8x8 init(plansza1);		//te dwie linie to utworzenie planszy 8x8 i ustawienie figur
	int i, n;
	int choice=0;

	cout <<	"----------------------" << endl;
	cout << "------- SZACHY -------" << endl;
	cout <<	"----------------------" << endl;
	cout <<	"Wybor opcji: ---------" << endl;
	cout <<	"1. Szachy stdandard --" << endl;
	cout <<	"2. Szachy 80 pol -----" << endl;
	cout <<	"3. Szachy 100 pol ----" << endl;
	cout <<	"----------------------" << endl;
	cout <<	"9. Wersja gry --------\n" << endl;


	/* TYLKO TESTY TYLKO TESTY
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

	if(plansza1.get_object(XX,YY).get_type()!=Skoczek &&
			plansza1.get_object(XX,YY).get_type()!=Arcybiskup &&
			plansza1.get_object(XX,YY).get_type()!=Kanclerz)
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
	else	if(plansza1.get_object(XX,YY).get_type()==Arcybiskup)
			{
				n = plansza1.get_object(XX,YY).get_elongation_move(0);
				cout<< "  " << n << " ";
				n = plansza1.get_object(XX,YY).get_elongation_move(1);
				cout<< n << "\n ";
				n = plansza1.get_object(XX,YY).get_elongation_move(7);
				cout<< n ;
				n = plansza1.get_object(XX,YY).get_elongation_move(11);
				cout<< n << " ";
				n = plansza1.get_object(XX,YY).get_elongation_move(8);
				cout<< n << "";
				n = plansza1.get_object(XX,YY).get_elongation_move(2);
				cout<< n << "\n   x\n ";
				n = plansza1.get_object(XX,YY).get_elongation_move(6);
				cout<< n;
				n = plansza1.get_object(XX,YY).get_elongation_move(10);
				cout<< n << " ";
				n = plansza1.get_object(XX,YY).get_elongation_move(9);
				cout<< n << "";
				n = plansza1.get_object(XX,YY).get_elongation_move(3);
				cout<< n << "\n ";
				n = plansza1.get_object(XX,YY).get_elongation_move(5);
				cout<< " " << n << " ";
				n = plansza1.get_object(XX,YY).get_elongation_move(4);
				cout<< n << "\n";
			}
	else 	if(plansza1.get_object(XX,YY).get_type()==Kanclerz)
			{
				n = plansza1.get_object(XX,YY).get_elongation_move(0);
				cout<< "  " << n << " ";
				n = plansza1.get_object(XX,YY).get_elongation_move(1);
				cout<< n << "\n ";
				n = plansza1.get_object(XX,YY).get_elongation_move(7);
				cout<< n << " ";
				n = plansza1.get_object(XX,YY).get_elongation_move(8);
				cout<< n << " ";
				n = plansza1.get_object(XX,YY).get_elongation_move(2);
				cout<< n << "\n  ";
				n = plansza1.get_object(XX,YY).get_elongation_move(11);
				cout<< n << "x";
				n = plansza1.get_object(XX,YY).get_elongation_move(9);
				cout<< n << "\n ";
				n = plansza1.get_object(XX,YY).get_elongation_move(6);
				cout<< n << " ";
				n = plansza1.get_object(XX,YY).get_elongation_move(10);
				cout<< n << " ";


				n = plansza1.get_object(XX,YY).get_elongation_move(3);
				cout<< n << "\n ";
				n = plansza1.get_object(XX,YY).get_elongation_move(5);
				cout<< " " << n << " ";
				n = plansza1.get_object(XX,YY).get_elongation_move(4);
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
		cout<< n << "\n  x\n";
		n = plansza1.get_object(XX,YY).get_elongation_move(6);
		cout<< n << "   ";
		n = plansza1.get_object(XX,YY).get_elongation_move(3);
		cout<< n << "\n";
		n = plansza1.get_object(XX,YY).get_elongation_move(5);
		cout<< " " << n << " ";
		n = plansza1.get_object(XX,YY).get_elongation_move(4);
		cout<< n << "\n";
	}


*/

	system("PAUSE");
	return 0;
}
//ok


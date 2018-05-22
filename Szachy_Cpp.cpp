#include <iostream>
#include <vector>
#include <string>

#include <windows.h>

#include "Figury/Figury.h"
#include "plansza/Plansza.h"
#include "plansza/8x8/Plansza8x8.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;


void SetColor(string number);

int main()
{
	Plansza plansza1(8, 8);
	Plansza8x8 init(plansza1);		//te dwie linie to utworzenie planszy 8x8 i ustawienie figur
	//int i, n;
	int choice=1;
	string move;
	int who_s=0;
	int x=0, y=0, type=0, xt=0, yt=0;
	vector<string> team_m = {"Biale", "Czarne"};
/*
	cout <<	"------------------------" << endl;
	cout << "-------- SZACHY --------" << endl;
	cout <<	"------------------------" << endl;
	cout <<	"Wybor opcji: -----------" << endl;
	cout <<	"1. Szachy standardowe --" << endl;
	cout <<	"2. Szachy 80 pol -------" << endl;
	cout <<	"3. Szachy 100 pol ------" << endl;
	cout <<	"------------------------" << endl;
	cout <<	"9. Wersja gry ----------\n" << endl;

	cin >> choice;
*/
	if(choice == 1)
	{
	//	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		cout << "Biale rozpoczynaja rozgrywke\n\n";
		while(1)
		{
			cout << "\n";
			move = "";
			cout <<"\t"<<"CZARNE"<< "\n"; 
			plansza1.draw(); //metoda ktÃ³ra rysuje plansze
			cout <<"\t"<<"BIALE"<< "\n";
Ruch: 		cout << "\n" << team_m[who_s]<<" podaj ruch: ";
			cin >> move; //ruch np A1WA3

			if(move == "exit") return 0; //wyjscie z gry
			if(move[5] != '\0' || move[0] == '\0' || move[1] == '\0' ||
				move[2] == '\0' || move[3] == '\0' || move[4] == '\0' )
			{
Ruch1:			cout << "Zle wprowadzony ruch\n";
				goto Ruch;
			}
			if(move[0]<'A') x = (move[0]-'0');
			else if(move[0]<'a') x = (move[0]-'A'+1);
			else 			x = (move[0]-'a'+1);

			y = ( move[1] - '0' );

			type = 0;
			if(move[2] == 'K' || move[2] == 'k')	type = Krol;
			if(move[2] == 'H' || move[2] == 'h')	type = Hetman;
			if(move[2] == 'W' || move[2] == 'w')	type = Wieza;
			if(move[2] == 'G' || move[2] == 'g')	type = Goniec;
			if(move[2] == 'S' || move[2] == 's')	type = Skoczek;
			if(move[2] == 'P' || move[2] == 'p')	type = Pionek;
			if(move[2] == 'A' || move[2] == 'a')	type = Arcybiskup;
			if(move[2] == 'N' || move[2] == 'n')	type = Kanclerz;

			if(plansza1.get_object(x,y).get_type() != type)	goto Ruch1;

			if(move[3]<'A') xt = (move[3]-'0');
			else if(move[3]<'a') xt = (move[3]-'A'+1);
			else 			xt = (move[3]-'a'+1);

			yt = ( move[4] - '0' );

		//	cout << "X: "  << x  << " Y: "  << y  << " Type: " << type;
		//	cout << " Xt: " << xt << " Yt: " << yt << endl;
		//tylko debugowanie

			if(plansza1.get_object(x,y).get_team() != who_s) goto Ruch1;
			if(!plansza1.make_move(x, y, xt, yt)) goto Ruch1;

			if(who_s == 0)
				{
					who_s = 1;
					continue;
				}
			if(who_s == 1) who_s = 0;
		}
	}



	system("PAUSE");
	return 0;
}






void SetColor(string number)
{

    /* Wybierz kolor wed³ug poni¿szego kodu:
    *
    * Pierwszy znak odpowiada za kolor t³a pod tekstem, drugi za kolor tekstu
    *
    * Kolory podstawowe
    *
    * 0 - czerwony
    * 1 - zielony
    * 2 - niebieski
    * 3 - czerwony + zielony = pomarañczowy
    * 4 - czerwony + niebieski = fioletowy
    * 5 - zielony + niebieski = ¿ó³ty
    * 6 - czerwony + zielony + niebieski = bia³y
    *
    * Kolory jaskrawe
    *
    * 7 - czerwony jaskrawy
    * 8 - zielony jaskrawy
    * 9 - niebieski jaskrawy
    * A - czerwony jaskrawy + zielony jaskrawy = pomarañczowy
    * B - czerwony jaskrawy + niebieski jasrkawy = fioletowy jaskrawy
    * C - zielony jaskrawy + niebieski jaskrawy = ¿ó³ty jaskrawy
    * D - czerwony jaskrawy + zielony jaskrawy + niebieski jaskrawy = bia³y jaskrawy

    */

    int color = 0;
    HANDLE hOut;

    switch (number[0]) {

    case '0':

        color += 0x40;
        break;

    case '1':

        color += 0x20;
        break;

    case '2':

        color += 0x10;
        break;

    case '3':

        color += 0x60;
        break;

    case '4':

        color += 0x50;
        break;

    case '5':

        color += 0x30;
        break;

    case '6':

        color += 0x70;
        break;

    case '7':

        color += 0xC0;
        break;

    case '8':

        color += 0xA0;
        break;

    case '9':

        color += 0x90;
        break;

    case 'A':

        color += 0xE0;
        break;

    case 'B':

        color += 0xD0;
        break;

    case 'C':

        color += 0xB0;
        break;

    case 'D':

        color += 0xF0;
        break;

    }

    switch (number[1]) {

    case '0':

        color += 0x4;
        break;

    case '1':

        color += 0x2;
        break;

    case '2':

        color += 0x1;
        break;

    case '3':

        color += 0x6;
        break;

    case '4':

        color += 0x5;
        break;

    case '5':

        color += 0x3;
        break;

    case '6':

        color += 0x7;
        break;

    case '7':

        color += 0xC;
        break;

    case '8':

        color += 0xA;
        break;

    case '9':

        color += 0x9;
        break;

    case 'A':

        color += 0xE;
        break;

    case 'B':

        color += 0xD;
        break;

    case 'C':

        color += 0xB;
        break;

    case 'D':

        color += 0xF;
        break;

    }

    SetConsoleTextAttribute(hOut, color);

}





//ok

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

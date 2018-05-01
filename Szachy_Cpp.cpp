#include <iostream>
#include <vector>
#include "Figury/Figury.h"
#include "plansza8x8/Plansza.h"

using std::cout;
using std::endl;

int main()
{
	Plansza plansza1(8);
	int i=0;
	plansza1.set_object(1,1,0,Skoczek);
	i = plansza1.get_object(1,1).get_possible_move();
	cout << endl << " Typ figury na polu "<< i << endl;
	return 0;
}
//ok


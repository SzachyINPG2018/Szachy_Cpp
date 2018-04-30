#include <iostream>
#include "Figury/Figury.h"
#include "plansza8x8/Plansza.h"

int main()
{
	Plansza plansza1;
	int i=0;
	plansza1.set_object(1,1,0,Skoczek);
	i = plansza1.get_object(1,1).get_probable_move();
	std::cout << std::endl << " Hello WORLD "<< i << std::endl;
	return 0;
}
//ok

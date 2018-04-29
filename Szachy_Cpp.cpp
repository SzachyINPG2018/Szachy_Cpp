#include <iostream>
#include "Figury/Figury.h"
#include "plansza8x8/Plansza.h"

int main()
{
	Plansza plansza1;
	int i;
	//plansza1.set_object(1,1,0,1);
	i = plansza1.get_object(1,1).get_possible_move();
	std::cout << " Hello WORLD "<< i << std::endl;
	return 0;
}
//ok

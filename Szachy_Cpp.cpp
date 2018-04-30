#include <iostream>
#include "Figury/Figury.h"
#include "plansza8x8/Plansza.h"

void itob(unsigned a)
{
  for(unsigned m = 256; m > 0; m >>= 1) std::cout << ((a & m) ? "1" : "0");
}

int main()
{
	Plansza plansza1;
	int i=0;
	plansza1.set_object(1,1,0,Pionek);
	i = plansza1.get_object(1,1).get_possible_move();
	itob(i);
	std::cout << std::endl << " Hello WORLD "<< i << std::endl;
	return 0;
}
//ok

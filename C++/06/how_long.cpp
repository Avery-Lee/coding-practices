#include <iostream>

double how_long(double n)
{
	double counter = 1;
	while (n / 10 > 10)
	{
		n /= 10;
		++counter;
	}
	return counter;
}
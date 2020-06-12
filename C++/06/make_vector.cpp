#include <iostream>
#include <vector>
#include "Sequence.h"

void make_vector(Sequence& s, const double& in)
{
	for (double i = 1; i != in+1; ++i)
	{
		s.n.push_back(i);
		s.n_square.push_back(i * i);
	}
}
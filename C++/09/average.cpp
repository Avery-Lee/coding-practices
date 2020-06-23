#include "average.h"

using std::vector;

//average.h

double average(const vector<double>& v)
{
	return accumulate(v.begin(), v.end(), 0.0) / v.size();
}
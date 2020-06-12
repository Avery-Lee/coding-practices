#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include "Sequence.h"
#include "make_vector.h"
#include "how_long.h"

using std::cout;  using std::vector;   using std::string;    using std::streamsize;
using std::cin;   using std::endl;     using std::setw;


int main()
{
	Sequence Sequence;

	cout << "Please enter the maximum value for the square number : ";

	double input_number;
	cin >> input_number;

	make_vector(Sequence, input_number);

	unsigned int maxlen = how_long(Sequence.n[Sequence.n.size() - 1]);

	cout << endl;

	for (vector<double>::size_type i = 0; i != Sequence.n.size(); ++i)
	{
		cout << setw(maxlen + how_long(Sequence.n[Sequence.n.size() - 1])) 
			 << Sequence.n[i] 
			 << string(maxlen + 1 - how_long(Sequence.n[i]), ' ') 
			 << Sequence.n_square[i] 
			 << endl;
	}

	return 0;
}

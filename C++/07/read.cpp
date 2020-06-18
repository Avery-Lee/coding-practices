#include "read.h"

using std::istream;    using std::vector;    using std::string;

istream& read(istream& in, vector<string>& vec)
{
	if (in) {
		vec.clear();
		string input;

		while (in)
		{
			in >> input;
			vec.push_back(input);
		}
		in.clear();
	}
	return in;
}
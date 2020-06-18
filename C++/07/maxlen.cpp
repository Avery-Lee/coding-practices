#include "maxlen.h"

using std::vector;    using std::max;    using std::string;

double maxlen(const vector<string>& vec)
{
	string::size_type size = 0;
	for (vector<string>::const_iterator iter = vec.begin(); iter != vec.end(); ++iter)
	{
		size = max(size, iter->size());
	}
	return size;
}
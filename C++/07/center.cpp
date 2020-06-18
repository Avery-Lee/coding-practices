#include "center.h"

using std::vector;    using std::string;

vector<string> center(const vector<string>& cnt)
{
	vector<string> result;

	for (vector<string>::const_iterator iter = cnt.begin(); iter != cnt.end(); ++iter)
	{
		result.push_back(string(maxlen(cnt), ' ') + *iter + string(maxlen(cnt), ' '));
	}
	return result;
}

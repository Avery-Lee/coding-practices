#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include "read.h"
#include "center.h"

using std::vector;    using std::string;
using std::cout;      using std::endl;
using std::cin;

int main() 
{
	vector<string> record;

	read(cin, record);

	vector<string> result = center(record);

	for (vector<string>::const_iterator iter = result.begin(); iter != result.end(); ++iter)
	{
		cout << *iter << endl;
	}

	return 0;
}
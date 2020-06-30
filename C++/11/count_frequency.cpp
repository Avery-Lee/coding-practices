#include <string>
#include <map>
#include <iostream>
#include <vector>

using std::string;
using std::map;
using std::cin;
using std::cout;
using std::vector;
using std::endl;

int main()
{
	string s;

	map<string, int> counters;
	map<int, vector<string> > reversed_counters;

	while (cin >> s)
		++counters[s];

	for (map<string, int>::const_iterator it = counters.begin();
		it != counters.end(); ++it)
		reversed_counters[it->second].push_back(it->first);

	for (map<int, vector<string> >::const_iterator it = reversed_counters.begin(); it != reversed_counters.end(); ++it)
	{
		cout << "\nShowed : " << it->first << endl;
		
		for (vector<string>::const_iterator it_v = it->second.begin(); it_v != it->second.end(); ++it_v)
			cout << *it_v << endl;
	}
	return 0;
}
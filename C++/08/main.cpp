#include <vector>
#include <cctype>
#include <string>
#include <iostream>

using std::istream;    using std::vector;
using std::string;     using std::cin;
using std::getline;    using std::cout;    using std::endl;


vector<string> split(const string& s, vector<string>& upper, vector<string>& lower)
{
	typedef string::size_type string_size;
	string_size i = 0;

	while (i != s.size()) {
		bool is_upper = false;
		bool value = false;

		while (i != s.size() && isspace(s[i])) 
			++i;
		
		string_size j = i;

		while (j != s.size() && !isspace(s[j]))
		{
		    is_upper = isupper(s[j]);
		    value = is_upper or value;
		    j++;
	    }
		if (i != j) {
			if (value) {
				upper.push_back(s.substr(i, j - i));
			}
			else if (!value) {
				lower.push_back(s.substr(i, j - i));
			}
			i = j;
		}
	}
	return lower;
}

int main() 
{
	vector<string> upper, lower;
	string s;

	while (cin)
	{
		cin >> s;

		lower = split(s, upper, lower);
	}
	
	cout << endl;

	for (vector<string>::size_type i = 0; i != lower.size(); ++i)
		cout << lower[i] << " ";

	cout << endl << endl;

	for (vector<string>::size_type j = 0; j != upper.size(); ++j)
		cout << upper[j] << " ";
	
	return 0;
}
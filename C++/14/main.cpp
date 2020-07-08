#include <stdexcept>
#include <iostream>
#include "String_list.h"

using std::string;
using std::cout;
using std::endl;
using std::exception;

int main()
{
	String_list str_list;
	try
	{
		str_list.push_back("Hello ");
		str_list.push_back("and ");
		str_list.push_back("hi");
		str_list.push_back("world");
		str_list.push_back("!");
		str_list.insert(3, ", ");
		str_list.remove(0);
		str_list.remove(0);
		for (String_list::iterator iter = str_list.begin(); iter != str_list.end(); ++iter)
			cout << *iter;
		cout << endl;
	}
	catch (const exception& e)
	{
		cout << e.what();
	}

}

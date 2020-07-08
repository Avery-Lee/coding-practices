#include "String_list.h"

using std::string;
using std::cout;
using std::endl;
using std::domain_error;



String_list::String_list(const String_list& src)
{
	*this = src;
	s_list = new string[max_size];

	for (string::size_type i = 0; i < size; ++i)
		s_list[i] = src.s_list[i];
}

String_list::~String_list()
{
	delete[] s_list;
}

void String_list::resize() 
{
	++max_size;

	string* copy = new string[max_size];

	for (string::size_type i = 0; i < size; ++i)
		copy[i] = s_list[i];

	delete[] s_list;

	s_list = copy;
}


void String_list::push_back(string str)
{
	if (size == max_size)
		resize();

	string* copy = new string[max_size];

	s_list[size++] = str;
}


void String_list::remove(size_t index)
{
	if (index == size)
		throw domain_error("Index out of range!");

	string* copy = new string[max_size - 1];

	for (string::size_type i = 0; i < index; ++i)
		copy[i] = s_list[i];

	++index;

	for (string::size_type i = index; i < size; ++i)
		copy[i-1] = s_list[i];

	delete[] s_list;

	s_list = copy;

	--size;
}

void String_list::insert(size_t index ,string str)
{
	if (index == size)
		throw domain_error("Index out of range!");

	if (size == max_size)
		resize();

	string* copy = new string[max_size];

	for (string::size_type i = 0; i < index; ++i)
		copy[i] = s_list[i];

	copy[index++] = str;

	for (string::size_type i = index; i <= size; ++i)
		copy[i] = s_list[i-1];

	delete[] s_list;

	s_list = copy;

	++size;
}



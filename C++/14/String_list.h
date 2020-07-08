#ifndef GUARD_String_list_h
#define GUARD_String_list_h

#include <string>
#include <iostream>
#include <stdexcept>

class String_list
{
public:
	typedef std::string* iterator;


	String_list() : s_list(new std::string[1]), size(0), max_size(1) {};
	String_list(const String_list& src);
	~String_list();

	void resize();
	void push_back(std::string);
	void insert(size_t index, std::string);
	void remove(size_t index);


	std::string* begin() { return s_list; }
	std::string* end() { return s_list + size; };

private:
	std::string* s_list;
	std::string::size_type size;
	std::string::size_type max_size;
};

#endif // !GUARD_String_list_h

#ifndef GUARD_Student_info_h
#define GUARD_Student_info_h

#include <vector>
#include <string>

struct Student_info
{
	std::string name;
	double midterm, final;
	std::vector<double> homework;
};

bool compare(const Student_info& x, const Student_info& y);

#endif

#ifndef GUARD_Student_info_h
#define GUARD_Student_info_h

#include <string>
#include <vector>
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <map>

class Student_info
{
public:
	Student_info();
	Student_info(std::istream&);
	std::string name() const { return n; }
	std::string result() const { return p_or_f; }
	bool vaild() const { return !homework.empty(); }

	std::istream& read_hw(std::istream& is, std::vector<double>& hw);
	std::istream& read(std::istream&);

	double grade() const;
	bool is_pass() const;


private:
	std::string n, p_or_f;
	double midterm, final, g;
	std::vector<double> homework;
};

bool compare(const Student_info& x, const Student_info& y);

template<class T>
T median(std::vector<T> vec);

double grade(double midterm, double final, const std::vector<double>& hw);

double grade(double midterm, double final, double homework);

#endif
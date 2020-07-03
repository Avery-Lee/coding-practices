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
	bool vaild() const { return !homework.empty(); }

	std::istream& read(std::istream&);

	double grade() const;
	bool is_pass() const { return grade() >= 60; }


private:
	std::string n;
	double midterm, final, g;
	std::vector<double> homework;
	std::map<char, double> pf_students;
};

bool compare(const Student_info& x, const Student_info& y);

std::istream& read_hw(std::istream& is, std::vector<double>& hw);

template<class T>
T median(vector<T> vec);

double grade(double midterm, double final, const std::vector<double>& hw);

double grade(double midterm, double final, double homework);

#endif
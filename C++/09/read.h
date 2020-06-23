#ifndef GUARD_read_h
#define GUARD_read_h

#include <iostream>
#include <vector>
#include "Student_info.h"

std::istream& read_hw(std::istream& in, std::vector<double>& hw);

std::istream& read(std::istream& is, Student_info& s);

#endif


#ifndef GUARD_grade_h
#define GUARD_grade_h

#include <vector>
#include <stdexcept>
#include "Student_info.h"
#include "median.h"
#include "average.h"

double grade(double midterm, double final, double homework);

double grade(double midterm, double final, const std::vector<double>& hw);

double grade(const Student_info& s);

bool fgrade(const Student_info& s);

bool pgrade(const Student_info& s);

double grade_aux(const Student_info& s);

double average_grade(const Student_info& s);

#endif

#ifndef GUARD_analysis_h
#define GUARD_analysis_h

#include <vector>
#include <algorithm>
#include <ios>
#include <iostream>
#include <string>

#include "Student_info.h"
#include "median.h"
#include "grade.h"

double analysis(const std::vector<Student_info>& students, double method(const Student_info&));

void write_analysis(std::ostream& out, const std::string& name, double method(const Student_info&), const std::vector<Student_info>& did, const std::vector<Student_info>& didnt);

#endif

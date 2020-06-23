#ifndef GUARD_median_h
#define GUARD_median_h

#include <vector>
#include <algorithm>
#include <stdexcept>
#include "Student_info.h"
#include "grade.h"

double median(std::vector<double> vec);

double optimistic_median(const Student_info& s);

#endif

#include "grade.h"

using std::string;          using std::vector;                using std::domain_error;
//grade.h

double grade(double midterm, double final, double homework)
{
	return midterm * 0.2 + final * 0.4 + homework * 0.4;
}

double grade(double midterm, double final, const vector<double>& hw)
{
	if (hw.empty())
		throw domain_error("student has done no homework");
	return grade(midterm, final, median(hw));
}


double grade(const Student_info& s)
{
	return grade(s.midterm, s.final, s.homework);
}

bool fgrade(const Student_info& s)
{
	return grade(s) < 60;
}

bool pgrade(const Student_info& s)
{
	return !fgrade(s);
}

double grade_aux(const Student_info& s)
{
	try {
		return grade(s);
	}
	catch (domain_error) {
		return grade(s.midterm, s.final, 0);
	}
}

double average_grade(const Student_info& s)
{
	return grade(s.midterm, s.final, average(s.homework));
}
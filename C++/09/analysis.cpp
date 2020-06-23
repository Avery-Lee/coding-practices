#include "analysis.h"
 
using std::string;              using std::vector;                using std::endl;
using std::transform;           using std::back_inserter;         using std::ostream;                 


//analysis.h

double analysis(const vector<Student_info>& students, double method(const Student_info&))
{
	vector<double> grades;
	transform(students.begin(), students.end(), back_inserter(grades), method);
	return median(grades);
}

void write_analysis(ostream& out, const string& name, double method(const Student_info&), const vector<Student_info>& did, const vector<Student_info>& didnt)
{
	out << name << ": did = " << analysis(did, method) << ", didnt = " << analysis(didnt, method) << endl;
}
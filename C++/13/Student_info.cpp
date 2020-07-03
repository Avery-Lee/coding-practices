#include "Student_info.h"

using std::istream;
using std::vector;
using std::domain_error;
using std::ostream;
using std::string;
using std::map;
using std::inserter;
using std::make_pair;
using std::remove_copy_if;

bool compare(const Student_info& x, const Student_info& y)
{
	return x.name() < y.name();
}

template<class T>
T median(vector<T> vec)
{
	typedef typename vector<T>::size_type vec_sz;

	vec_sz size = vec.size();
	if (size == 0)
		throw domain_error("median of empty vector");

	sort(vec.begin(), vec.end());
	vec_sz mid = size / 2;

	return size % 2 == 0 ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid];
}

double grade(double midterm, double final, const std::vector<double>& hw)
{
	if (hw.size() == 0)
		throw domain_error("Student has done no homework");
	return grade(midterm, final, median(hw));
}

double grade(double midterm, double final, double homework)
{
	return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

istream& Student_info::read_hw(istream& is, vector<double>& hw)
{
	if (is)
	{
		is.clear();

		double x;
		while (is >> x)
			hw.push_back(x);

		is.clear();
	}

	return is;
}


istream& Student_info::read(istream& in)
{
	in >> n >> midterm >> final;
	read_hw(in, homework);

	g = ::grade(midterm, final, homework);

	if (is_pass())
		p_or_f = "Pass";
	else if (!is_pass())
		p_or_f = "Fail";
	return in;
}

double Student_info::grade() const
{
	return ::grade(midterm, final, homework);
}

Student_info::Student_info() : midterm(0), final(0), g(0) { }

Student_info::Student_info(istream& is) { read(is); }

bool Student_info::is_pass() const { return g >= 60; }
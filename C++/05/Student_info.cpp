#include "Student_info.h"

using std::istream;  using std::vector; using std::cout; using std::endl;

bool compare(const Student_info& x, const Student_info& y)
{
	return x.name < y.name;
}

istream& read(istream& is, Student_info& s)
{
	cout << endl << "Please enter a name, a midterm score and a final score. If it ends, type Ctrl+z and Enter to stop the process." << endl;
	is >> s.name >> s.midterm >> s.final;
	read_hw(is, s.homework);
	return is;
}

istream& read_hw(istream& in, vector<double>& hw)
{
	if (in) {
		hw.clear();

		double x;
		cout << endl << "Please enter homework scores. If it ends, type Ctrl+z and Enter to stop the process." << endl;
		while (in >> x)
			hw.push_back(x);

		in.clear();
	}
	return in;
}
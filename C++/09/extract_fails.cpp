#include "extract_fails.h"

using std::vector;            using std::remove_if;             
using std::remove_copy_if;    using std::copy;           

//extract_fails

vector<Student_info> extract_fails(vector<Student_info>& students)
{
	vector<Student_info> fail;
	vector<Student_info>::iterator iter = remove_if(students.begin(), students.end(), fgrade);

	copy(iter, students.end(), fail);

	students.erase(iter, students.end());

	return fail;
}
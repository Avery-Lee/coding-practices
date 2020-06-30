#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include "split.h"
#include "util.h"

using std::vector;
using std::string;
using std::map;
using std::istream;
using std::logic_error;
using std::cin;
using std::cout;
using std::endl;
using std::domain_error;

int main() {
	vector<string> sentence = gen_sentence(read_grammar(cin));
	vector<string>::const_iterator it = sentence.begin();

	if (!sentence.empty()) {
		cout << *it;
		++it;
	}

	while (it != sentence.end()) {
		cout << " " << *it;
		++it;
	}
	cout << endl;
	return 0;
}
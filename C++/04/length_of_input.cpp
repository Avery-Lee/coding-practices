#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cout;   using std::cin;    using std::endl;
using std::string; using std::vector; using std::sort;

int main()
{
    vector<double> counter;
    string word;

    cout << "Please enter values : " << endl;

    while (cin >> word)
    {
        counter.push_back(word.size());
    }
    if (counter.size() < 2)
    {
        cout << "Please enter vaild values!" << endl;
        return 1;
    }
    sort(counter.begin(), counter.end());

    cout << "The minimum length of input : " << counter[0] << endl
        << "The maximum length of input : " << counter[counter.size()-1] << endl;
    
    return 0;
}
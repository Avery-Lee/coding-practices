#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cin;    using std::sort;
using std::string; using std::endl;
using std::cout;   using std::vector;

int main()
{
    cout << "Please enter values. "
            "followed by end-of-file : ";
    vector<double> sequence;
    double x;
    
    while (cin >> x)
    {
        sequence.push_back(x);
    }
    
    vector<double>::size_type sequence_size = sequence.size();
    if (sequence_size < 4)
    {
        cout << "Values are too little!" << endl;
        return 1;
    }
    
    sort(sequence.begin(), sequence.end());

    for (int n = 1; n != 4; ++n)
    {
        double quartile_point = (sequence_size / 4) * n;
        double quartile = sequence_size % 2 == 0 ? (sequence[quartile_point] + sequence[quartile_point - 1]) / 2
                                                : sequence[quartile_point];
        cout << "The quartile " << n << " is : " << quartile << endl;
        }
    return 0;
}
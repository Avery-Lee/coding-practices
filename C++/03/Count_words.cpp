#include <iostream>
#include <vector>
#include <string>

using std::cout;   using std::cin;    using std::endl;
using std::string; using std::vector;

int main()
{
    typedef vector<string>::size_type vec_sz;
    
    vector<string> words;
    vector<int> counter;

    cout << "Please enter some words. Followed by end-of-file :  " << endl;
    string word;
    while (cin >> word)
    {
        bool is_in = false;
        for (vec_sz i = 0; i != words.size(); ++i)
        {
            if (word == words[i])
            {
                ++counter[i];
                is_in = true;
            }
        }
        
        if (is_in == false)
        {
            words.push_back(word);
            counter.push_back(1);
        }
    }
    if (word.size() < 1)
    {
        cout << "Please enter vaild words." << endl;
        return 1;
    } 
    else
    {
        for (vec_sz j = 0; j != word.size(); ++j)
        cout << words[j] << " was typed " << counter[j] << " times." << endl;
    }
    return 0;
}
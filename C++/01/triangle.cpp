#include <iostream>
#include <string>
#include <windows.h>

using std::cout; using std::string;
using std::cin;  using std::endl;

int main()
    {
        cout << "Please enter the size of a triangle : ";
    int triangle;
    cin >> triangle;
    cout << endl;

    int spaces = triangle;
    int sleep_time = 300 / triangle;

    //triangle
    for(int n = 1; n != triangle + 1; ++n){
        for(int space = spaces - 1; space != 0; --space){
            cout << " ";
        }
        for(int m = 2*n-1; m != 0; --m){
            Sleep(sleep_time);
            cout << "*";
        }
        --spaces;
        cout << endl;
        }
    return 0;
    }
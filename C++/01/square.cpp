#include <iostream>
#include <string>
#include <windows.h>

using std::cout; using std::string;
using std::cin;  using std::endl;

int main()
    //square
    {
    cout << "Please enter the size of a square : ";
    int size_of_square;
    cin >> size_of_square;
    cout << endl;

    int sleep_time = 10;
    if(size_of_square < 10){
        sleep_time *= 10;
        }
    else if(size_of_square < 20){
        sleep_time *= 5;
    }
    else if(size_of_square < 30){
        sleep_time *= 3;
    }


    for(int y = 0; y != size_of_square; ++y){
        for(int x = 0; x != size_of_square; ++x){
            Sleep(sleep_time);
            cout << "* ";
        }
        cout << endl;
        }
    return 0;
    }
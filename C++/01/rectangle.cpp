#include <iostream>
#include <string>
#include <windows.h>

using std::cout; using std::string;
using std::cin;  using std::endl;

int main()
    //rectangle
    {
    cout << "Please enter the height of a rectangle : ";
    int height;
    cin >> height;
    
    cout << "Please enter the weith of a rectangle : ";
    int weith;
    cin >> weith;

    cout << endl;

    int sleep_time = 10;
    if(weith + height < 10){
        sleep_time *= 10;
        }
    else if(weith + height < 20){
        sleep_time *= 5;
    }
    else if(weith + height < 30){
        sleep_time *= 3;
    }

    for(int y = 0; y != height; ++y){
        for(int x = 0; x != weith; ++x){
            Sleep(sleep_time);
            cout << "* ";
        }
        cout << endl;
    }
    return 0;
    }

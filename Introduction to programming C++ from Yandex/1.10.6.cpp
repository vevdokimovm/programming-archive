#include <iostream>

using namespace std;

int main()
{
    string empty_str = "", str = "";
    while (cin >> str)
    {
        if (str.length() > empty_str.length())
            empty_str = str;
    }
    cout << empty_str;
}
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n, count = 0;
    string s;
    getline(cin, s);
    for (auto c : s){
        if (c == 32){
            count++;
        }
    }
    cout << count + 1<< endl;
    return 0;
}

#include <iostream>
using namespace std;
int main(){
    char c = '\0';
    int counter = 0;
    while (cin.get(c)){
        if (c == ' ')
            counter++;
        else
            counter = 0;
        if (counter == 1 || c != ' ')
            cout << c;
    }
}
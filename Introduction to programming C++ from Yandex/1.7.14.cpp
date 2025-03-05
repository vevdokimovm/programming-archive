#include <iostream>

using namespace std;

int main()
{
    unsigned pins = 0, balls = 0;
    cin >> pins >> balls;
    char field[pins];
    for (size_t i = 0; i < pins; ++i)
        field[i] = 'I';
    for (size_t i = 0; i < balls; ++i){
        unsigned start = 0, finish = 0;
        cin >> start >> finish;
        unsigned dif = 1 + finish - start--;
        while (dif--)
            field[start++] = '.';
    }
    for (size_t i = 0; i < pins; ++i)
        cout << field[i];
    return 0;
}
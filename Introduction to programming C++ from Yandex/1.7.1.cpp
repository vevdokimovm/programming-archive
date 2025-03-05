#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector <int> a(n);
    // Считывание
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    // Обработка
    for ( int i = 0; i < n; i++)
    {
        if ( i % 2 == 0)
        {
            cout << a[i] << " ";
        }
    }
    return 0;
}
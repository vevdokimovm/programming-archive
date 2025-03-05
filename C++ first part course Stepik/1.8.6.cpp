#include <iostream>

using namespace std;

int logarithm(int a){
    int number = 1;
    int answer = 0;
    while (number < a)
    {
        number *= 2;
        answer++;
        number > a ? answer-- : 0;
    }
    return answer;
}

int main()
{
    int n = 0;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int a = 0;
        cin >> a;
        cout << logarithm(a) << "\n";
    }
}

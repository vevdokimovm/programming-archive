#include <iostream>

using namespace std;

int main()
{
    int H, M, S, H1, M1, S1;
    cin >> H >> M >> S >> H1 >> M1 >> S1;
    H = H * 3600;
    M = M * 60;
    H1 = H1 * 3600;
    M1 = M1 * 60;
    cout << H1 - H + M1 - M + S1 - S ;
    return 0;
}
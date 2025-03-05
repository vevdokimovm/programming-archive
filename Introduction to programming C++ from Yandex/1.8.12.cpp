#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int n, m, count = 0;
    cin >> n >> m;
    int a[n][m];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            a[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (i % 2 == 0){
                if (j % 2 == 0){
                    count++;
                    a[i][j] = count;
                    cout << setw(4) << a[i][j];
                }
                else {
                    a[i][j] = 0;
                    cout << setw(4) << a[i][j];
                }
            }
            else {
                if (j % 2 == 0){
                    a[i][j] = 0;
                    cout << setw(4) << a[i][j];
                }
                else {
                    count++;
                    a[i][j] = count;
                    cout << setw(4) << a[i][j];
                }
            }
        }
        cout << endl;
    }
    return 0;
}
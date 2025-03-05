#include <iostream>

using namespace std;

int main()
{
    int n, a[10][10], count = 0;
    cin >> n;
    //Чтение
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
     for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (i != j && a[i][j] == a[j][i]){
                count++;
            }
        }
    }
    if (count == n * n - n){
        cout << "YES";
    }
    else {
        cout << "NO";
    }
    return 0;
}
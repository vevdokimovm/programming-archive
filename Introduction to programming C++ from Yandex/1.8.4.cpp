#include <iostream>

using namespace std;

int main()
{
    int n, m, a[100][100];
    cin >> n >> m;
    //Чтение
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    //Обмен столбцов
    int r, k;
    cin >> r >> k;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (k == j){
                int temp;
                temp = a[i][j];
                a[i][j] = a[i][r];
                a[i][r] = temp;
            }
        }
    }
    //Вывод
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
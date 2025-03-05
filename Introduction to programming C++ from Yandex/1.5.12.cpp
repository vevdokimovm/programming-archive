#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int now, count = 1, same = 0;
    cin >> now;
    vector <int> a;
    while (now != 0) {
        if (now == same) {
            count++;
        } else {
            a.push_back(count);
            count = 1;
        }
        same = now;
        cin >> now;
    }
    a.push_back(count);
    int num_max = a[0];
    for (int i = 0; i < (int)a.size(); i++) {
        if (num_max < a[i]){
            num_max = a[i];
        }
    }
    cout << num_max << endl;
    return 0;
}
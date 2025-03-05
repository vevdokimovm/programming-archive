#include <iostream>
using namespace std;

int output(int a, int b){
    return (a + b);
}

int main(){
    int n = 0;
    cin >> n;
    for (int i = 0; i < n; i++){
        int a = 0;
        int b = 0;
        cin >> a >> b;
        cout << output(a, b) << "\n";
    }
}
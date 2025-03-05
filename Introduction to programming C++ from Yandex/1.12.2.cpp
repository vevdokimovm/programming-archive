#include <iostream>
#include <set>
using namespace std;
int main(){
    int size, c, count = 0;
    cin >> size >> c;
    set <int> s;
    for (int i = 0; i < c; i++){
        int y;
        cin >> y;
        s.insert(y);}
    for (auto now : s){
        if (now >= size){
            count++;
            size = now + 3;}}
    cout << count;
}
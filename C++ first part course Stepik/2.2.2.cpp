#include <iostream>

using namespace std;

void reverser(){
    unsigned now = 0;
    cin >> now;
    if (now == 0)
        return;
    reverser();
    cout << now << " ";
}

int main()
{
    reverser();
    return 0;
}
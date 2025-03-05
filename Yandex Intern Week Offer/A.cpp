#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long long int n, m, c2, c5;
    cin >> n >> m >> c2 >> c5;
    
    double cost1 = (double)c2 / 2.0;
    double cost2 = (double)c5 / 5.0;
    
    long long int cost = 0;
    long long int x = 0, y =0;
    
    if (cost1 < cost2) {
        x = ceil((5 * n - m) / 3.0);
        long long int left_ports = m - 2 * x;
        if (left_ports < 5) { x += ceil(left_ports / 2.0); }
        else y = floor((m - 2 * x) / 5.0);
        
        cost = x * c2 + y * c5;
    }
    else { // cost1 >= cost2
        cost = ceil(m / 5.0) * c5;
        long long int ports_used = m / 5;
        
        if (ports_used * 5 != m) {
            long long int left_ports = m - ports_used * 5;
            if (ceil(left_ports / 2.0) * c2 < c5) {
                cost -= c5;
                cost += ceil(left_ports / 2.0) * c2;
            }
        }
    }

    cout << cost; 
    
    return 0;
}
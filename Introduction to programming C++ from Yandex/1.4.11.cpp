#include <iostream>

using namespace std;

int main()
{
    int n,m,k;
    cin>> n >> m >> k;
    if (((k%n==0 || k%m==0) && (k<n*m)))
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
    return 0;
}
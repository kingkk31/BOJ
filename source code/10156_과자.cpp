#include <iostream>
using namespace std;

int main(void)
{
    int k,n,m;
    cin>>k>>n>>m;
    
    if(k*n <= m)
        cout<<0<<endl;
    else
        cout<<k*n-m<<endl;
    
    return 0;
}
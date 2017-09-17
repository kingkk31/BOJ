#include <iostream>
#include <stdio.h>
using namespace std;

int main(void)
{
    int r,c,n;
    cin>>r>>c>>n;
    
    long long cnt = ((long long)(r/n))*((long long)(c/n));
    if(r%n != 0 && c%n != 0)
        cnt += (long long)(c/n) + (long long)(r/n) + 1;
    else if(r%n != 0)
        cnt += (long long)(c/n);
    else if(c%n != 0)
        cnt += (long long)(r/n);
    cout<<cnt<<endl;
}
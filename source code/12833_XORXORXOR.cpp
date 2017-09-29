#include <iostream>
#include <stdio.h>
using namespace std;

int main(void)
{
    int a,b,c;
    cin>>a>>b>>c;
    
    for(int i=0;i<c;i++)
        a ^= b;
    cout<<a<<endl;
}
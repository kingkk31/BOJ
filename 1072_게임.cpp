#include <iostream>
#include <stdio.h>
using namespace std;
long long L = 2000000000;
 
int win(long long x, long long y)
{
    return (y*100) / x;
}
 
int optimize(long long x, long long y)
{
    if(win(x,y) == win(x+L,y+L))
		return -1;
	
	long long lo = 0, hi = L;
    while(lo+1<hi)
    {
        long long mid = (lo+hi)/2;
        if(win(x,y) == win(x+mid,y+mid))
            lo = mid;
        else
            hi = mid;
    }
 
    return hi;
}
 
int main(void)
{
    long long x,y;
 
	while(scanf("%lld %lld", &x,&y) != EOF)
    {
        cout<<optimize(x,y)<<endl;
    }
 
    return 0;
}
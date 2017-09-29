#include <iostream>
using namespace std;
 
int N;
unsigned long long cache[91][2];
 
unsigned long long check(int pre, int place)
{   
    if(place == N-1)
        return 1;
 
	unsigned long long &ret = cache[place][pre];

	if(ret != -1)
		return ret;

    if(pre == 0)
        return ret = check(0,place+1) + check(1,place+1);
     
    if(pre == 1)
        return ret = check(0,place+1);
 
    return ret;
}
 
int main(void)
{   
    cin>>N;
 
	for(int i=0;i<91;i++)
	{
		for(int j=0;j<2;j++)
		cache[i][j] = -1;
	}
	
    cout<<check(1,0)<<endl;
     
    return 0;
}
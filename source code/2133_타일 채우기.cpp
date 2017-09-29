#include <iostream>
using namespace std;

int cache[101];

int check(int n)
{	
	if (n == 0)return 1;
    
	if (n == 2)return 3;

	int &ret = cache[n];

	if(ret != -1)
		return ret;
    
    return 4*check(n-2) - check(n-4);
}

int main(void)
{
	for(int i=0;i<101;i++)
	{
		cache[i] = -1;
	}

	int N;
	cin>>N;
	
	if(N%2 != 0)
		cout<<0<<endl;
	
	else
		cout<<check(N)<<endl;

    return 0;
}
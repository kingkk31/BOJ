#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int cache[2000001];

int main(void)
{
	memset(cache,-1,sizeof(cache));
	
	int N,C,total=0;
	cin>>N>>C;
	
	for(int i=0;i<N;i++)
	{
		int T;
		cin>>T;

		int a=1;
		while(T*a <= C)
		{
			if(cache[T*a] == -1)
			{
				cache[T*a] = 1;
				total++;
			}	
			a++;
		}
	}

	cout<<total<<endl;

	return 0;
}
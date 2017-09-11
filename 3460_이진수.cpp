#include <iostream>
#include <string>
#include <math.h>
using namespace std;
 
int main(void)
{
	int T;
	cin>>T;

	for(int i=0;i<T;i++)
	{
		int n;

		cin>>n;

		int *str = new int[n];

		int j=0;

		while(n>=1)
		{
			str[j] = n%2;
			n=n/2;
			j++;
		}
		/*		
		for(int i=(j-1);i>=0;i--)
			cout<<str[i];*/
				
		for(int i=0;i<j;i++)
		{
			if(str[i]==1)
			{
				cout<<i<<" ";
				if(i==(j-1))
				{
					cout<<endl;
				}
			}
		}

	}
 
    return 0;
}
#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <set>
#include <math.h>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;
 
int main(void) 
{
	int n;
	cin>>n;

	int a=0;
	int b=1;
	int temp;

	if(n == 0)
		cout<<a<<endl;
	else if(n == 1)
		cout<<b<<endl;
	else
	{
		for(int i=2;i<=n;i++)
		{
			temp = a+b;
			a = b;
			b = temp;
		}
		cout<<b<<endl;
	}

	return 0;
}

#include <iostream>
using namespace std;

int check(int N)
{
	int count = 0;
	int n=N;

	if(N < 3)
	{
		count = -1;
		return count;
	}

	if(N%5 == 0)
		return N/5;

	while(1)
	{
		n-=3;
		++count;
		
		if(n%5 == 0)
		{
			count += n/5;
			break;
		}

		if(n == 0)
			break;

		if(n<0)
		{
			count = -1;
			break;
		}
	}

	return count;
}

int main(void)
{
	int N;
	cin>>N;

	cout<<check(N)<<endl;


	return 0;
}

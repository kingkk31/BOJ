#include <iostream>
#include <math.h>
#include <vector>
#include <stdio.h>
using namespace std;
   
bool isPrime(int n)
{
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    int sqrtn = int(sqrt((double)n));
    for (int i = 3; i <= sqrtn; i += 2)
    {
        if (n%i == 0)
            return false;
    }
    return true;
}

int main(void)
{
	int cnt=0;
	int N;
	cin>>N;

	for(int i=0;i<N;i++)
	{
		int num;
		cin>>num;

		if(isPrime(num))
			cnt++;
	}

	cout<<cnt<<endl;

	return 0;
}

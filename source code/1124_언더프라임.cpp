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

vector<int> minFactor;

void eratos(int n)
{
	minFactor.resize(n+1);

	minFactor[0] = minFactor[1] = -1;

	for(int i=2;i<=n;i++)
		minFactor[i] = i;

	int sqrtn = int(sqrt((double)n));

	for(int i=2;i<=sqrtn;i++)
	{
		if(minFactor[i] == i)
		{
			for(int j=i*i;j<=n;j+=i)
			{
				if(minFactor[j] == j)
					minFactor[j] = i;
			}
		}
	}
}

int factor(int n)
{
	vector<int> ret;

	while(n > 1)
	{
		ret.push_back(minFactor[n]);
		n /= minFactor[n];
	}

	return ret.size();
}



int main(void)
{
    int A,B;
	scanf("%d %d", &A,&B);

	int cnt=0;
	eratos(B);
	
	for(int i=A;i<=B;i++)
	{
		if(isPrime(factor(i)))
			cnt++;
	}

	printf("%d\n", cnt);
	
    return 0;
}
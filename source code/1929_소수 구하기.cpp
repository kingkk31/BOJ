#include <iostream>
#include <math.h>
using namespace std;
   
bool isPrime(int n)
{
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    int sqrtn = int(sqrt((double)n));
    for (int i = 3; i <= sqrtn; i += 2)
		if (n%i == 0)
            return false;
    
    return true;
}

int main(void)
{
	int m,n;
	cin>>m>>n;

	for(int i=m;i<=n;i++)
		if(isPrime(i))
			cout<<i<<endl;

	return 0;
}
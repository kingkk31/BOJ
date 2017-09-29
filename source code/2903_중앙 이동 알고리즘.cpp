#include <iostream>
#include <math.h>
using namespace std;

int main(void)
{
	int n;
	cin>>n;

	unsigned long long a = pow(2+(pow(2.0,n)-1),2);
	cout<<a<<endl;

	return 0;
}
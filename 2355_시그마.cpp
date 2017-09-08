#include <iostream>
using namespace std;

int main(void)
{
	long long i,j;
	cin>>i>>j;

	if(i>j)
	{
		long long temp;		
		temp = i;
		i=j;
		j = temp;
	}

	cout<<(((j-i+1)*(i+j))/2)<<endl;
	
	return 0;
}
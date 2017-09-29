#include <iostream>
using namespace std;

int main(void)
{
	int A,B,V;

	cin>>A>>B>>V;

	int i=0,cnt=0;

	while(i<V)
	{
		i=i+A;

		if(i<V)
		{
			i=i-B;
		}
		cnt++;
	}

	cout<<cnt<<endl;

}
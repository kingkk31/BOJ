#include <iostream>
#include <string>
using namespace std;

int main(void)
{  	
	int T;
	cin>>T;
	
	int m=0,s=0,l=0;
	
	for(int i=0;i<T;i++)
	{
		string eat;
		cin>>eat;

		if(eat == "1/2")
			m++;	
		else if(eat == "1/4")
			s++;
		else if(eat == "3/4")
			l++;
	}

	int piz = l;
	s = s-l;

	while(m > 1)
	{
		m = m-2;
		piz++;
	}
		
	if(m == 1)
		piz++;
	
	if(m == 1 && s>0)
		s = s-2;
	
	if(s>0)
	{
		int mod = s/4;

		if(s%4 == 0)
			piz += mod;
		else
			piz += (mod+1);
	}

	cout<<piz<<endl;

    return 0;
}
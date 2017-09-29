#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	int N;
	cin>>N;

	long long maxi;
	long long total=0;
	long long all = 0;

	long long num;
	cin>>num;
	
	total += num;
	maxi = total;
	all += num;
	
	for(int i=1;i<N;i++)
	{
		long long num;
		cin>>num;
		
		if(maxi < 0)
		{
			if(num < 0)
			{
				maxi = max(maxi,num);
				all += num;
				
			}
			else
			{
				total = num;
				maxi = total;
				all += num;
				maxi = max(maxi,all);
				if(all <= 0)
					all = 0;
			}
		}
		else
		{
			if(num >= 0)
			{
				total += num;
				maxi = max(maxi,total);
				maxi = max(maxi,all);
				all += num;
				if(all <= 0)
					all = 0;
			}
			else
			{
				maxi = max(maxi,total);
				maxi = max(maxi,all);
				total=0;
				all += num;
				if(all <= 0)
					all = 0;
			}
		}	
	}
	
	maxi = max(maxi,all);

	cout<<maxi<<endl;

	return 0;
}
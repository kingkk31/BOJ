#include <iostream>
using namespace std;
 
int main(void)
{
    int total=0;

	for(int i=0;i<5;i++)
	{
		int s;
		cin>>s;
		
		if(s<40)
			s = 40;

		total += s;
	}

	cout<<total/5<<endl;
		
    return 0;
}
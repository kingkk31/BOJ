#include <iostream>
using namespace std;

int main(void)
{
	for(int i=0;i<3;i++)
	{
		int zero=0, one=0;
		for(int j=0;j<4;j++)
		{
			int num;
			cin>>num;
			if(num == 0)
				zero++;
			else if(num == 1)
				one++;
		}

		if(zero == 1 && one == 3)
			cout<<'A'<<endl;
		else if(zero == 2 && one == 2)
			cout<<'B'<<endl;
		else if(zero == 3 && one == 1)
			cout<<'C'<<endl;
		else if(zero == 4)
			cout<<'D'<<endl;
		else if(one == 4)
			cout<<'E'<<endl;
	}

	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	while(1)
	{
		int T;
		cin>>T;

		if(T == -1)
			break;

		int num=T,total=0;
		vector<int> child;

		for(int i=1;i<T;i++)
		{
			if(num%i == 0)
			{
				total += i;
				child.push_back(i);
			}
		}

		if(total == T)
		{
			cout<<T<<" =";

			for(int i=0;i<child.size();i++)
			{
				cout<<" "<<child[i];
				if(i != child.size()-1)
					cout<<" +";
			}
		}
		else
		{
			cout<<T<<" is NOT perfect.";
		}

		cout<<endl;
	}

	return 0;
}

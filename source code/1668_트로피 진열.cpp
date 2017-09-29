#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int main(void)
{
    int N;
	cin>>N;

	if(N==0)
	{
		cout<<0<<endl;
		cout<<0<<endl;
	}
	else
	{
		vector<int> vt;

		for(int i=0;i<N;i++)
		{
			int num;
			cin>>num;

			vt.push_back(num);
		}

		int left=1,right=1;
		int maxL=vt.front(), maxR=vt.back();

		for(int i=0;i<vt.size();i++)
		{
			if(maxL < vt[i])
			{
				maxL = vt[i];
				left++;
			}
		}

		for(int i=vt.size()-1;i>=0;i--)
		{
			if(maxR < vt[i])
			{
				maxR = vt[i];
				right++;
			}
		}

		cout<<left<<endl;
		cout<<right<<endl;
	}

    return 0;
}

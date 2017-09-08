#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

int main(void)
{
	string str;
	cin>>str;

	vector<int> vt;

	for(int i=0;i<str.length();i++)
	{
		vt.push_back((int)str[i] - 48);
	}
	while((vt.size() % 3) != 0)
	{
		vt.insert(vt.begin(),0);
	}

	for(int i=0;i<vt.size();i+=3)
	{
		int num=0;
		
		if(vt[i] == 0)
		{
			if(vt[i+1] == 0)
				vt[i+2] == 0 ? num+=0 : num+=1;
			else
				vt[i+2] == 0 ? num+=2 : num+=3;
		}
		else
		{
			if(vt[i+1] == 0)
				vt[i+2] == 0 ? num+=4 : num+=5;
			else
				vt[i+2] == 0 ? num+=6 : num+=7;
		}

		cout<<num;
	}
	cout<<endl;

	return 0;
}

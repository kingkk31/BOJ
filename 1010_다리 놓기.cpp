#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	int T;
	cin>>T;
	
	for(int i=0;i<T;i++)
	{
		int N,M;
		cin>>N>>M;
		vector<int> vt1,vt2;
			
		for(int a=N+1;a<=M;a++)
			vt1.push_back(a);

		for(int a=1;a<=M-N;a++)
			vt2.push_back(a);

		for(int i=0;i<vt1.size();i++)
		{
			for(int j=0;j<vt2.size();j++)
			{
				if((vt1[i] % vt2[j]) == 0)
				{	
					vt1[i] = (vt1[i] / vt2[j]);
				    vt2.erase((vt2.begin())+j);
				}
			}
		}

		unsigned long long A=1,B=1;

		for(int a=0;a<vt1.size();a++)
			B *= vt1[a];
		
		for(int a=0;a<vt2.size();a++)
			A *= vt2[a];
				
		cout<<B/A<<endl;
	}	

	return 0;
}

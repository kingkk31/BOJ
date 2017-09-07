#include <iostream>
#include <vector>
using namespace std;

int main(void)
{  
	int N;
	cin>>N;
	int what;
	cin>>what;
	int l,r;
	
	vector<vector<int> > vt;
	
	for(int i=0;i<N;i++)
	{
		vector<int> in;
		in.resize(N);
		vt.push_back(in);
	}

	int P=(N/2),Q=(N/2);
	int S=(-1);
	int k=1;
	int num=2;

	vt[N/2][N/2] = 1;

	while(1)
	{
		for(int i=0;i<k;i++)
		{
			if(num > N*N)
				break;

			P = P+S;
			vt[P][Q] = num++;
		}		
		
		if(num > N*N)
			break;
		
		S = S*(-1);

		for(int i=0;i<k;i++)
		{
			if(num > N*N)
				break;

			Q = Q+S;
			vt[P][Q] = num++;
		}	

		if(num > N*N)
			break;

		k++;
	}

	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(vt[i][j] == what)
			{
				l = i+1;
				r = j+1;
			}
			if(j<N-1)
				cout<<vt[i][j]<<" ";
			else if(j == N-1)
				cout<<vt[i][j]<<endl;
		}
	}

	cout<<l<<" "<<r<<endl;

	return 0;
}
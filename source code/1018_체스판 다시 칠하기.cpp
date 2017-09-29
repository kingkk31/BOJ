#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<char> > vt;
int mini = 2500;

int check(int i,int j)
{
    int B=0, W=0;

    for (int y = 0; y < 8; y++)
    {
        if ((y%2) == 0)
        {
            for (int x = 0; x < 8; x++)
            {
                if ((x%2) == 0)
                {
                    if (vt[i+y][j+x] == 'B')
						W++;
                    else 
						B++;
                }
                else
                {
                    if (vt[i+y][j+x] == 'W')
						W++;
                    else 
						B++;
                }
            }
        }
        else
        {
            for (int x = 0; x < 8; x++)
            {
                if ((x%2) == 0)
                {
                    if (vt[i+y][j+x] == 'W')
						W++;
                    else 
						B++;
                }
                else
                {
                    if (vt[i+y][j+x] == 'B')
						W++;
                    else 
						B++;
                 }
            }
        }
    }

    if (W < B)
		return W;
    else 
		return B;
}

int main(void)
{
	int N,M;
	cin>>N>>M;

	for(int i=0;i<N;i++)
	{
		vector<char> in;
		in.resize(M);
		vt.push_back(in);
	}	

	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			cin>>vt[i][j];

	for (int i=0;i<=N-8;i++)
        for (int j=0;j<=M-8;j++)
    		mini = min(mini, check(i,j));
    
	cout<<mini<<endl;

	return 0;
}

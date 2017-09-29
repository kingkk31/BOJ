#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int N;
	cin>>N;

	vector<vector<int> > vt;

	for(int i=0;i<N;i++)
	{
		vector<int> in;
		in.resize(3);
		vt.push_back(in);
	}

	int r,g,b;
	
	cin>>vt[0][0]>>vt[0][1]>>vt[0][2];

	 for(int i=1;i<N;i++)
	 {
        cin>>r>>g>>b;

        vt[i][0]=min(vt[i-1][1]+r, vt[i-1][2]+r);
        vt[i][1]=min(vt[i-1][0]+g, vt[i-1][2]+g);
        vt[i][2]=min(vt[i-1][0]+b, vt[i-1][1]+b);
     }
	 
    cout<<min(vt[N-1][0], min(vt[N-1][1], vt[N-1][2]))<<endl;
	
	return 0;
}
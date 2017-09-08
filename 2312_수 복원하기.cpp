#include <iostream>
#include <math.h>
#include <vector>
#include <map>
using namespace std;

bool isPrime(int n)
{
	if(n<=1) return false;
	if(n==2) return true;
	if(n%2==0) return false;
	int sqrtn = int(sqrt((double)n));
	for(int i=3;i<=sqrtn;i+=2)
    {
		if(n%i==0)
			return false;
    }
	return true;
}

int main(void)
{
	int T;
	cin>>T;

	for(int i=0;i<T;i++)
    {
		int N;
		cin>>N;

		vector<int> vt;
		map<int,int> m;

		for(int j=2;j<=N;j++)
			if(isPrime(j))
        {
				vt.push_back(j);
				m[j]=0;
        }

			for(int j=0;j<vt.size();j++)
            {
				while(N%vt[j] == 0)
                {
					N /= vt[j];
					m[vt[j]] += 1;
                }

				if(m[vt[j]] != 0)
                {
					cout<<vt[j]<<" "<<m[vt[j]]<<endl;
                }
            }
    }

	return 0;
}
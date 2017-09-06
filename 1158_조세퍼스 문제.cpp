#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	vector<int> vt;
	int n,m,cnt=0;
	cin>>n>>m;

	for(int j=0;j<n;j++)
		vt.push_back(j+1);

	cout<<"<";

	for(int i=0;i<n;i++)
	{
		cnt+=(m-1);
		if(vt.size()>cnt)
		{
			cout<<*(vt.begin()+cnt);
			vt.erase((vt.begin()+cnt));
		}
		else
		{
			cnt = cnt%vt.size();
			cout<<*(vt.begin()+cnt);
			vt.erase((vt.begin()+cnt));
		}

		if(i<n-1)
			cout <<", ";
	}

	cout<<">";

	return 0;
}
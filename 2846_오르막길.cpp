#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
  
int main(void)
{
    int N;
	cin>>N;
	vector<int> vt;

	int maximum=0;

	int num;
	cin>>num;
	vt.push_back(num);

	for(int i=1;i<N;i++)
	{
		int num;
		cin>>num;

		if(num <= vt[vt.size()-1])
		{
			vt.clear();
			vt.push_back(num);
		}
		else
		{
			vt.push_back(num);
			maximum = max(maximum,(vt[vt.size()-1]-vt[0]));
		}
	}

	cout<<maximum<<endl;

    return 0;
}
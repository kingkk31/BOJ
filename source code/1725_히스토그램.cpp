#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> h;

int solve(int left, int right)
{
	if(left == right)
		return h[left];

	int mid = (left+right)/2;
	int ret = max(solve(left,mid), solve(mid+1,right));

	int lo = mid, hi = mid+1;
	int height = min(h[lo],h[hi]);

	ret = max(ret, height*2);

	while(left < lo || hi < right)
	{
		if(hi < right && (lo == left || h[lo-1] < h[hi+1]))
		{
			++hi;
			height = min(height, h[hi]);
		}
		else
		{
			--lo;
			height = min(height, h[lo]);
		}

		ret = max(ret, height * (hi-lo+1));
	}

	return ret;
}

int main(void)
{
	int N;
	cin>>N;

	for(int i=0;i<N;i++)
	{
		int num;
		cin>>num;
		h.push_back(num);
	}

	cout<<solve(0,N-1)<<endl;

	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int start[100000], finish[100000];

int schedule(void)
{
	vector<pair<int,int> > order;

	for(int i=0;i<n;++i)
		order.push_back(make_pair(finish[i],start[i]));
	
	sort(order.begin(),order.end());

	int earliest=0,selected=0;

	for(int i=0;i<order.size();++i)
	{
		int meetingBegin = order[i].second, meetingEnd = order[i].first;

		if(earliest <= meetingBegin)
		{
			earliest = meetingEnd;
			++selected;
		}
	}
	return selected;
}

int main(void)
{
	cin>>n;

	for(int i=0;i<n;i++)
		cin>>start[i]>>finish[i];
	
	cout<<schedule()<<endl;
	
	return 0;
}
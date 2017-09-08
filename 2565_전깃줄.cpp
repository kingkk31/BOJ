#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <set>
#include <list>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;

int main(void)
{
	int n;
	cin >> n;
	
	vector<pair<int,int> > vt;
		
	for (int i = 0; i < n; i++)
	{
		int first,second;
		cin >> first >> second;
		vt.push_back(make_pair(first,second));
	}
	
	sort(vt.begin(), vt.end());

	vector<int> LIS;
	LIS.push_back(vt[0].second);

		for (int i = 1; i<vt.size(); ++i) 
		{
			if (LIS.back()<vt[i].second) 
				LIS.push_back(vt[i].second);
			else 
			{
				vector<int>::iterator itr = lower_bound(LIS.begin(), LIS.end(), vt[i].second);
				*itr = vt[i].second;
			}
		}

		cout << vt.size() - LIS.size() << endl;		
	

	return 0;
}

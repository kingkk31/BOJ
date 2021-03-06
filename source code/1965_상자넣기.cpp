#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <list>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <malloc.h>
#include <functional>
#include <time.h>
#include <cctype>
#pragma warning(disable:4996)
using namespace std;

vector<int> LIS(vector<int> vt)
{
	vector<int> lis;
	lis.push_back(vt[0]);
	
	for (int i = 1; i<vt.size(); ++i)
	{
		if (lis.back() < vt[i])
			lis.push_back(vt[i]);
		else
		{
			vector<int>::iterator itr = lower_bound(lis.begin(), lis.end(), vt[i]);
			*itr = vt[i];
		}
	}

	return lis;
}

int main(void)
{
	int n;
	cin >> n;
	vector<int> vt(n);
	
	for (int i = 0; i < n; i++)
		cin >> vt[i];

	vector<int> result = LIS(vt);
	cout << result.size() << endl;
	
	return 0;
}
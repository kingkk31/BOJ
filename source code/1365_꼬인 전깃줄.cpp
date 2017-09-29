#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <vector>
#include <stack>
#include <set>
#include <list>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <malloc.h>
#include <functional>
#pragma warning(disable:4996)
using namespace std;

int main(void)
{
	int n;
	cin >> n;

	vector<int> vt;

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		vt.push_back(num);
	}

	vector<int> LIS;
	LIS.push_back(vt[0]);

	for (int i = 1; i<vt.size(); ++i)
	{
		if (LIS.back()<vt[i])
			LIS.push_back(vt[i]);
		else
		{
			vector<int>::iterator itr = lower_bound(LIS.begin(), LIS.end(), vt[i]);
			*itr = vt[i];
		}
	}

	cout << vt.size() - LIS.size() << endl;

	return 0;
}
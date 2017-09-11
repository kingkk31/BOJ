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
	int T;

	while(~scanf("%d", &T))
	{
		vector<int> v;
		
		for (int i = 0; i < T; i++)
		{
			int num;
			cin >> num;
			v.push_back(num);
		}
		
		vector<int> LIS;
		LIS.push_back(v[0]);

		for (int i = 1; i<v.size(); ++i) 
		{
			if (LIS.back()<v[i]) LIS.push_back(v[i]);
			else 
			{
				vector<int>::iterator it = lower_bound(LIS.begin(), LIS.end(), v[i]);
				*it = v[i];
			}
		}

		cout << LIS.size() << endl;		
	}

	return 0;
}

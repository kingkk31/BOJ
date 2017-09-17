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

int main(void)
{
	int t;
	cin >> t;

	while (t--)
	{
		int n;
		cin >> n;
		map<int, int> mp;

		while (n--)
		{
			int m;
			cin >> m;
			if (!mp.insert(make_pair(m, 1)).second)
				mp[m]++;
		}

		map<int, int>::iterator itr = mp.begin();
		map<int, int>::iterator itr2 = mp.begin();

		while (itr != mp.end())
		{
			if (itr->second > itr2->second)
				itr2 = itr;
			itr++;
		}

		cout << itr2->first << endl;
	}

	return 0;
}
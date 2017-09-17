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
#pragma warning(disable:4996)
using namespace std;

multiset<int> cache[1000001];

int main(void)
{
	int n, cnt = 0, maxi = 0;
	cin >> n;
	vector<int> vt;
	
	for (int i = 0; i < n; i++)
	{
		int num;
		scanf("%d", &num);
		vt.push_back(num);
		maxi = max(maxi, num);
	}

	for (int i = 0; i < n; i++)
		cache[vt[i]].insert(i);

	for (int i = maxi; i > 0; i--)
	{
		while (!cache[i].empty())
		{
			multiset<int>::iterator itr = cache[i].end();
			int here = *(--itr);
			cache[i].erase(itr);

			int next = i - 1;
			while (!cache[next].empty())
			{
				multiset<int>::iterator itr2 = cache[next].end();
				itr2--;
				
				if (*itr2 <= here)
					break;
				
				here = *itr2;
				cache[next].erase(itr2);
				next--;
			}

			cnt++;
		}
	}

	cout << cnt << endl;

	return 0;
}
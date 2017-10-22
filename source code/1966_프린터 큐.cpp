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
#include <iterator>
#include <sstream>
#pragma warning(disable:4996)
using namespace std;

#define INF 987654321

int solve(vector<int> &priority, queue<pair<int, int> > &qu, int m)
{
	int cnt = 0;
	sort(priority.begin(), priority.end());
	while (!qu.empty())
	{
		int num = qu.front().first, order = qu.front().second;
		qu.pop();
		if (priority.back() == order)
		{
			cnt++;
			if (num == m)
				return cnt;
			priority.pop_back();
		}
		else
			qu.push(make_pair(num, order));
	}	
}

int main(void)
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n, m;
		scanf("%d %d", &n, &m);	

		vector<int> priority;
		queue<pair<int, int> > qu;
		for (int i = 0; i < n; i++)
		{
			int p;
			scanf("%d", &p);
			priority.push_back(p);
			qu.push(make_pair(i, p));
		}

		cout << solve(priority, qu, m) << endl;		
	}

	return 0;
}
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
#pragma warning(disable:4996)
using namespace std;

int main(void)
{
	int n;
	cin >> n;

	long long cnt = 0;
	stack<pair<int, int> > st;

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
				
		pair<int, int> p;
		p.first = num;
		p.second = 1;

		while (!st.empty())
		{
			if (st.top().first <= num)
			{
				cnt += (long long)st.top().second;

				if (st.top().first == num)
					p.second += st.top().second;

				st.pop();
			}
			else
				break;
		}

		if (!st.empty())
			cnt += 1LL;

		st.push(p);
	}

	cout << cnt << endl;

	return 0;
}


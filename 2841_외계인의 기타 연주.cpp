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

#define INF 987654321

int main(void)
{
	int n, p, cnt = 0;
	scanf("%d %d", &n, &p);
	vector<stack<int> > vt(7);

	for (int i = 0; i < n; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		
		while (!vt[a].empty() && vt[a].top() > b)
		{
			vt[a].pop();
			cnt++;
		}
		if (vt[a].empty() || vt[a].top() < b)
		{
			cnt++;
			vt[a].push(b);
		}
	}

	cout << cnt << endl;

	return 0;
}
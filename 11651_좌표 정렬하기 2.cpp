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

#define pp pair<int, int>

bool comp(const pp &left, const pp &right)
{
	if (left.second < right.second || (left.second == right.second) && left.first < right.first)
		return true;
	return false;
}

int main(void)
{
	int n;
	scanf("%d", &n);

	vector<pp> vt(n);
	for (int i = 0; i < n; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		vt[i] = make_pair(x, y);
	}

	sort(vt.begin(), vt.end(), comp);
	for (int i = 0; i < n; i++)
		printf("%d %d\n", vt[i].first, vt[i].second);

	return 0;
}
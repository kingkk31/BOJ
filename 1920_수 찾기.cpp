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

vector<int> vt;

int solve(int num)
{
	int start = 0, end = vt.size() - 1;
	while (start <= end)
	{
		int mid = (start + end) / 2;
		if (vt[mid] == num)
			return 1;
		
		if (vt[mid] < num)
			start = mid + 1;
		else
			end = mid - 1;
	}
	return 0;
}

int main(void)
{
	int n;
	scanf("%d", &n);

	vt = vector<int>(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &vt[i]);

	sort(vt.begin(), vt.end());

	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		int num;
		scanf("%d", &num);
		printf("%d\n", solve(num));
	}
	return 0;
}
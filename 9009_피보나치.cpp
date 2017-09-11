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

int arr[45];
int cache[45];
vector<int> vt;
bool flag;

void solve(int num, int sum, int pre)
{
	if (flag)
		return;

	if (num == sum)
	{
		if (!flag) 
		{
			sort(vt.begin(), vt.end());
			for (int i = 0; i < vt.size(); i++)
				printf("%d ", vt[i]);
			printf("\n");
			flag = true;
		}
		return;
	}
	else if (num < sum)
		return;

	for (int i = pre - 1; i > 0; i--)
	{
		if (flag)
			return;

		if (cache[i] == -1)
		{
			vt.push_back(arr[i]);
			cache[i] = 1;
			solve(num, sum + arr[i], i);
			cache[i] = -1;
			vt.pop_back();
		}
	}
}

int main(void)
{
	arr[0] = 0;
	arr[1] = 1;
	for (int i = 2; i < 45;i++)
		arr[i] = arr[i - 1] + arr[i - 2];
	
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n;
		scanf("%d", &n);
		memset(cache, -1, sizeof(cache));
		flag = false;
		vt.clear();
		solve(n, 0, 45);
	}

	return 0;
}
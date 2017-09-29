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
	int n, maxi = 0;
	unsigned long long cnt = 0;
	scanf("%d", &n);
	vector<int> vt(n + 2);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &vt[i]);
		maxi = max(maxi, vt[i]);
	}
	vt[0] = vt[n + 1] = maxi;
	
	for (int i = 1; i <= n + 1; i++)
		cnt += abs(vt[i] - vt[i - 1]);
	cout << (unsigned long long)(cnt / 2) << endl;

	return 0;
}
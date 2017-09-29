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
	int n, ans = -500001;
	scanf("%d", &n);
	vector<int> vt(n);
	vector<int> sorted(n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &vt[i]);
		sorted[i] = vt[i];
	}

	sort(sorted.begin(), sorted.end());

	for (int i = 0; i < n; i++)
		ans = max(ans, i - (lower_bound(sorted.begin(), sorted.end(), vt[i]) - sorted.begin()));

	cout << ans << endl;

	return 0;
}
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
	int n;
	scanf("%d", &n);

	vector<int> vt(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &vt[i]);

	sort(vt.begin(), vt.end(), greater<int>());
	long long cnt = 0;
	for (int i = 0; i < n; i++)
		cnt += (((vt[i] - i) <= 0) ? 0 : vt[i] - i);
	cout << cnt << endl;

	return 0;
}
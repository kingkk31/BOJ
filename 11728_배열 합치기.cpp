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
	int n, m;
	cin >> n >> m;

	vector<int> vt;

	for (int i = 0; i < n; i++)
	{
		int num;
		scanf("%d", &num);
		vt.push_back(num);
	}

	for (int i = 0; i < m; i++)
	{
		int num;
		scanf("%d", &num);
		vt.push_back(num);
	}

	sort(vt.begin(), vt.end());

	for (int i = 0; i < vt.size(); i++)
		printf("%d ", vt[i]);

	return 0;
}
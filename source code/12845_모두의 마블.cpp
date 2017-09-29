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
	int n, maxi = -1, total = 0;
	scanf("%d", &n);
	vector<int> vt(n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &vt[i]);
		maxi = max(maxi, vt[i]);
	}

	vector<int>::iterator itr = find(vt.begin(), vt.end(), maxi);
	while (itr + 1 != vt.end())
	{
		total += (*itr) + *(vt.end() - 1);
		vt.pop_back();
	}
	while (vt.size() != 1)
	{
		total += vt.front() + vt.back();
		vt.erase(vt.begin());
	}
	cout << total << endl;

	return 0;
}
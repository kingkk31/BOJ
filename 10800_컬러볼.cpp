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
#pragma warning(disable:4996)
using namespace std;

#define pp pair<int,int>

void partialsum(vector<long long> &vt)
{
	vt[0] = 0;
	for (int i = 1; i < vt.size(); i++)
		vt[i] = vt[i - 1] + (vt[i] * i);
}

int main(void)
{
	int n;
	scanf("%d", &n);

	vector<pp> box(n);
	vector<long long> vt(2001, 0);
	vector<vector<int> > colorBox(n + 1);

	for (int i = 0; i < n; i++)
	{
		int color, size;
		scanf("%d %d", &color, &size);

		box[i] = make_pair(color, size);
		colorBox[color].push_back(size);
		vt[size]++;
	}

	for (int i = 1; i <= n; i++)
		sort(colorBox[i].begin(), colorBox[i].end());

	partialsum(vt);

	for (int i = 0; i < n; i++)
	{
		long long sum = vt[box[i].second - 1];
		vector<int>::iterator pos = lower_bound(colorBox[box[i].first].begin(), colorBox[box[i].first].end(), box[i].second);
		vector<int>::iterator itr = colorBox[box[i].first].begin();
		while (itr != pos)
			sum -= *(itr++);

		printf("%lld\n", sum);
	}

	return 0;
}
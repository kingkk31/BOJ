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

vector<pair<int, int> > vt;

void hanoi(int n, int from, int temp, int to)
{
	if (n == 1)
	{
		vt.push_back(make_pair(from, to));
		return;
	}

	hanoi(n - 1, from, to, temp);
	vt.push_back(make_pair(from, to));
	hanoi(n - 1, temp, from, to);
}

int main(void)
{
	int n;
	scanf("%d", &n);

	hanoi(n, 1, 2, 3);
	printf("%d\n", vt.size());
	for (int i = 0; i < vt.size(); i++)
		printf("%d %d\n", vt[i].first, vt[i].second);

	return 0;
}

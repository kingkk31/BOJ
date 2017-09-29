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
vector<int> minTree;
vector<int> maxTree;

int minInit(int node, int start, int end)
{
	if (start == end)
		return minTree[node] = vt[start];
	else
		return minTree[node] = min(minInit(node * 2, start, (start + end) / 2), minInit(node * 2 + 1, (start + end) / 2 + 1, end));
}

int maxInit(int node, int start, int end)
{
	if (start == end)
		return maxTree[node] = vt[start];
	else
		return maxTree[node] = max(maxInit(node * 2, start, (start + end) / 2), maxInit(node * 2 + 1, (start + end) / 2 + 1, end));
}

int minSolve(int node, int start, int end, int left, int right)
{
	if (left > end || right < start)
		return 1000000001;
	if (left <= start && end <= right)
		return minTree[node];
	
	return min(minSolve(node * 2, start, (start + end) / 2, left, right), minSolve(node * 2 + 1, (start + end) / 2 + 1, end, left, right));
}

int maxSolve(int node, int start, int end, int left, int right)
{
	if (left > end || right < start)
		return 0;
	if (left <= start && end <= right)
		return maxTree[node];

	return max(maxSolve(node * 2, start, (start + end) / 2, left, right), maxSolve(node * 2 + 1, (start + end) / 2 + 1, end, left, right));
}

int main(void)
{
	int n, m;
	scanf("%d %d", &n, &m);
	
	int h = (int)ceil(log2(n));
	int tree_size = (1 << (h + 1));
	vt = vector<int>(n);
	minTree = vector<int>(tree_size);
	maxTree = vector<int>(tree_size);

	for (int i = 0; i < n; i++)
		scanf("%d", &vt[i]);

	minInit(1, 0, n - 1);
	maxInit(1, 0, n - 1);

	while (m--)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d %d\n", minSolve(1, 0, n - 1, a - 1, b - 1), maxSolve(1, 0, n - 1, a - 1, b - 1));
	}

	return 0;
}

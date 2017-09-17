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

vector<long long> tree;

void update(int node, int start, int end, int index, long long diff)
{
	if (index < start || index > end)
		return;

	tree[node] = tree[node] + diff;

	if (start != end)
	{
		update(node * 2, start, (start + end) / 2, index, diff);
		update(node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
	}
}

long long sum(int node, int start, int end, int left, int right)
{
	if (left > end || right < start)
		return 0;
	
	if (left <= start && end <= right)
		return tree[node];

	return sum(node * 2, start, (start + end) / 2, left, right) + sum(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

int main(void)
{
	int n, q;
	scanf("%d %d", &n, &q);
	
	int h = (int)ceil(log2(n));
	int tree_size = (1 << (h + 1));
	tree = vector<long long>(tree_size, 0);
	
	while (q--)
	{
		int a, b;
		long long c;
		scanf("%d %d %lld", &a, &b, &c);
		
		if (a == 1)
			update(1, 0, n - 1, b - 1, c);
		else
			printf("%lld\n", sum(1, 0, n - 1, b - 1, c - 1));
	}

	return 0;
}

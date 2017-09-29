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

unsigned long long init(vector<unsigned long long> &a, vector<unsigned long long> &tree, int node, int start, int end)
{
	if (start == end)
		return tree[node] = a[start];
	else
		return tree[node] = init(a, tree, node * 2, start, (start + end) / 2) + init(a, tree, node * 2 + 1, (start + end) / 2 + 1, end);
}

// node가 담당하는 구간이 start~end이고, 구해야하는 합의 범위는 left~right
unsigned long long sum(vector<unsigned long long> &tree, int node, int start, int end, int left, int right)
{
	if (left > end || right < start)
		return 0;

	if (left <= start && end <= right)
		return tree[node];

	return sum(tree, node * 2, start, (start + end) / 2, left, right) + sum(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

void update(vector<unsigned long long> &tree, int node, int start, int end, int index, unsigned long long diff)
{
	if (index < start || index > end)
		return;

	tree[node] = tree[node] + diff;

	if (start != end)
	{
		update(tree, node * 2, start, (start + end) / 2, index, diff);
		update(tree, node * 2 + 1, (start + end) / 2 + 1, end, index, diff);
	}
}

int main(void)
{
	int n, m;
	scanf("%d %d", &n, &m);

	vector<unsigned long long> vt(n, 0);
	int h = (int)ceil(log2(n));
	int tree_size = (1 << (h + 1));
	vector<unsigned long long> tree(tree_size);
	init(vt, tree, 1, 0, n - 1);

	while (m--)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		if (a == 1)
		{
			b -= 1;
			unsigned long long diff = c - vt[b];
			vt[b] = c;
			update(tree, 1, 0, n - 1, b, diff);
		}
		else
		{
			if (b > c)
				swap(b, c);
			printf("%llu\n", sum(tree, 1, 0, n - 1, b - 1, c - 1));
		}
	}

	return 0;
}
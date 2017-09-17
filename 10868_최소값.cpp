#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <set>
#include <list>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <assert.h>
#pragma warning(disable:4996)
using namespace std;

const int INF = 987654321;

struct IndexedTree {
	vector<int> tree;
	int last;

	IndexedTree(int n) 
	{
		int i;
		for (i = 1; i<n; i *= 2);

		last = i;
		tree.resize(4 * n, INF);
	}

	void set(int pos, int val)
	{
		tree[last + pos] = val;
		int next = last + pos;
		
		while (next != 1) 
		{
			if (tree[next] < tree[next / 2])
				tree[next / 2] = tree[next];
			else
				break;
			
			next /= 2;
		}
	}

	int mini(int left, int right)
	{
		int ret = INF;
		left += last;
		right += last;

		while (left<right) 
		{
			if (left % 2 == 1)
			{
				ret = min(ret, tree[left]);
				++left;
			}

			if (right % 2 == 0) 
			{
				ret = min(ret, tree[right]);
				--right;
			}
		
			left /= 2;
			right /= 2;
		}
		
		if (left == right)
			ret = min(ret, tree[left]);
		
		return ret;
	}
};

int main(void)
{
	int n, m;
	scanf("%d %d", &n, &m);

	IndexedTree vt(n);

	for (int i = 0; i < n; i++)
	{
		int num;
		scanf("%d", &num);
		vt.set(i, num);
	}

	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);

		printf("%d\n", vt.mini(a - 1, b - 1));
	}

	return 0;
}
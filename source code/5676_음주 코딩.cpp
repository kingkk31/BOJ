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
#include <iterator>
#include <sstream>
#pragma warning(disable:4996)
using namespace std;

#define INF 987654321
int n, k;
vector<int> vt, tree;

int init(vector<int> &a, vector<int> &tree, int node, int start, int end)
{
	if (start == end)
		return tree[node] = a[start];
	else
		return tree[node] = init(a, tree, node * 2, start, (start + end) / 2) * init(a, tree, node * 2 + 1, (start + end) / 2 + 1, end);
}

// node가 담당하는 구간이 start~end이고, 구해야하는 합의 범위는 left~right
int multiple(vector<int> &tree, int node, int start, int end, int left, int right)
{
	if (left > end || right < start)
		return 1;

	if (left <= start && end <= right)
		return tree[node];

	return multiple(tree, node * 2, start, (start + end) / 2, left, right) * multiple(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

void update(vector<int> &tree, int node, int start, int end, int index, int value)
{
	if (index < start || index > end)
		return;

	tree[node] = multiple(tree, 1, 0, n - 1, start, index - 1) * value * multiple(tree, 1, 0, n - 1, index + 1, end);

	if (start != end)
	{
		update(tree, node * 2, start, (start + end) / 2, index, value);
		update(tree, node * 2 + 1, (start + end) / 2 + 1, end, index, value);
	}
}

int main(void)
{
	while (scanf("%d %d ", &n, &k) != EOF)
	{
		vt = vector<int>(n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &vt[i]);
			if (vt[i] > 0)
				vt[i] = 1;
			else if (vt[i] < 0)
				vt[i] = -1;
		}
		getchar();
	
		int h = (int)ceil(log2(n));
		int tree_size = (1 << (h + 1));
		tree = vector<int>(tree_size);
		init(vt, tree, 1, 0, n - 1);
		
		queue<char> qu;

		while (k--)
		{
			char command;
			int a, b;
			scanf("%c %d %d", &command, &a, &b);
			getchar();
		
			if (command == 'C')
			{
				if (b > 0)
					b = 1;
				else if (b < 0)
					b = -1;
				else
					b = 0;

				if (vt[a - 1] != b) 
				{
					vt[a - 1] = b;
					update(tree, 1, 0, n - 1, a - 1, b);
				}
			}
			else
			{
				int ans = multiple(tree, 1, 0, n - 1, a - 1, b - 1);
				if (ans > 0)
					qu.push('+');
				else if (ans < 0)
					qu.push('-');
				else
					qu.push('0');
			}
		}
		
		while (!qu.empty())
		{
			printf("%c", qu.front());
			qu.pop();
		}
		printf("\n");
	}	

	return 0;
}
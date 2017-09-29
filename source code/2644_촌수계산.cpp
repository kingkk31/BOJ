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

void DFS(int start, const vector<vector<int> > &vt, vector<int> &numbering)
{
	for (int i = 0; i < vt[start].size(); i++)
	{
		int here = vt[start][i];
		if (numbering[here] == -1)
		{
			numbering[here] = numbering[start] + 1;
			DFS(here, vt, numbering);
		}
	}
}

int main(void)
{
	int n, m, a, b;
	cin >> n >> a >> b >> m;

	vector<vector<int> > vt(n);

	for (int i = 0; i < m; i++)
	{
		int parent, child;
		scanf("%d %d", &parent, &child);

		vt[parent - 1].push_back(child - 1);
		vt[child-1].push_back(parent - 1);
	}

	vector<int> numbering(n, -1);
	numbering[a - 1] = 0;

	DFS(a - 1, vt, numbering);

	cout << numbering[b - 1] << endl;

	return 0;
}
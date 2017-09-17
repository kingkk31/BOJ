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

int n;

void dfs(int num, vector<list<int> > &vt, vector<int> &parent)
{
	list<int>::iterator itr = vt[num].begin();
	for (int i = 0; i < vt[num].size(); i++)
	{
		vt[*itr].remove(num);
		parent[*itr] = num + 1;
		dfs(*itr, vt, parent);
		itr++;
	}
}

int main(void)
{
	cin >> n;

	vector<list<int> > vt(n);
	vector<int> parent(n, 0);

	for (int i = 1; i < n; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);

		vt[a - 1].push_back(b - 1);
		vt[b - 1].push_back(a - 1);
	}

	dfs(0, vt , parent);

	for (int i = 1; i < n; i++)
		cout << parent[i] << endl;
	
	return 0;
}
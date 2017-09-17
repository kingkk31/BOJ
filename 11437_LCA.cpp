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
vector<list<int> > tree;
vector<vector<int> > home;

void solve(int place)
{
	home[place].push_back(place); //족보에 나를 추가
	
	while(!tree[place].empty())
	{
		list<int>::iterator itr = tree[place].begin();
		int temp = *itr;
		home[temp].assign(home[place].begin(), home[place].end());//자식에게 자신의 조상복사
		tree[temp].remove(place);
		tree[place].remove(temp);

		solve(temp);
	}
}

int main(void)
{
	scanf("%d", &n);

	tree = vector<list<int> >(n + 1);

	for (int i = 0; i < n-1; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	home = vector<vector<int> >(n + 1);
	solve(1); //족보완성
	
	int m;
	scanf("%d", &m);

	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);

		int pa = 1;
		int cnt = home[a].size() < home[b].size() ? home[a].size() : home[b].size();
	
		for (int j = 0; j < cnt; j++)
		{
			if (home[a][j] != home[b][j])
					break;
			pa = home[a][j];
		}

		printf("%d\n", pa);
	}
	
	return 0;
}
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

#define pp pair<int, int>
map<string, int> mp;
map<int, string> mp2;
vector<vector<pp> > vt;
vector<int> worth;
vector<int> ans;
int n;
int maxi;

void solve(int pos, int e, long long w, int &maxL, int l, vector<int>&path, vector<int>&visited)
{
	if (pos == e && maxi < w)
	{
			maxi = w;
			ans = path;
	}
	
	for (int i = 0; i < vt[pos].size(); i++)
	{
		int next = vt[pos][i].first;
		int nextW = worth[next];
		int nextL = vt[pos][i].second;

		if (l + nextL > maxL)
			continue;

		visited[next]++;
		path.push_back(next);
		solve(next, e, w + (visited[next] == 1 ? nextW : 0), maxL, l + nextL, path, visited);
		path.pop_back();
		visited[next]--;
	}
}

int main(void)
{
	scanf("%d", &n);
	worth = vector<int>(n);
	for (int i = 0; i < n; i++)
	{
		string city;
		int w;
		cin >> city >> w;
		mp[city] = i;
		mp2[i] = city;
		worth[i] = w;
	}

	vt = vector<vector<pp> >(n);

	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		string c1, c2;
		int w;
		cin >> c1 >> c2 >> w;
		vt[mp[c1]].push_back(make_pair(mp[c2], w));
		vt[mp[c2]].push_back(make_pair(mp[c1], w));
	}

	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++)
	{
		string c1, c2;
		int l;
		cin >> c1 >> c2 >> l;
		
		vector<int> path;
		vector<int> visited(n, 0);
		visited[mp[c1]] = 1;
		path.push_back(mp[c1]);
		ans.clear();
		maxi = -987654321;
		solve(mp[c1], mp[c2], worth[mp[c1]], l, 0, path, visited);
		
		int result = ans.size();

		if (result == 0)
			printf("Case %d: Not possible\n", i);		
		else
		{
			printf("Case %d: %d\n", i, maxi);
			for (int i = 0; i < ans.size(); i++)
				cout << mp2[ans[i]] << endl;
		}
	}

	return 0;
}
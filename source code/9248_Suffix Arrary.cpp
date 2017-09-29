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

//접미사 배열
struct Compare
{
	int t;
	vector<int>& gr;
	Compare(int t_, vector<int>& gr_) :t(t_), gr(gr_) {}

	bool operator() (int x, int y)
	{
		return gr[x] != gr[y] ? gr[x]<gr[y] : gr[x + t]<gr[y + t];
	}
};

vector<int> getSuffixArray(string& S)
{
	int n = S.size();
	vector<int> ret(n), gr(n + 1), gr2(n);

	for (int i = 0; i < n; i++)
	{
		ret[i] = i;
		gr[i] = S[i];
	}
	gr[n] = -1;

	for (int i = 1; i < n; i <<= 1)
	{
		Compare cmp(i, gr);
		sort(ret.begin(), ret.end(), cmp);
		gr2[ret[0]] = 0;

		for (int j = 1; j<n; j++)
		{
			if (cmp(ret[j - 1], ret[j]))
				gr2[ret[j]] = gr2[ret[j - 1]] + 1;
			else
				gr2[ret[j]] = gr2[ret[j - 1]];
		}

		for (int j = 0; j<n; j++)
			gr[j] = gr2[j];
	}
	return ret;
}

//LCP - suffix array 이용
vector<int> getLCP(vector<int>& pos, string&s)
{
	int n = pos.size();
	vector<int> rank(n), height(n);
	for (int i = 0; i<n; i++)
		rank[pos[i]] = i;

	for (int i = 0, h = 0; i < n; i++)
	{
		if (rank[i] > 0)
		{
			int j = pos[rank[i] - 1];

			while (i + h < n && j + h < n && s[i + h] == s[j + h])
				h++;

			height[rank[i]] = h;

			if (h > 0)
				h--;
		}
	}

	return height;
}

int main(void)
{
	string a;
	cin >> a;
	
	vector<int> suffixArr = getSuffixArray(a);
	vector<int> lcpArr = getLCP(suffixArr, a);

	for (int i = 0; i < suffixArr.size(); i++)
		cout << suffixArr[i] + 1 << " ";

	cout << endl << "x ";
	for (int i = 1; i < lcpArr.size(); i++)
		cout << lcpArr[i] << " ";

	return 0;
}
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

int main(void)
{
	string str;
	cin >> str;
	
	vector<int> suffix = getSuffixArray(str);
	for (int i = 0; i < suffix.size(); i++)
		cout << str.substr(suffix[i], str.length() - suffix[i]) << endl;

	return 0;
}
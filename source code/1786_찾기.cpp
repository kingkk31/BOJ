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

vector<int> getPartialMatch(string &str)
{
	int m = str.size();
	vector<int> matchCnt(m, 0);

	int matched = 0;
	for (int begin = 1; begin < m; begin++)
	{
		while (matched > 0 && str[begin] != str[matched])
			matched = matchCnt[matched - 1];
		if (str[begin] == str[matched])
			matchCnt[begin] = ++matched;
	}

	return matchCnt;
}

vector<int> kmp(string &str, string &pattern)
{
	int n = str.size(), m = pattern.size();
	vector<int> matchCnt = getPartialMatch(pattern);

	vector<int> ret;
	int matched = 0;

	for (int begin = 0; begin < n; begin++)
	{
		while (matched > 0 && str[begin] != pattern[matched])
			matched = matchCnt[matched - 1];

		if (str[begin] == pattern[matched])
		{
			if (matched == m - 1)
			{
				ret.push_back(begin - m + 1);
				matched = matchCnt[matched];
			}
			else
				matched++;
		}
	}

	return ret;
}

int main(void)
{
	string T, P;
	getline(cin, T);
	getline(cin, P);

	vector<int> ans = kmp(T, P);
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++)
		printf("%d\n", ans[i] + 1);

	return 0;
}
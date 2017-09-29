#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <string>
#include <set>
#include <stdio.h>
#define MAX 1000001
using namespace std;

vector<int> getPartialMatch(const string& N)
{
	int m = N.size();
	vector<int> pi(m, 0);

	int begin = 1, matched = 0;

	while (begin + matched < m)
	{
		if (N[begin + matched] == N[matched])
		{
			++matched;
			pi[begin + matched - 1] = matched;
		}
		else
		{
			if (matched == 0)
				++begin;
			else
			{
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
	
	return pi;
}

int maxOverlap(const string& a, const string& b)
{
	int n = a.size(), m = b.size();
	vector<int> pi = getPartialMatch(b);

	int begin = 0, matched = 0;

	while (begin < n)
	{
		if (matched < m && a[begin + matched] == b[matched])
		{
			++matched;
			if (begin + matched == n)
				return 2*n - matched;
		}
		else
		{
			if (matched == 0)
				++begin;
			else
			{
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}

	return 0;
}

int main() 
{
	string b;

	cin >> b;

	string a = b;
	
	reverse(b.begin(), b.end());

	getPartialMatch(b);

	cout << maxOverlap(a, b);
	
	return 0;
}
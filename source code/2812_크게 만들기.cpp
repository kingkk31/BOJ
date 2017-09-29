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
#pragma warning(disable:4996)
using namespace std;

int main(void)
{
	int n, k, cnt;
	string str;
	cin >> n >> k >> str;

	vector<char> st;
	st.push_back(str[0]);
	cnt = k;

	for (int i = 1; i < str.length(); i++)
	{
		while (cnt != 0 && !st.empty() && st.back() < str[i])
		{
			st.pop_back();
			cnt--;
		}

		st.push_back(str[i]);
	}

	for (int i = 0; i < n - k; i++)
		cout << st[i];
	cout << endl;

	return 0;
}
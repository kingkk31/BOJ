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

#define pp pair<char, int>
#define pa pair<int, int>
#define mk make_pair
int total;
string str;
stack<pp> st;
vector<pa> vt;

bool pairSort(const pair<int, int> &left, const pair<int, int> &right)
{
	return left.second > right.second;
}

int solve(vector<pa> part)
{
	if (part.empty())
		return 1;

	vector<int> plus;
	vector<pa> temp;
	int pos = -1, sum = 0;
	
	for (int i = 0; i < part.size(); i++)
	{
		if (pos == -1)
			pos = i;
		else
		{
			if (part[pos].first < part[i].first && part[pos].second > part[i].second)
				temp.push_back(part[i]);
			else
			{
				int a = str[part[pos].first] == '(' ? 2 : 3;
				int b = solve(temp);
				plus.push_back(a*b);

				pos = i;
				temp.clear();
			}
		}
	}

	int a = str[part[pos].first] == '(' ? 2 : 3;
	int b = solve(temp);
	plus.push_back(a*b);

	for (int i = 0; i < plus.size(); i++)
		sum += plus[i];
	
	return sum;
}

int main(void)
{
	total = 0;
	cin >> str;

	vector<pa> vt;

	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '(' || str[i] == '[')
			st.push(mk(str[i], i));
		else
			if (st.empty())//left < right
			{
				cout << 0 << endl;
				return 0;
			}
			else
				if ((str[i] == ')' && st.top().first == '(') || (str[i] == ']' && st.top().first == '['))
				{
					vt.push_back(mk(st.top().second, i));
					st.pop();
				}
	}//괄호 멀쩡한지 검사

	if (!st.empty())//left > right
	{
		cout << 0 << endl;
		return 0;
	}

	sort(vt.begin(), vt.end(), pairSort);
	cout << solve(vt) << endl;

	return 0;
}
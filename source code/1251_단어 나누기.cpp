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

string rever(string str, int spot1, int spot2)
{
	string first(str.begin(), str.begin() + spot1 + 1);
	string second(str.begin() + spot1 + 1, str.begin() + spot2 + 1);
	string third(str.begin() + spot2 + 1, str.begin() + str.length());
	
	reverse(first.begin(), first.end());
	reverse(second.begin(), second.end());
	reverse(third.begin(), third.end());

	string result = first + second + third;
	return result;
}

void solve(string str)
{
	set<string> st;

	for (int i = 0; i < str.length() - 2; i++)
		for (int j = i + 1; j < str.length() - 1; j++)
			st.insert(rever(str, i, j));

	cout << *st.begin() << endl;
}

int main(void)
{
	string str;
	cin >> str;

	solve(str);
	
	return 0;
}
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <vector>
#include <stack>
#include <set>
#include <list>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <malloc.h>
#include <functional>
#pragma warning(disable:4996)
using namespace std;

int cut(const string& str)
{
	int ret = 0;
	stack<char> st;

	for (int i = 0; i < str.size(); i++)
	{
		switch (str[i])
		{
		case '(':
			st.push(str[i]);
			break;
		
		case ')':
			st.pop();
			if (str[i - 1] == '(')
				ret += st.size();
			else
				ret++;
			break;
		}
	}

	return ret;
}

int main(void)
{
	string str;
	cin >> str;

	cout << cut(str) << endl;

	return 0;
}
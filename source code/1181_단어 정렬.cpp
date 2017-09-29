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

struct comp {
	bool operator()(string str1, string str2)
	{
		if (str1.size() == str2.size())
			return str1 < str2;
		else
			return str1.size() < str2.size();
	}
};

int main(void)
{
	int n;
	cin >> n;

	set<string, comp> st;
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		st.insert(str);
	}
	
	set<string>::iterator itr = st.begin();
	while (itr != st.end())
		cout << *(itr++) << endl;

	return 0;
}
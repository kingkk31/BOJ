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

void solve(string str)
{
	for (int i = 0; i < str.length() / 2; i++)
	{
		if (str[i] != str[str.length() - 1 - i])
		{
			cout << "No" << endl;
			return;
		}
	}
	cout << "Yes" << endl;
}

int main(void)
{
	int n;
	cin >> n;
	char c = getchar();

	while (n--)
	{
		string str;
		getline(cin, str);
		transform(str.begin(), str.end(), str.begin(), (int(*)(int))tolower); 
		solve(str);
	}
	
	return 0;
}
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

int main(void)
{
	int n;
	cin >> n;
	
	vector<string> vt;

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		vt.push_back(str);
	}

	int mind;
	cin >> mind;

	if (mind == 1)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				printf("%c", vt[i][j]);
			printf("\n");
		}
	}
	else if (mind == 2)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = n-1; j >= 0; j--)
				printf("%c", vt[i][j]);
			printf("\n");
		}
	}
	else if (mind == 3)
	{
		for (int i = n-1; i >= 0; i--)
		{
			for (int j = 0; j < n; j++)
				printf("%c", vt[i][j]);
			printf("\n");
		}
	}

	return 0;
}
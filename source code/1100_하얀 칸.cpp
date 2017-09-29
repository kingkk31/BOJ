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

int main(void)
{
	vector<string> vt;
	
	for (int i = 0; i < 8; i++)
	{
		string str;
		cin >> str;
	
		vt.push_back(str);
	}

	int cnt = 0;

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (vt[i][j] == 'F')
			{
				if (i % 2 == j % 2)
					cnt++;
			}
		}
	}

	cout << cnt << endl;

	return 0;
}
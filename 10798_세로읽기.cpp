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
	int maxlength = 0;
	vector<string> vt(5);
	for (int i = 0; i < 5; i++)
	{
		cin >> vt[i];
		maxlength = max(maxlength, (int)vt[i].length());
	}
	for (int i = 0; i < maxlength; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (vt[j].length() <= i)
				continue;
			printf("%c", vt[j][i]);
		}
	}
	cout << endl;

	return 0;
}
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

	if (n == 1)
		cout << "*" << endl;
	else
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (j % 2 == 0)
					cout << "*";
				else
					cout << " ";
			}
			cout << endl;
			for (int j = 0; j < n; j++)
			{
				if (j % 2 == 0)
					cout << " ";
				else
					cout << "*";
			}
			cout << endl;
		}
	}

	return 0;
}


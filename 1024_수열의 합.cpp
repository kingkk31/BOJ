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
	int n, l;
	cin >> n >> l;
	
	int i,j,sum = 0;
	bool ch = false;

	for (i = l; i <= 100; i++)//l
	{
		j = (n - ((i*(i - 1)) / 2)) / i;
		sum = i*j + ((i*(i - 1)) / 2);

		if (j < 0)
			continue;

		if (sum == n)
		{
			ch = true;
			break;
		}
	}

	if (ch)
	{
		for (int q = 0; q < i; q++)
			cout << j + q << " ";
		cout << endl;
	}
	else
		cout << -1 << endl;

	return 0;
}

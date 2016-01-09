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

vector<long long> vt;

void divide(long long n) //분할정복
{
	int sqrtn = int(sqrt((double)n));
	int check = -1;

	for (long long i = sqrtn; i > 1; i--)
	{
		if (n%i == 0)
		{
			check = i;
			break;
		}
	}

	if (check == -1)
	{
		vt.push_back(n);
		return;
	}

	divide(check);
	divide(n / check);
}

int main(void)
{
	long long n;
	cin >> n;

	divide(n);

	sort(vt.begin(), vt.end());

	for (int i = 0; i < vt.size(); i++)
		cout << vt[i] << endl;

	return 0;
}

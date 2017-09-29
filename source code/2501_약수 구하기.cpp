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

int main(void)
{
	int n, k;
	cin >> n >> k;

	vector<int> vt;
	for (int i = 1; i <= sqrt(n); i++)
	{
		if (n%i == 0)
		{
			vt.push_back(i);
			if(i*i != n)
				vt.push_back(n / i);
		}
	}

	if (k > vt.size())
		cout << 0 << endl;
	else
	{
		sort(vt.begin(), vt.end());
		cout << vt[k - 1] << endl;
	}

	return 0;
}
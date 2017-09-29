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
	int n;
	cin >> n;

	vector<int> vt(n);
	for (int i = 0; i < n; i++)
		cin >> vt[i];

	int k;
	long long cnt = 0;
	cin >> k;

	for (int i = 0; i < n; i++)
	{
		if (vt[i] == 0)
			continue;
		
		if (vt[i] / k == 0)
			cnt++;
		else
		{
			cnt += (vt[i] / k);
			if (vt[i] % k != 0)
				cnt++;
		}
	}
	cout << (unsigned long long)(k * cnt) << endl;
	
	return 0;
}
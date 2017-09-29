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
	scanf("%d", &n);

	int sum[1001];
	vector<int> vt(n);
	for (int i = 0; i < n; i++)
		cin >> vt[i];

	for (int i = 0; i < n; i++)
	{
		sum[i] = vt[i];
		for (int j = 0; j < i; j++)
			if (vt[i] > vt[j] && sum[j] + vt[i] > sum[i])
				sum[i] = sum[j] + vt[i];
	}

	int result = 0;
	for (int i = 0; i < n; i++)
		result = max(result, sum[i]);
	cout << result << endl;
	
	return 0;
}
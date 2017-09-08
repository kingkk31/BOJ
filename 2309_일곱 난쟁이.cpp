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

int arr[9] = { 0 };

void solve(int sum)
{
	for (int i = 0; i < 8; i++)
		for (int j = i + 1; j < 9; j++)
			if (sum - arr[i] - arr[j] == 100)
			{
				vector<int> vt;
				for (int k = 0; k < 9; k++)
					if (k != i && k != j)
						vt.push_back(arr[k]);
				sort(vt.begin(), vt.end());
				for (int k = 0; k < vt.size(); k++)
					cout << vt[k] << endl;
				return;
			}
}

int main(void)
{
	int sum = 0;
	for (int i = 0; i < 9; i++)
	{
		cin >> arr[i];
		sum += arr[i];
	}

	solve(sum);

	return 0;
}
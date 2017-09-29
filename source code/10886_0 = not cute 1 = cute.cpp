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
	int n, yes = 0, no = 0;
	cin >> n;
	vector<int> vt(n);
	for (int i = 0; i < n; i++)
	{
		cin >> vt[i];
		if (vt[i] == 0)
			no++;
		else
			yes++;
	}

	if (yes > no)
		cout << "Junhee is cute!" << endl;
	else
		cout << "Junhee is not cute!" << endl;

	return 0;
}
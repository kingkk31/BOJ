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
	int n;
	cin >> n;
	vector<int> vt(10000001);

	vt[0] = 0;
	vt[1] = 1;
	vt[2] = 2;
	vt[3] = 3;
	
	if (n >= 4)
	{
		for (int i = 4; i <= n; i++)
			vt[i] = ((vt[i - 1] % 10) + (vt[i - 2] % 10)) % 10;
	}

	cout << vt[n] << endl;

	return 0;
}
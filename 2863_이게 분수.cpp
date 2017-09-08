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
	double a, b, c, d;
	vector<double> vt(4);
	cin >> a >> b >> c >> d;

	vt[0] = (a / c) + (b / d);
	vt[1] = (c / d) + (a / b);
	vt[2] = (d / b) + (c / a);
	vt[3] = (b / a) + (d / c);

	int cnt = 0;
	for (int i = 1; i < 4; i++)
		if (vt[cnt] < vt[i])
			cnt = i;

	cout << cnt << endl;
	
	return 0;
}
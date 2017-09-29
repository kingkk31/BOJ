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
	vector<int> vt(3);
	cin >> vt[0] >> vt[1] >> vt[2];
	sort(vt.begin(), vt.end());

	if (vt[0] == vt[1] && vt[1] == vt[2])
		cout << 10000 + vt[0] * 1000 << endl;
	else if (vt[0] == vt[1] || vt[1] == vt[2])
		cout << 1000 + (vt[0] == vt[1] ? vt[0] : vt[2]) * 100 << endl;
	else
		cout << vt[2] * 100 << endl;

	return 0;
}
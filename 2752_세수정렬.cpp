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
	vector<int> vt(3);
	cin >> vt[0] >> vt[1] >> vt[2];
	sort(vt.begin(), vt.end());
	cout << vt[0] << " " << vt[1] << " " << vt[2] << endl;
	return 0;
}
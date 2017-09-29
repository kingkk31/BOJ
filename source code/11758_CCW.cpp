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

int main(void)
{
	int x1, x2, x3, y1, y2, y3;
	cin >> x1 >> y1;
	cin >> x2 >> y2;
	cin >> x3 >> y3;

	int cy = y2 - y1, cx = x2 - x1;
	int cb = cx*y1 - cy*x1;
	
	if (cx*y3 == cy*x3 + cb)
		cout << 0 << endl;
	else if (cx*y3 > cy*x3 + cb)
		cout << 1 << endl;
	else
		cout << -1 << endl;
	
	return 0;
}
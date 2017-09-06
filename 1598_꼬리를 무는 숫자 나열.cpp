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

int posY(int num)
{
	int ret;
	switch (num % 4)
	{
	case 0: ret = 4; break;
	case 1: ret = 1; break;
	case 2: ret = 2; break;
	case 3: ret = 3; break;
	default:
		break;
	}
	return ret;
}

int main(void)
{
	int a, b;
	pair<int, int> ap, bp;
	scanf("%d %d", &a, &b);
	
	ap.first = posY(a);
	bp.first = posY(b);
	ap.second = ((a - ap.first) + 4) / 4;
	bp.second = ((b - bp.first) + 4) / 4;
	cout << (abs(ap.first - bp.first) + abs(ap.second - bp.second)) << endl;

	return 0;
}

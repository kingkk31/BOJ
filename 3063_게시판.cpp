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
	int t;
	cin >> t;
	while (t--)
	{
		int x1, y1, x2, y2, x3, y3, x4, y4;
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

		if (x2 <= x3 || x4 <= x1 || y2 <= y3 || y4 <= y1)
			cout << (x2 - x1)*(y2 - y1) << endl;
		else
		{
			int x, y;

			//x
			if (x1 < x3 && x2 < x4)
				x = x2 - x3;
			else if (x3 < x1 && x4 < x2)
				x = x4 - x1;
			else if (x3 <= x1 && x2 <= x4)
				x = x2 - x1;
			else if (x1 <= x3 && x4 <= x2)
				x = x4 - x3;
		
			if (y1 < y3 && y2 < y4)
				y = y2 - y3;
			else if (y3 < y1 && y4 < y2)
				y = y4 - y1;
			else if (y3 <= y1 && y2 <= y4)
				y = y2 - y1;
			else if (y1 <= y3 && y4 <= y2)
				y = y4 - y3;
		
			cout << (x2 - x1)*(y2 - y1) - y*x << endl;
		}
	}

	return 0;
}
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
	while (1)
	{
		vector<int> vt(3);
		scanf("%d %d %d", &vt[0], &vt[1], &vt[2]);
		
		if (vt[0] == 0 && vt[1] == 0 && vt[2] == 0)
			return 0;

		sort(vt.begin(), vt.end());
		if (vt[0] + vt[1] <= vt[2])
			cout << "Invalid" << endl;
		else
		{
			if (vt[0] == vt[1] && vt[1] == vt[2])
				cout << "Equilateral" << endl;
			else if ((vt[0] == vt[1] && vt[1] != vt[2]) || (vt[0] == vt[2] && vt[2] != vt[1]) || (vt[1] == vt[2] && vt[0] != vt[2]))
				cout << "Isosceles" << endl;
			else
				cout << "Scalene" << endl;
		}
	}

	return 0;
}
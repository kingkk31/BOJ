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
	int t;
	cin >> t;

	while (t--)
	{
		int n, total = 0, maxi = 0, cnt = 0;
		cin >> n;
		vector<int> vt(n);

		for (int i = 0; i < n; i++)
		{
			cin >> vt[i];
			total += vt[i];

			if (vt[i] > vt[maxi])
			{
				maxi = i;
				cnt = 1;
			}
			else if (vt[i] == vt[maxi])
				cnt++;
		}

		if (cnt >= 2)
			cout << "no winner" << endl;
		else
			printf("%s winner %d\n", vt[maxi] > total / 2 ? "majority" : "minority", maxi + 1);
	}

	return 0;
}
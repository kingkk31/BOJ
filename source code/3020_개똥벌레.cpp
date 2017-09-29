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
	
	int n, h;
	cin >> n >> h;
	vector<int> vt1(n/2), vt2(n/2);
	
	for (int i = 0; i < n; i+=2)
		scanf("%d %d", &vt1[i/2], &vt2[i / 2]);
	
	sort(vt1.begin(), vt1.end());
	sort(vt2.begin(), vt2.end());
	
	int mini = 987654321, cnt = 0;
	for (int i = 1; i <= h; i++)
	{
		int temp = vt1.size() - (lower_bound(vt1.begin(), vt1.end(), i) - vt1.begin());
		temp += vt2.end() - upper_bound(vt2.begin(), vt2.end(), h - i);
		if (mini > temp)
		{
			mini = temp;
			cnt = 0;
		}
		if (mini == temp)
			cnt++;
	}

	cout << mini << " " << cnt <<endl;

	return 0;
}


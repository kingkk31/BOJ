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
#include <sstream>
#pragma warning(disable:4996)
using namespace std;

int main(void)
{
	int n, c;
	scanf("%d %d", &n, &c);
	
	vector<int> vt(n);
	for (int i = 0; i < n; i++) 
		scanf("%d", &vt[i]);
	sort(vt.begin(), vt.end());

	int start = 1, end = vt[n - 1] - vt[0] + 1, ans;
	
	while (start <= end)
	{
		int mid = (start + end) / 2; //공유기를 가장 인접하게 놓는 최대거리

		int cnt = 1, last = vt[0];
		for (int i = 1; i < n && cnt <= c; i++) 
		{
			if (vt[i] - last >= mid) //공유기를 놓을 수 있다면(최대거리이상)
			{
				cnt++;
				last = vt[i];
			}
		}

		if (cnt >= c) 
		{
			ans = mid;
			start = mid + 1;
		}
		else 
			end = mid - 1;
	}

	cout << ans << endl;

	return 0;
}
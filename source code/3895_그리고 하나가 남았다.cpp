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
#include <iterator>
#include <sstream>
#pragma warning(disable:4996)
using namespace std;

#define INF 987654321

int main(void)
{
	int n, k, m, pos, cnt;
	vector<int> vt;

	while (true) 
	{
		scanf("%d %d %d", &n, &k, &m);
		if (n == 0 && k == 0 && m == 0)	break;

		vt.clear();
		for (int i = 1; i <= n; i++)
			vt.push_back(i);
		
		pos = m - 1;
		
		while (vt.size() > 1)
		{
			vector<int>::iterator itr = vt.begin() + pos;
			vt.erase(itr);
			pos = (pos + k - 1)% vt.size();
		}
		
		cout << vt[0] << endl;
	}

	return 0;
}
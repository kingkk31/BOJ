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
	vector<int> vt;
	int n, m, cnt = 0;
	cin >> n >> m;

	for (int j = 0; j<n; j++)
		vt.push_back(j + 1);

	cout << "<";

	for (int i = 0; i<n; i++)
	{
		cnt += (m - 1);
		if (cnt >= vt.size())
			cnt = cnt%vt.size();

		cout << *(vt.begin() + cnt);
		vt.erase((vt.begin() + cnt));
		
		if (i < n - 1)
			cout << ", ";
	}

	cout << ">";

	return 0;
}
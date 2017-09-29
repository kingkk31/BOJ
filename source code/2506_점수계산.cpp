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
	int n, m, pre = 0, score = 0;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> m;
		if (m == 1)
			score += (++pre);
		else
			pre = 0;
	}
	cout << score << endl;

	return 0;
}
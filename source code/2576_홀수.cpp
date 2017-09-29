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
	int total = 0;
	vector<int> vt;
	
	for (int i = 0; i < 7; i++)
	{
		int num;
		cin >> num;
		
		if (num % 2 != 0)
		{
			total += num;
			vt.push_back(num);
		}
	}

	if (!vt.empty())
	{
		sort(vt.begin(), vt.end());
		cout << total << endl;
		cout << vt.front() << endl;
	}
	else
		cout << -1 << endl;

	return 0;
}